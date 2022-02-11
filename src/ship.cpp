#include "ship.h"

#define PI 3.14159265f
#define FULL_CIRCLE 6.2831853 // 2 * PI
#define HALF_CIRCLE PI
#define CCW90 1.57079632f // .5 * PI
#define radToDegrees(rad) ( rad ) * 180.f / (PI)
#define degreesToRad(deg) ( deg ) * (PI) / 180.f

sf::Texture Ship::texture;

Ship::Ship() {
    this->radius = SHIP_CONSTS::SHIP_RADIUS_PX;
    this->health = SHIP_CONSTS::INITIAL_HEALTH;
    this->angle = SHIP_CONSTS::INITIAL_ANGLE_RAD;
    this->velocity = SHIP_CONSTS::INITIAL_VELOCITY_PS_PER_S;
    this->pos = SHIP_CONSTS::INITIAL_POSITION;

    this->shipSprite = sf::CircleShape(this->radius);
    this->shipSprite.setFillColor(sf::Color::White);
    this->shipSprite.setOrigin({this->radius, this->radius});
    this->shipSprite.setPosition(SHIP_CONSTS::INITIAL_POSITION);
    this->shipSprite.setTexture(&Ship::texture);
    this->shipSprite.setTextureRect(SHIP_CONSTS::TEXTURE_RECT);
}

bool Ship::collides(const sf::Vector2f& pixelPos) const
{
    auto [x, y] = this->shipSprite.getPosition();
    float dx = pixelPos.x - x, dy = pixelPos.y - y;
    return this->radius < std::sqrt(dx * dx + dy * dy);
}

void Ship::rotateShip(float rad)
{
    shipSprite.setRotation(( radToDegrees( rad + CCW90 ) ));
}

void Ship::move(float dt)
{
    float dp = this->velocity * dt;
    float dx = dp * std::cos( this->angle ), dy = dp * std::sin( this->angle );
    float newx = this->pos.x + dx, newy = this->pos.y + dy;
    // if ( newy > lower_bound || newy < upper_bound ) ( - this->angle - this->angle) to negate this->angle (negating mirrors angle over x-axis)
    // add FULL_CIRCLE to maintain 0 <= this->angle < 360
    this->angle += ( newy > SHIP_CONSTS::LOWER_BOUND || newy < SHIP_CONSTS::UPPER_BOUND ) * ( (FULL_CIRCLE) - this->angle - this->angle );
    // if ( newx > right_bound || newx < left_bound ) same as above but rotating by half a circle gives us angle mirrored over y-axis
    // and add FULL_CIRCLE to maintain 0 <= this->angle < 360
    this->angle += ( newx > SHIP_CONSTS::RIGHT_BOUND || newx < SHIP_CONSTS::LEFT_BOUND ) * ( ( HALF_CIRCLE ) + ( this->angle > HALF_CIRCLE ) * ( FULL_CIRCLE ) - this->angle - this->angle );
    // moving left : max( x + dx (returned if x + dx > left_bound), 2 * left_bound - (x + dx) (returned if x + dx < left_bound) )
    // moving right : min( x + dx (returned if x + dx < right_bound), right_bound - (x + dx - right_bound) = 2*right_bound - x - dx (returned if x + dx > right_bound) )
    // moving up : max( y + dy (returned if y + dy > upper_bound), 2 * upper_bound - (x + dx) (returned if y + dy < upper_bound) )
    // moving down : min( y + dy (returned if y + dy < lower_bound), lower_bound - (y + dy - lower_bound) = 2*lower_bound - y - dy (returned if y + dy > lower_bound) )
    this->pos.x = std::min(std::max( newx , 2 * ( SHIP_CONSTS::LEFT_BOUND ) - newx ) , 2 * ( SHIP_CONSTS::RIGHT_BOUND ) - newx ); // x < 0 : 2 * (left_bound) - newx, 0 < x < 720 : newx, x > 720 : 2 * (right_bound) - newx
    this->pos.y = std::min(std::max( newy , 2 * ( SHIP_CONSTS::UPPER_BOUND ) - newy ) , 2 * ( SHIP_CONSTS::LOWER_BOUND ) - newy ); // y < 0 : 2 * (upper_bound) - newy, 0 < y < 720 : newy, y > 720 : 2 * (lower_bound) - newy
    this->shipSprite.setPosition( this->pos );
}

void Ship::setVelocityVector(float vel, float angle)
{
    this->velocity = vel;
    this->angle = angle;
}

float Ship::getAngle() const 
{
    return this->shipSprite.getRotation();
}

sf::Vector2f Ship::getPosition() const 
{
    return this->shipSprite.getPosition();
}

void Ship::draw(sf::RenderWindow& window)
{
    window.draw(shipSprite);
}

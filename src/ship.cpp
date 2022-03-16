#include "ship.h"

#define FULL_CIRCLE ( 2 * M_PI )
#define HALF_CIRCLE ( M_PI )
#define CCW90 ( M_PI_2 )
#define RADTODEGREES(rad) ( ( rad ) * 180.f / ( M_PI ) )
#define DEGREESTORAD(deg) ( ( deg ) * ( M_PI ) / 180.f )

sf::Texture Ship::texture;

Ship::Ship() {
    this->radius = SHIP_CONSTS::SHIP_RADIUS_PX;
    this->health = SHIP_CONSTS::INITIAL_HEALTH;
    this->angleInRad = SHIP_CONSTS::INITIAL_ANGLE_RAD;
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
    float dist = std::sqrt(dx * dx + dy * dy);
    return this->radius > dist;
}

void Ship::rotateShip(float rad)
{
    shipSprite.setRotation(( RADTODEGREES( rad + CCW90 ) ));
}

void Ship::move(float dt)
{
    float dp = this->velocity * dt;
    float dx = dp * std::cos( this->angleInRad ), dy = dp * std::sin( this->angleInRad );
    float newx = this->pos.x + dx, newy = this->pos.y + dy;
    // if ( newy > lower_bound || newy < upper_bound ) ( - this->angleInRad - this->angle) to negate this->angleInRad (negating mirrors angle over x-axis)
    // add FULL_CIRCLE to maintain 0 <= this->angleInRad < 360
    this->angleInRad += ( newy > SHIP_CONSTS::LOWER_BOUND || newy < SHIP_CONSTS::UPPER_BOUND ) * ( (FULL_CIRCLE) - this->angleInRad - this->angleInRad );
    // if ( newx > right_bound || newx < left_bound ) same as above but rotating by half a circle gives us angle mirrored over y-axis
    // and add FULL_CIRCLE to maintain 0 <= this->angleInRad < 360
    this->angleInRad += ( newx > SHIP_CONSTS::RIGHT_BOUND || newx < SHIP_CONSTS::LEFT_BOUND ) * ( ( HALF_CIRCLE ) + ( this->angleInRad > HALF_CIRCLE ) * ( FULL_CIRCLE ) - this->angleInRad - this->angleInRad );
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
    this->angleInRad = angle;
}

float Ship::getAngleInRadians() const 
{
    return ( DEGREESTORAD( this->shipSprite.getRotation() ) );
}

const sf::Vector2f Ship::getPosition() const 
{
    return this->pos;
}

void Ship::reset()
{
    this->radius = SHIP_CONSTS::SHIP_RADIUS_PX;
    this->health = SHIP_CONSTS::INITIAL_HEALTH;
    this->angleInRad = SHIP_CONSTS::INITIAL_ANGLE_RAD;
    this->velocity = SHIP_CONSTS::INITIAL_VELOCITY_PS_PER_S;
    this->pos = SHIP_CONSTS::INITIAL_POSITION;
    this->shipSprite.setPosition(SHIP_CONSTS::INITIAL_POSITION);
}

void Ship::draw(sf::RenderWindow& window)
{
    window.draw(shipSprite);
}

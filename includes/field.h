// #include "common_external_includes.h"
// #include "constants.h"
#include "ship.h"

typedef std::mt19937 rng_t;

class Field
{
    private:
        int currY; 
        std::deque<int> obstacles; // int used as placeholder
        sf::RenderWindow& window;
        rng_t generator;
        std::uniform_int_distribution<int> udist;
        int distanceToFurthestObstacle;

    public:

        Field(sf::RenderWindow& w);

        int generateObstacle();

        void fillObstacles();

        void draw();

};

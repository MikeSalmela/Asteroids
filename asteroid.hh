#ifndef ASTEROID_HH
#define ASTEROID_HH

#include "sprite.hh"

namespace Ui{
    /**
     * @brief Asteroid is a Sprite that represents an asteroid
     */
class Asteroid : public Sprite 
{
public:
    Asteroid(int wW, int wH,
            SDL_Renderer* renderer,
            SDL_Rect avoidRect);

    /**
     * @brief Construct a new Asteroid that is
     *      the parent asteroid splitted
     */
    Asteroid(Asteroid* parent);

    void move();
    /**
     * @brief return true if this will be splitted to new asteroids
     */
    bool spawnsNew();
    /**
     * @brief getter for Phase
     */
    int getPhase();

private:
    /**
     * @brief returns correct Asteroid width for current phase
     */
    int phaseWidth();
    /**
     * @brief Sets the asteroid to a random position
     *      that does not collide with avoid
     */
    bool setPosition(SDL_Rect avoid);

    int phase_ = 2;
    /**
     * @brief sets random speed and spin
     */
    void randomize();

    float rotationSpeed_;

};
}


#endif
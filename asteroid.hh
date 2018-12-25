#ifndef ASTEROID_HH
#define ASTEROID_HH

#include "sprite.hh"

namespace Ui{
class Asteroid : public Sprite 
{
public:
    Asteroid(int wW, int wH,
            SDL_Renderer* renderer,
            SDL_Rect avoidRect);

    Asteroid(Asteroid* parent);

    void move();

    bool spawnsNew();

    int getPhase();

private:

    int phaseWidth();
    
    bool setPosition(SDL_Rect avoid);

    int phase_ = 2;

    void randomize();

    float rotationSpeed_;

};
}


#endif
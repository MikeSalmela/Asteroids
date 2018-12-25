#include "asteroid.hh"
#include <cstdlib>
#include <ctime>

Ui::Asteroid::Asteroid( int wW, int wH,
                        SDL_Renderer* renderer,
                        SDL_Rect avoidRect)
{
    
    wW_ = wW;
    wH_ = wH;

    w_ = 75;
    h_ = 75;

    while(!setPosition(avoidRect));

    randomize();
    renderer_ = renderer;
    loadTexture("Res/asteroid.bmp");
}

Ui::Asteroid::Asteroid(Asteroid* parent)
{
    x_ = parent->getX();
    y_ = parent->getY();

    phase_ = parent->getPhase() - 1;

    w_ = phaseWidth();
    h_ = phaseWidth();

    wW_ = parent->getWindowW();
    wH_ = parent->getWindowH();

    hitbox_ = makeRect(x_, y_, w_, h_);
    imageBox_ = makeRect(x_, y_, w_, h_);

    randomize();

    renderer_ = parent->getRenderer();

    loadTexture("Res/asteroid.bmp");
}


int Ui::Asteroid::getPhase() 
{
    return phase_;
}

int Ui::Asteroid::phaseWidth()
{
    if(phase_ == 1)
    {
        return 50;
    }
    if(phase_ == 0)
    {
        return 25;
    }
}



bool Ui::Asteroid::setPosition(SDL_Rect avoid)
{
    x_ = rand()%wW_;
    y_ = rand()%wH_;

    hitbox_ = makeRect(x_, y_, w_, h_);
    imageBox_ = makeRect(x_, y_, w_, h_);

    return !rectCollide(hitbox_, avoid);
}

bool Ui::Asteroid::spawnsNew()
{
    return phase_;
}

void Ui::Asteroid::move()
{
    angle_ += rotationSpeed_;
    Sprite::move();
}

void Ui::Asteroid::randomize()
{
    xs_ = 4 - static_cast<float>(rand()%8);
    ys_ = 4 - static_cast<float>(rand()%8);

    rotationSpeed_ = (15-rand()%30)/(float) 3;
}
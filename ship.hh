#ifndef SHIP_HH
#define SHIP_HH

#include <vector>
#include <list>
#include <memory>

#include "sprite.hh"
#include "bullet.hh"
#include "inputcontrol.hh"


namespace Ui
{
class Ship : public Sprite
{
public:

    Ship(   int w, int h, 
            int windowW, int windowH, 
            SDL_Renderer* renderer,
            Engine::InputContorl* control);

    void move();
    void draw();

    void hit();

    std::list<std::unique_ptr<Ui::Bullet>>& getBullets();

    SDL_Rect safetybox();

private:

    void shoot();
    
    void accelerate();
    void removeDead();
    void updateBullets();

    int shootLimiter_ = 0;

    Engine::InputContorl* control_;
    
    std::list<std::unique_ptr<Ui::Bullet>> bullets_;
    
    float acceleration_ = 0.5;
    float maxSpeed_ = 10;


};
}

#endif
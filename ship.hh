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
    /**
     * @brief the Ship is a sprite that represents a space ship
     */
class Ship : public Sprite
{
public:

    Ship(   int w, int h, 
            int windowW, int windowH, 
            SDL_Renderer* renderer,
            Engine::InputContorl* control);

    void move();
    /**
     * @brief Ship also draws bullets it has shot
     */
    void draw();

    void hit();
    /**
     * @brief Get a reference to the vector of shot bullets
     */
    std::list<std::unique_ptr<Ui::Bullet>>& getBullets();
    /**
     * @brief the area that Asteroids can't spawn in
     */
    SDL_Rect safetybox();

private:

    /**
     * @brief shoots a bullet
     */
    void shoot();
    /**
     * @brief increase velocity towards the angle of the ship
     */
    void accelerate();
    /**
     * @brief destroys dead bullets
     */
    void removeDead();
    /**
     * @brief moves bullets forwards, removes dead ones 
     */
    void updateBullets();
    
    int shootLimiter_ = 0;

    Engine::InputContorl* control_;
    
    std::list<std::unique_ptr<Ui::Bullet>> bullets_;
    
    float acceleration_ = 0.5;
    float maxSpeed_ = 10;


};
}

#endif
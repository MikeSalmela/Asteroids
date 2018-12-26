#ifndef BULLET_HH
#define BULLET_HH

#include "sprite.hh"
namespace Ui
{
    /**
     * @brief Sprite that represents a shot bullet
     * 
     */
class Bullet : public Sprite
{
public:
    Bullet(int x, int y, double angle,
            SDL_Renderer* renderer_,
            int windowW, int windowH);
    /**
     * @brief decrements the range of the bullet
     */
    void move();
    bool isAlive() const;

    bool collides(Sprite* sprite) const;
    void hit();

private:
    int range_ = 50;
    bool alive_ = true;

};
}

#endif
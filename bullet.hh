#ifndef BULLET_HH
#define BULLET_HH

#include "sprite.hh"
namespace Ui
{
class Bullet : public Sprite
{
public:
    Bullet(int x, int y, double angle,
            SDL_Renderer* renderer_,
            int windowW, int windowH);

    void move();
    bool isAlive();

    bool collides(Sprite* sprite);
    void hit();

private:
    int range_ = 50;
    bool alive_ = true;

};
}

#endif
#include "bullet.hh"
#include <cmath>

const float speed = 15;
const double Pi = 3.14159265;

Ui::Bullet::Bullet(int x, int y, double angle,
                    SDL_Renderer* renderer,
                    int windowW, int windowH)
{
    x_ = x;
    y_ = y;

    w_ = 10;
    h_ = 10;

    wW_ = windowW;
    wH_ = windowH;

    angle_ = angle;

    renderer_ = renderer;
    hitbox_ = makeRect(x_, y_, w_ , h_);
    imageBox_ = makeRect(x_, y_, w_, h_);
    loadTexture("Res/bullet.bmp");

    xs_ = cos(angle_*Pi/180)*speed;
    ys_ = sin(angle_*Pi/180)*speed;

}

void Ui::Bullet::hit()
{
    alive_ = false;
}

bool Ui::Bullet::collides(Sprite* sprite) const
{
    // A dead bullet cannot hit anything
    if(!alive_)
    {
        return false;
    }
    return Sprite::collides(sprite);
}

bool Ui::Bullet::isAlive() const
{
    return alive_;
}

void Ui::Bullet::move()
{
    range_--;
    if(range_ < 0)
    {
        alive_ = false;
    }

    Ui::Sprite::move();
}
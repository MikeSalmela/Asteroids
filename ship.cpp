#include "ship.hh"
#include <iostream>
#include <cmath>

const char* texture = "Res/ship.bmp";
const double Pi = 3.14159265;

Ui::Ship::Ship( int w, int h, 
                int windowW, int windowH, 
                SDL_Renderer* renderer,
                Engine::InputContorl* control)
{
    x_ = windowW/2;
    y_ = windowH/2;
    w_ = w;
    h_ = h;

    wW_ = windowW;
    wH_ = windowH;
    renderer_ = renderer;
    control_ = control;

    hitbox_ = makeRect(x_, y_, w_, h_);
    imageBox_ = makeRect(x_, y_, w_, h_);
    loadTexture(texture);
}

SDL_Rect Ui::Ship::safetybox()
{
    SDL_Rect rect;
    rect.x = x_ - 50;
    rect.y = y_ - 50;
    rect.w = w_ + 100;
    rect.h = h_ + 100;

    return rect;
}

void Ui::Ship::accelerate()
{
    xs_ += cos(angle_*Pi/180)*acceleration_;
    ys_ += sin(angle_*Pi/180)*acceleration_;

    if(xs_ > maxSpeed_) 
    {
        xs_ = maxSpeed_;
    }
    if(xs_ < -maxSpeed_)
    {
        xs_ = -maxSpeed_;
    }
    if(ys_ > maxSpeed_)
    {
        ys_ = maxSpeed_;
    }
    if(ys_ < -maxSpeed_)
    {
        ys_ = -maxSpeed_;
    }

}

void Ui::Ship::draw()
{
    for(auto& bullet : bullets_)
    {
        bullet->draw();
    }
    Ui::Sprite::draw();
}

void Ui::Ship::updateBullets()
{

    for(auto& bullet : bullets_)
    {
        bullet->move();        
    }

    removeDead();
}

void Ui::Ship::hit()
{
    alive_ = false;
}

void Ui::Ship::removeDead()
{
    if(bullets_.size() > 0)
    {
        auto bulletIt = bullets_.begin();
        while(bulletIt != bullets_.end())
        {
            auto current = bulletIt;
            ++bulletIt;
            if(!(*current)->isAlive())
            {
                bullets_.erase(current);
            }
        }
    }
}


std::list<std::unique_ptr<Ui::Bullet>>& Ui::Ship::getBullets()
{
    return bullets_;
}

void Ui::Ship::shoot()
{
    if(shootLimiter_ == 0)
        {
            bullets_.push_back(std::make_unique<Ui::Bullet>
                (midX(), midY(), angle_, renderer_, wW_, wH_));
    
        }
    ++shootLimiter_;

    if(shootLimiter_ == 10)
    {
        shootLimiter_ = 0;
    }
}

void Ui::Ship::move()
{
    if(control_->left())
    {
        angle_ -= 4;
    }
    if(control_->right())
    {
        angle_ += 4;
    }
    if(control_->up())
    {
        accelerate();
    }
    if(control_->space())
    {
        shoot();
    }
    else
    {
        shootLimiter_ = 0;
    }

    updateBullets();
    Ui::Sprite::move();
}
#include "sprite.hh"
#include <iostream>

Ui::Sprite::Sprite(int x, int y, int w, int h, 
            int windowW, int windowH, 
            SDL_Renderer* renderer,
            const std::string& texture) :
                x_(x), y_(y), w_(w), h_(h),
                wW_(windowW), wH_(windowH), 
                renderer_(renderer)
{
    hitbox_ = makeRect(x_, y_, w_, h_);
    imageBox_ = makeRect(x_, y_, w_, h_);
    xs_ = 2.5;
    ys_ = 2.5;
    loadTexture(texture);
}


void Ui::Sprite::loadTexture(const std::string& texture)
{
    SDL_Surface* surface = SDL_LoadBMP(texture.c_str());
    texture_ = SDL_CreateTextureFromSurface(renderer_ ,surface);

    if(texture_ == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
    }
    SDL_FreeSurface(surface);
}


float Ui::Sprite::getX() {return x_;}
float Ui::Sprite::getY() {return y_;}

int Ui::Sprite::getWindowW() {return wW_;}
int Ui::Sprite::getWindowH() {return wH_;}

void Ui::Sprite::move()
{

    x_ += xs_;
    y_ += ys_;
    updateRects();
    moveToBoundaries();
}

SDL_Rect* Ui::Sprite::getHitbox()
{
    return &hitbox_;
}

bool Ui::Sprite::collides(Sprite* sprite) const
{
    return(rectCollide(hitbox_, *sprite->getHitbox()));
}

void Ui::Sprite::hit()
{
    alive_ = false;
}

void Ui::Sprite::moveToBoundaries()
{
    if(angle_ > 360)
    {
        angle_ -= 360;
    }
    else if(angle_ < -360)
    {
        angle_ += 360;
    }

    if(y_ > wH_)
    {
        y_ = -h_;
    }
    else if(y_ < -1.0001*h_)
    {
        y_ = wH_;
    }
    if(x_ > wW_)
    {
        x_ = -w_;
    }
    else if(x_ < -1.0001*w_)
    {
        x_ = wW_;
    }
}


bool Ui::Sprite::isAlive() const
{
    return alive_;
}

SDL_Renderer* Ui::Sprite::getRenderer()
{
    return renderer_;
}

void Ui::Sprite::updateRects()
{
    hitbox_.x = (int) x_;
    hitbox_.y = (int) y_;

    imageBox_.x = (int) x_;
    imageBox_.y = (int) y_;
}

int Ui::Sprite::midX()
{
    return hitbox_.x + hitbox_.w/2;
}

int Ui::Sprite::midY()
{
    return hitbox_.y + hitbox_.h/2;
}

void Ui::Sprite::draw()
{
    SDL_RenderCopyEx(renderer_, texture_, 0, &imageBox_, 
                    angle_, NULL, SDL_FLIP_NONE);
}

SDL_Rect Ui::Sprite::makeRect(int x, int y, int w, int h)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    return rect;
}

bool Ui::Sprite::rectCollide(const SDL_Rect& a, const SDL_Rect& b) const
{
    int leftA = a.x;
    int rightA = a.x + a.w;
    int topA = a.y;
    int botA = a.y + a.h;

    int leftB = b.x;
    int rightB = b.x + b.w;
    int topB = b.y;
    int botB = b.y + b.h;

    if(rightA <= leftB)
    {
        return false;
    }
    if(leftA >= rightB)
    {
        return false;
    }
    if(topA >= botB)
    {
        return false;
    }
    if(botA <= topB)
    {
        return false;
    }
    return true;
}
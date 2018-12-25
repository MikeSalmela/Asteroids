#ifndef SPRITE_HH
#define SPRITE_HH

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <string>

namespace Ui{
    /**
     * @brief a base class for anything that moves
     */
class Sprite{

public:

    Sprite() = default;
    Sprite(int x, int y, int w, int h, 
            int windowW, int windowH, 
            SDL_Renderer* renderer,
            const std::string& texture);

    ~Sprite(){
        SDL_DestroyTexture(texture_);
    }

    virtual bool collides(Sprite* sprite) const;

    bool isAlive() const;
    virtual void move();
    virtual void draw();

    virtual void hit();

    float getX();
    float getY();

    int getWindowW();
    int getWindowH();

    int getPhase();

    SDL_Renderer* getRenderer();

protected:

    SDL_Rect hitbox_;
    SDL_Rect imageBox_;
    SDL_Texture* texture_;
    SDL_Renderer* renderer_;

    SDL_Rect* getHitbox();

    void loadTexture(const std::string& texture);

    bool rectCollide(const SDL_Rect& a, const SDL_Rect& b) const;

    int midX();
    int midY();

    void moveToBoundaries();
    void updateRects();

    SDL_Rect makeRect(int x, int y, int w, int h);

    // Sprite position
    float x_;
    float y_;
    double angle_ = 0;
    
    // Sprite speed
    float xs_ = 0;
    float ys_ = 0;

    int w_;
    int h_;

    // window
    int wW_;
    int wH_;

    bool alive_ = true;

};
}

#endif
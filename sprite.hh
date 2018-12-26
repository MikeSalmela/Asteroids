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

    /**
     * @brief Construct a new Sprite object
     */
    Sprite() = default;

    Sprite(int x, int y, int w, int h, 
            int windowW, int windowH, 
            SDL_Renderer* renderer,
            const std::string& texture);

    /**
     * @brief Destroy the Sprite object 
     */
    ~Sprite(){
        SDL_DestroyTexture(texture_);
    }

    /**
     * @brief checks for collision between this and
     *  the param Sprites
     * @param sprite 
     */
    virtual bool collides(Sprite* sprite) const;

    bool isAlive() const;
    /**
     * @brief moves Sprite according to it's speed
     */
    virtual void move();
    /**
     * @brief draws sprite with renderer_
     */
    virtual void draw();
    /**
     * @brief sets alive_ false
     */
    virtual void hit();

    /**
     * @brief getters for coordinates 
     */
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

    SDL_Rect* getHitbox();

    /**
     * @brief sets a texture for this sprite
     * @param texture path to a bmp file
     */
    void loadTexture(const std::string& texture);
    /**
     * @brief check collision between two rects
     */
    bool rectCollide(const SDL_Rect& a, const SDL_Rect& b) const;
    /**
     * @brief returns coordinates to the center of Sprite 
     */
    int midX();
    int midY();
    /**
     * @brief move Sprite back to the window area
     */
    void moveToBoundaries();
    /**
     * @brief set hitbox_ and imageBox_ to correct positions
     */
    void updateRects();
    /**
     * @brief constructs an SDL_Rect with given parameters
     */
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

    // window properties
    int wW_;
    int wH_;

    // Sprite status
    bool alive_ = true;

    SDL_Renderer* renderer_;

};
}

#endif
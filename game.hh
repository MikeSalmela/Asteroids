#ifndef GAME_HH
#define GAME_HH

#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include <list>
#include "ship.hh"
#include "asteroid.hh"
#include "sprite.hh"
#include "inputcontrol.hh"

namespace Ui
{
/**
 * @brief the Game class handles game loop and all game objects
 */
class Game
{
public:
    /**
     * @brief Construct a new Game object
     */
    Game(SDL_Window* window,
         SDL_Renderer* renderer,
         int width,
         int height
         );
    /**
     * @brief starts gameloop
     */
    void start();

private:
    /**
     * @brief polls user inputs and updates Sprites
     */
    void gameLoop();
    /**
     * @brief presents renderer, updates window
     */
    void updateUi();
    /**
     * @brief remove Sprites that aren't alive
     */
    void removeDead();
    /**
     * @brief check for collisions between Sprites
     *      if a collision happens, calls Sprite::hit()
     */
    void checkCollisions();
    /**
     * @brief Creates new asteroids if all of them are destroyed
     */
    void makeAsteroids();
    
    /**
     * @brief moves Sprites, checks collisions
     *          draws Sprites
     */
    void moveAndDraw();
    /**
     * @brief Create ship_ and inputControl_
     */
    void createObjects();
    /**
     * @brief create new asteroids on position of splitted 
     */
    void splitAsteroid(Ui::Asteroid* splitted);

    SDL_Renderer* renderer_;
    SDL_Window* window_;
    int width_;
    int height_;

    int points_ = 0;

    int asteroidCount_ = 2;
    bool running_ = true;
    SDL_Event event_;

    std::unique_ptr<Engine::InputContorl> inputControl_;
    std::list<std::unique_ptr<Asteroid>> asteroids_;
    std::unique_ptr<Ship> ship_;

};
}

#endif
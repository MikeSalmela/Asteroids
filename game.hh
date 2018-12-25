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
    Game(SDL_Window* window,
         SDL_Renderer* renderer,
         int width,
         int height
         );

    void start();

private:

    void gameLoop();
    void updateUi();

    void removeDead();

    void checkCollisions();
    void makeAsteroids();

    void moveAndDraw();

    void createObjects();
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
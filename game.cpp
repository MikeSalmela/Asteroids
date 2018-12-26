#include "game.hh"
#include "inputcontrol.hh"
#include <iostream>
#include <memory>
#include <cstdlib>

Ui::Game::Game( SDL_Window* window,
                SDL_Renderer* renderer,
                int width,
                int height) :
    window_(window), renderer_(renderer), 
    width_(width), height_(height)
{

    srand(time(NULL));
    createObjects();    
}

void Ui::Game::createObjects()
{
    inputControl_ = std::make_unique<Engine::InputContorl>();

    ship_ = std::make_unique<Ui::Ship>
        (50, 50, width_, height_, 
        renderer_, inputControl_.get());
}
    

void Ui::Game::start()
{
    
    while(running_)
    {
        gameLoop();
    }
}

void Ui::Game::updateUi()
{
    SDL_RenderPresent(renderer_);   
    SDL_UpdateWindowSurface(window_);
}

void Ui::Game::moveAndDraw()
{
    if(ship_->isAlive())
    {
        ship_->move();
        ship_->draw();
    }
    checkCollisions();
    removeDead();

    for(auto& asteroid : asteroids_)
    {
        asteroid->move();
        asteroid->draw();
    }
}

void Ui::Game::checkCollisions()
{
    // Check for asteroid colliding with the ship
    for(auto& asteroid : asteroids_)
    {
        if(asteroid->collides(ship_.get()))
        {
            if(ship_->isAlive())
            {
                std::cout << points_ << std::endl;
            }
            ship_->hit();
        }
    }
    // Check for bullet colliding with an asteroid
    for(auto& bullet : ship_->getBullets())
    {
        for(auto& asteroid : asteroids_)
        {
            if(bullet->collides(asteroid.get()))
            {
                asteroid->hit();
                bullet->hit();
                ++points_;

                if(asteroid->spawnsNew())
                {
                    splitAsteroid(asteroid.get());
                }
            }
        }
    }
}

void Ui::Game::splitAsteroid(Ui::Asteroid* splitted)
{
    for(int i = 0; i < 2; ++i)
    {
        asteroids_.push_back(std::make_unique<Asteroid>(splitted));
    }
}

void Ui::Game::removeDead()
{
    if(asteroids_.size() > 0)
    {
        auto asteroidIter = asteroids_.begin();
        while(asteroidIter != asteroids_.end())
        {
            auto current = asteroidIter;
            ++asteroidIter;
            if(!(*current)->isAlive())
            {
                asteroids_.erase(current);
            }
        }
    }
}

void Ui::Game::makeAsteroids()
{
    if(asteroids_.size() == 0)
    {       
        while(asteroids_.size() < asteroidCount_)
        {
            asteroids_.push_back(std::make_unique<Ui::Asteroid>
                (width_, height_, renderer_, ship_->safetybox()));
        }
        ++asteroidCount_;
    }
}

void Ui::Game::gameLoop()
{

    SDL_RenderClear(renderer_);
    running_ = inputControl_->update();
    moveAndDraw();
    makeAsteroids();
    updateUi();
    SDL_Delay(25);
}
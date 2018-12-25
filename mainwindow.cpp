#include "mainwindow.hh"
#include "game.hh"
#include <iostream>
#include <memory>

Ui::MainWindow::MainWindow()
{
    if(initSDL("Asteroids"))
    {
        renderer_ = SDL_CreateRenderer(
        window_,
        -1,
        SDL_RENDERER_ACCELERATED
        );
    }
    else
    {
        std::cout << "Window creation failed" << std::endl;
    }
}

Ui::MainWindow::~MainWindow()
{
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
    SDL_Quit();
}

void Ui::MainWindow::start()
{
    auto game = std::make_unique<Ui::Game>
        (window_, renderer_, windowWidth, windowHeight);
    game->start();
}

bool Ui::MainWindow::initSDL(const std::string& name)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    
    window_ = SDL_CreateWindow(
        name.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        windowWidth,
        windowHeight,
        SDL_WINDOW_OPENGL
    );

    return(window_ != NULL);
}

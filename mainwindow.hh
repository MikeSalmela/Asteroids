#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <SDL2/SDL.h>
#include <string>

namespace Ui
{
class MainWindow{
public:

    MainWindow();
    ~MainWindow();

    void start();

private:
    bool initSDL(const std::string& name);

    int windowHeight = 720;
    int windowWidth = 1080;

    SDL_Window* window_;
    SDL_Renderer* renderer_;

};

}

#endif
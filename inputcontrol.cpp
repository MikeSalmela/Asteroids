#include "inputcontrol.hh"
#include <iostream>

Engine::InputContorl::InputContorl()
{

}

bool Engine::InputContorl::update()
{   
    while(SDL_PollEvent(&event_))
    {
        if(event_.type == SDL_QUIT)
        {
            running_ = false;
        }
    }

    readStates();
    return running_;
}


void Engine::InputContorl::readStates()
{
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    left_ = (keystate[SDL_SCANCODE_LEFT]);
    right_ = (keystate[SDL_SCANCODE_RIGHT]);
    up_ = (keystate[SDL_SCANCODE_UP]);
    space_ = (keystate[SDL_SCANCODE_SPACE]);
}

bool Engine::InputContorl::up()
{
    return up_;
}

bool Engine::InputContorl::left()
{
    return left_;
}

bool Engine::InputContorl::right()
{
    return right_;
}

bool Engine::InputContorl::space()
{
    return space_;
}
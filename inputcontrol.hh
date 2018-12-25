#ifndef INPUTCONTROL_HH
#define INPUTCONTROL_HH

#include <SDL2/SDL.h>

namespace Engine
{
class InputContorl
{
public:
    InputContorl();
    
    // Updates keypresses, returns false if user input closes window
    bool update();

    bool left();
    bool right();
    bool up();
    bool space();

private:

    SDL_Event event_;
    bool running_ = true;

    void readStates();

    bool left_;
    bool right_;
    bool up_;
    bool space_;

};
}


#endif
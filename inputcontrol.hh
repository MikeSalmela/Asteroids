#ifndef INPUTCONTROL_HH
#define INPUTCONTROL_HH

#include <SDL2/SDL.h>

namespace Engine
{
    /**
     * @brief Handles user inputs
     */
class InputContorl
{
public:
    InputContorl();
    
    /**
     * @brief update key states to current status
     * @return false, if user has tried to close the window 
     */
    bool update();

    /**
     * @brief returns true if the button is pressed 
     */
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
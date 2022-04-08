#include "headers/input.h"

Input::Input(){
    this->button.left = this->button.right =  this->button.up =  this->button.down =  this->button.escape = false;
}

Input::Button Input::getButton(void){
    return this->button;
}

void Input::inputHandler(Event event, RenderWindow &window){

    if(event.type == Event::Closed){
        window.close();
    }

    if(event.type == Event::KeyPressed){
        switch (event.key.code)
        {
        case Keyboard::Escape:
            this->button.escape = true;
            break;
        
        case Keyboard::Up:
            this->button.up = true;
            break;

        case Keyboard::Down:
            this->button.down = true;
            break;

        case Keyboard::Right:
            this->button.right = true;
            break;

        case Keyboard::Left:
            this->button.left = true;
            break;
        
        default:
            break;
        }
    }

    if(event.type == Event::KeyReleased){
        switch (event.key.code)
        {
        case Keyboard::Escape:
            this->button.escape = false;
            break;
        
        case Keyboard::Up:
            this->button.up = false;
            break;

        case Keyboard::Down:
            this->button.down = false;
            break;

        case Keyboard::Right:
            this->button.right = false;
            break;

        case Keyboard::Left:
            this->button.left = false;
            break;
        
        default:
            break;
        }
    }

}
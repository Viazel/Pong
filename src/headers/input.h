#ifndef INPUT_H
#define INPUT_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Input {
    struct Button { bool left, right, down, up, escape; };

private:
    Button button;

public:
    Input();
    Button getButton(void);
    void inputHandler(Event event, RenderWindow &window);

};

#endif
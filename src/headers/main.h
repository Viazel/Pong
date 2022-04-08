#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "input.h"

const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;

using namespace sf;
using namespace std;

void setText(Text &text, String str);
void checkButton(void);

#endif
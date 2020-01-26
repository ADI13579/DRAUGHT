#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "board.h"

using namespace std;

void setBoard(sf::RenderWindow &window)
{
    window.clear();
    board board;
    board.backgroundCreate();
    board.textFormat();
    board.setBackground(window);
}

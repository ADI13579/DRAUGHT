#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "menuBoard.h"


void setBoard(sf::RenderWindow &window)
{
    window.clear();
    board board;
    board.backgroundCreate();
    board.setBackground(window);
}

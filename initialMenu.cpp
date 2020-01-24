#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "initialMenu.h"

void initialMenu(sf::RenderWindow &window)
{
    initMenu initialize;
    initialize.set(window);
    initialize.menuDisp(window);
    initialize.hover(window);
  
 }
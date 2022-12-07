#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "initialMenu.h"


int main()
{
    

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Draught"/*, sf::Style::Fullscreen*/);
    window.setFramerateLimit(100);
    sf::Event event;

    setBoard(window);
    initialMenu(window);
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
            
        }
    }
    return 0;
}
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "board.h"
#include "initialMenu.h"
using namespace std;


int main()
{
    sf::Music bckMusic;
    bckMusic.openFromFile("musics/background.ogg");
    bckMusic.setVolume(50);
    bckMusic.play();

    sf::RenderWindow window(sf::VideoMode(1000, 480), "Draught", sf::Style::Fullscreen);
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
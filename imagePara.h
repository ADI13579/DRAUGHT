#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include"SFML/Audio.hpp"


class imagePara//contains all the sprites loaded
{
public:
    sf::SoundBuffer Sbuffer;
    sf::Sound jump;
    sf::RectangleShape move;;//the blue box in program that shows move
//this section has the piece variable defines 
    sf::Texture blackKing, black, white, whiteKing;
    sf::Sprite swhiteKing, swhite, sblack, sblackKing;

    //defines the image used
    sf::Texture board_background, board;
    sf::Sprite sbck, sboard;

    sf::Vector2f boardPos;

    sf::Font gfont;
    sf::Text turnMsg,back;
    imagePara(void);
    ~imagePara()
    {
        std::cout << "Destroyed" << std::endl;
    }
};
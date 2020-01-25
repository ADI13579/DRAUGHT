#include <iostream>
#include <SFML/Window.hpp>
#include<Windows.h>
#include <SFML/Graphics.hpp>
#pragma once


class board
{
	private:
		//defining font
		sf::Font gfont;

		//defining game's name
		sf::Text gamename;

		//defining images for background
		sf::Texture background, board;
		
		//defining sprite
		sf::Sprite sp_board, sp_background;
		
		float scale = GetSystemMetrics(SM_CXSCREEN) / 1920.0;
	public:
		void textFormat()
		{
			//loading font file
			gfont.loadFromFile("fonts/gfont.ttf");


			gamename.setFont(gfont);
			gamename.setCharacterSize(scale * 300);
			gamename.move(scale * 100, scale * 100);
			gamename.setOutlineThickness(scale * 40);
			gamename.setString("Draught");

		}

		void backgroundCreate()
		{
			//loading images
			background.loadFromFile("images/background.png");
			board.loadFromFile("images/board.png");

			//defining sprites
			sp_board.setTexture(board);
			sp_background.setTexture(background);
			sp_board.move(scale * 800, scale * 500);

		}

		void setBackground(sf::RenderWindow &window)
		{
			//drawing background
			window.draw(sp_background);
			window.draw(gamename);
			window.draw(sp_board);
		}
};

void setBoard(sf::RenderWindow& window);

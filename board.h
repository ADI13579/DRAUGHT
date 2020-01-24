#include <iostream>
#include <SFML/Window.hpp>
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

	public:
		void textFormat()
		{
			//loading font file
			gfont.loadFromFile("fonts/gfont.ttf");


			gamename.setFont(gfont);
			gamename.setCharacterSize(300);
			gamename.move(100, 100);
			gamename.setOutlineThickness(40);
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
			sp_board.move(800, 500);

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

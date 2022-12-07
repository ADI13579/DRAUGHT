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
		sf::Texture background, mboard;
		
		//defining sprite
		sf::Sprite sp_board, sp_background;
		
		float scale = static_cast<float>(1000 / 1920.0);
	public:
		board()
		{
			//loading font file
			gfont.loadFromFile("fonts/gfont.ttf");


			gamename.setFont(gfont);
			gamename.setCharacterSize(static_cast<float>(scale * 300));
			gamename.move(scale * 100, static_cast<float>(scale * 100));
			gamename.setOutlineThickness(static_cast<float>(scale * 40));
			gamename.setString("Draught");
		}
		~board()
		{

		}
	

		void backgroundCreate()
		{
			//loading images
			background.loadFromFile("images/background.png");
			mboard.loadFromFile("images/board.png");

			//defining sprites
			sp_board.setTexture(mboard);
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

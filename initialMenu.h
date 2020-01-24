#include<SFML/Graphics.hpp>
#include<iostream>
#include "board.h"
#pragma once
class initMenu
{
	private:
		//defining font
		sf::Font gfont;

		//initializing text
		sf::Text singleplayer, multiplayer, rules, exit;


	public:
		void set(sf::RenderWindow  &window)
		{
			//loading font
			gfont.loadFromFile("fonts/gfont.ttf");

			//loading fonts for text and setting size
			singleplayer.setFont(gfont);
			singleplayer.setCharacterSize(60);

            multiplayer.setFont(gfont);
            multiplayer.setCharacterSize(60);


            rules.setFont(gfont);
            rules.setCharacterSize(60);

            exit.setFont(gfont);
            exit.setCharacterSize(60);

            //setting position for each text
            singleplayer.move(50, 490);
            multiplayer.move(50, 600);
            rules.move(50, 710);
            exit.move(50, 820);


            //setting Text to display text

            singleplayer.setString("Single Player");
            multiplayer.setString("Multi Player");
            rules.setString("Rules");
            exit.setString("Exit");
		}
         
        //display menu initially when begins
        void menuDisp(sf::RenderWindow& window)
        {

            //writing texts
            window.draw(singleplayer);
            window.draw(multiplayer);
            window.draw(rules);
            window.draw(exit);
            window.display();
        }

        //hovering when first is selected
        void o1Disp(sf::RenderWindow& window)
        {
            singleplayer.setOutlineThickness(20);
            multiplayer.setOutlineThickness(0);
            rules.setOutlineThickness(0);
            exit.setOutlineThickness(0);
            //writing texts
            window.draw(singleplayer);
            window.draw(multiplayer);
            window.draw(rules);
            window.draw(exit);
            window.display();
        }
        
        //hovering when multiplayer is selected
        void o2Disp(sf::RenderWindow& window)
        {
            singleplayer.setOutlineThickness(0);
            multiplayer.setOutlineThickness(20);
            rules.setOutlineThickness(0);
            exit.setOutlineThickness(0);
            //writing texts
            window.draw(singleplayer);
            window.draw(multiplayer);
            window.draw(rules);
            window.draw(exit);
            window.display();
        }
        
        //hovering when rules is selected
        void o3Disp(sf::RenderWindow& window)
        {
            singleplayer.setOutlineThickness(0);
            multiplayer.setOutlineThickness(0);
            rules.setOutlineThickness(20);
            exit.setOutlineThickness(0);
            //writing texts
            window.draw(singleplayer);
            window.draw(multiplayer);
            window.draw(rules);
            window.draw(exit);
            window.display();
        }
        
        //hovering when exit is selected
        void o4Disp(sf::RenderWindow& window)
        {
            singleplayer.setOutlineThickness(0);
            multiplayer.setOutlineThickness(0);
            rules.setOutlineThickness(0);
            exit.setOutlineThickness(20);
            //writing texts
            window.draw(singleplayer);
            window.draw(multiplayer);
            window.draw(rules);
            window.draw(exit);
            window.display();
        }

        void dispDestruct(sf::RenderWindow& window)
        {
            //destruct thickness created by hovering
            singleplayer.setOutlineThickness(0);
            multiplayer.setOutlineThickness(0);
            rules.setOutlineThickness(0);
            exit.setOutlineThickness(0);
            //writing texts
            window.draw(singleplayer);
            window.draw(multiplayer);
            window.draw(rules);
            window.draw(exit);
            window.display();
        }

        void clickCheck(int a,int b,sf::RenderWindow &window)
        {

            if (a < 570 && b < 545 && b>508)
            {
                std::cout << "singleplayer was selected" << std::endl;
                window.close();
            }
            if (a < 536 && b < 658 && b>614)
            {
                std::cout << "multiplayer was selected" << std::endl;
                window.close();
            }
            if (a < 290 && b < 760 && b>727)
            {
                std::cout << "Rules was selected" << std::endl;
                window.close();
            }
            if (a < 210 && b < 888 && b>820)
            {
                std::cout << "Exit was selected" << std::endl;
                window.close();
            }

        }

        void hover(sf::RenderWindow& window)
        {
            while (window.isOpen())
           {
                
                int a = sf::Mouse::getPosition(window).x;
                int b = sf::Mouse::getPosition(window).y;
                if (a< 570 && b < 545 && b>508)
                {

                    window.clear();
                    setBoard(window);
                    o1Disp(window);
                }
                else if (a <536 && b < 658 && b>614)
                {
                    window.clear();
                    setBoard(window);
                    o2Disp(window);

                }
                else if (a< 290 && b < 760 && b>723)
                {
                    window.clear();
                    setBoard(window);
                    o3Disp(window);
                }
                else if(a < 210 && b < 888 && b>820)
                {
                    window.clear();
                    setBoard(window);
                    o4Disp(window);   
                }
                else
                {
                    window.clear();
                    setBoard(window);
                    dispDestruct(window);
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    clickCheck(a,b,window);
                }
            }
        }
};
void initialMenu(sf::RenderWindow& window);
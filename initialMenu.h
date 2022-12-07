#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include "menuBoard.h"
#pragma once
class initMenu
{
	private:
		//defining font
		sf::Font gfont;

		//initializing text
		sf::Text singleplayer1,singleplayer2, multiplayer1,multiplayer2, rules, exit;

        float scale;
        int character_size;
		float movex;
	public:
        initMenu(sf::RenderWindow& window)
        {
            scale =static_cast<float> (1000 / 1920.0);
			movex=scale * 40;
            character_size = static_cast<int > (scale * 40);
             //loading font
            gfont.loadFromFile("fonts/gfont.ttf");

            //loading fonts for text and setting size
            singleplayer1.setFont(gfont);
            singleplayer1.setCharacterSize(character_size);

            singleplayer2.setFont(gfont);
            singleplayer2.setCharacterSize(character_size);

            multiplayer1.setFont(gfont);
            multiplayer1.setCharacterSize(character_size);

            //multiplayer2.setFont(gfont);
            //multiplayer2.setCharacterSize(character_size);

            rules.setFont(gfont);
            rules.setCharacterSize(character_size);

            exit.setFont(gfont);
            exit.setCharacterSize(character_size);

            //setting position for each text
            singleplayer1.move(movex,static_cast<float>(scale * 470));
            singleplayer2.move(movex, static_cast<float>(scale * 540));

            
            multiplayer1.move(movex, static_cast<float>(scale*610));
            multiplayer2.move(movex, static_cast<float>(scale*680));

            rules.move(movex, static_cast<float>(scale * 730));
            exit.move(movex, static_cast<float>(scale * 820));


            //setting Text to display text

            singleplayer1.setString("Single Player Easy");
            singleplayer2.setString("single Player Hard");

            multiplayer1.setString("Multi Player");
            multiplayer2.setString("Multi Player Network");

            rules.setString("Rules");
            exit.setString("Exit");
       
            window.draw(singleplayer1);
            window.draw(singleplayer2);

            window.draw(multiplayer1);
            window.draw(multiplayer2);

            window.draw(rules);
            window.draw(exit);
            window.display();

        }

        ~initMenu()
        {

        }

        //display menu initially when begins
        void menuDisp(sf::RenderWindow& window)
        {

            //writing texts
            window.draw(singleplayer1);
            window.draw(singleplayer2);

            window.draw(multiplayer1);
            window.draw(multiplayer2);

            window.draw(rules);
            window.draw(exit);
            window.display();
        }
		

        //hovering when first is selected
        void o1Disp(sf::RenderWindow& window)
        {
            singleplayer1.setOutlineThickness(scale * 20);
            singleplayer2.setOutlineThickness(0);

            multiplayer1.setOutlineThickness(0);
            multiplayer2.setOutlineThickness(0);

            rules.setOutlineThickness(0);
            exit.setOutlineThickness(0);
            //writing texts
            window.draw(singleplayer1);
            window.draw(singleplayer2);
            window.draw(multiplayer1);
            window.draw(multiplayer2);

            window.draw(rules);
            window.draw(exit);
            window.display();
        }
        
        //hovering when multiplayer is selected
        void o2Disp(sf::RenderWindow& window)
        {
            singleplayer1.setOutlineThickness(0);
            singleplayer2.setOutlineThickness(0);
            multiplayer1.setOutlineThickness(scale * 20);
            multiplayer2.setOutlineThickness(0);

            rules.setOutlineThickness(0);
            exit.setOutlineThickness(0);
            //writing texts
            window.draw(singleplayer1);
            window.draw(singleplayer2);
            window.draw(multiplayer1);
            window.draw(multiplayer2);

            window.draw(rules);
            window.draw(exit);
            window.display();
        }
        
        //hovering when rules is selected
        void o3Disp(sf::RenderWindow& window)
        {
            singleplayer1.setOutlineThickness(0);
            singleplayer2.setOutlineThickness(0);
            multiplayer1.setOutlineThickness(0);
            multiplayer2.setOutlineThickness(0);

            rules.setOutlineThickness(scale * 20);
            exit.setOutlineThickness(0);
            //writing texts
            window.draw(singleplayer1);
            window.draw(singleplayer2);

            window.draw(multiplayer1);
            window.draw(multiplayer2);

            window.draw(rules);
            window.draw(exit);
            window.display();
        }
        
        //hovering when exit is selected
        void o4Disp(sf::RenderWindow& window)
        {
            singleplayer1.setOutlineThickness(0);
            singleplayer2.setOutlineThickness(0);

            multiplayer1.setOutlineThickness(0);
            multiplayer2.setOutlineThickness(0);


            rules.setOutlineThickness(0);
            exit.setOutlineThickness(scale * 20);
            //writing texts
            window.draw(singleplayer1);
            window.draw(singleplayer2);
            window.draw(multiplayer1);
            window.draw(multiplayer2);

            window.draw(rules);
            window.draw(exit);
            window.display();
        }

        //hovering when singleplayer2 is selected
        void o5Disp(sf::RenderWindow& window)
        {
            singleplayer1.setOutlineThickness(0);
            singleplayer2.setOutlineThickness(scale * 20);

            multiplayer1.setOutlineThickness(0);
            multiplayer2.setOutlineThickness(0);


            rules.setOutlineThickness(0);
            exit.setOutlineThickness(0);
            //writing texts
            window.draw(singleplayer1);
            window.draw(singleplayer2);
            window.draw(multiplayer1);
            window.draw(multiplayer2);

            window.draw(rules);
            window.draw(exit);
            window.display();
        }
        //hovering when multiplayer2 is selected
        void o6Disp(sf::RenderWindow& window)
        {
            singleplayer1.setOutlineThickness(0);
            singleplayer2.setOutlineThickness(0);

            multiplayer1.setOutlineThickness(0);
            multiplayer2.setOutlineThickness(scale * 20);


            rules.setOutlineThickness(0);
            exit.setOutlineThickness(0);
            //writing texts
            window.draw(singleplayer1);
            window.draw(singleplayer2);
            window.draw(multiplayer1);
            window.draw(multiplayer2);

            window.draw(rules);
            window.draw(exit);
            window.display();
        }

        void dispDestruct(sf::RenderWindow& window)
        {
            //destruct thickness created by hovering
            singleplayer1.setOutlineThickness(0);
            singleplayer2.setOutlineThickness(0);

            multiplayer1.setOutlineThickness(0);
            multiplayer2.setOutlineThickness(0);

            rules.setOutlineThickness(0);
            exit.setOutlineThickness(0);
            //writing texts
            window.draw(singleplayer1);
            window.draw(singleplayer2);

            window.draw(multiplayer1);
            window.draw(multiplayer2);

            window.draw(rules);
            window.draw(exit);
            window.display();
        }

        
       
        int clickCheck(int a,int b,sf::RenderWindow &window)
        {
            std::cout << a << "," << b << std::endl;

            if (a < scale * 570 && b < scale * 545 && b>movex)
            {
                return 1;
            }

            if (a < scale * 570 && b<587 && b>scale * 550)
            {
                return 2;
            }
            
            if (a < scale * 536 && b < scale * 658 && b>scale * 614)
            {
                return 3;
            }

            if (a < scale * 700 && b < scale * 723 && b>scale * 689)
            {
                return 4;
            }
            if (a < scale * 290 && b < scale * 760 && b>scale * 727)
            {
                std::cout << "Rules was selected" << std::endl;
                return 5;
            }
            if (a < scale * 210 && b < scale * 876 && b>scale * 827)
            {
                std::cout << "aexit";
                window.close();

            }

        }

        int hover(sf::RenderWindow& window)
        {
            while (window.isOpen())
           {
                
                int a = sf::Mouse::getPosition(window).x;
                int b = sf::Mouse::getPosition(window).y;
                if (a< scale * 570 && b < scale * 545 && b>movex)
                {

                    window.clear();
                    setBoard(window);
                    o1Disp(window);
                }
                else if (a < scale * 570 && b<587 && b>scale * 550)
                {
                    window.clear();
                    setBoard(window);
                    o5Disp(window);
                }
                else if (a < scale * 536 && b < scale * 68 && b>scale * 614)
                {
                    window.clear();
                    setBoard(window);
                    o2Disp(window);

                }
                

                else if (a< scale * 290 && b < scale * 760 && b>scale * 740)
                {
                    window.clear();
                    setBoard(window);
                    o3Disp(window);
                }
                else if(a < scale * 210 && b < scale * 876 && b>scale * 827)
                {
                    std::cout << "\n \n Exit";
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
                    a = clickCheck(a, b, window);
                    if (a < 6 && a>0)
                    {
                        return a;
                    }
                }
            }
        }
        
        void show_rules()
        {
            sf::Event event;
            sf::RenderWindow window(sf::VideoMode(1000, 500), "Help");
            window.clear();
            //setBoard(window);
            sf::Text rule1,rule2;
            rule1.setFont(gfont);
            rule1.setCharacterSize(30);
            rule1.move(0, 20);
            rule1.setString("1 This is rule 1");
            window.draw(rule1);
            rule2.setFont(gfont);
            rule2.setCharacterSize(30);
            rule2.move(0, 20);
            rule1.setString("2 this is rule 2");
            window.draw(rule2);
            window.display();
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

        }
};
void initialMenu(sf::RenderWindow& window);

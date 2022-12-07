#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include"compare.h"
#include"imagePara.h"
namespace
{
    extern int initPos[8][8] = {
                      {0,0,0,3,0,0,0,1},
                      {1,0,1,0,1,0,1,0},
                      {0,0,0,1,0,1,0,1},
                      {0,0,2,0,0,0,0,0},
                      {0,0,0,3,0,0,0,0},
                      {2,0,0,0,0,0,2,0},
                      {0,2,0,2,0,2,0,2},
                      {2,0,2,0,2,0,2,0}
    };
    extern int turn = 0;
};
class initialBoard:public imagePara
{
protected:
    sf::Vector2i clickedPos;
    float scale = static_cast <float> (1000 / 1920.0);//this helps to define resolution ratio
   
    int* posreset = &initPos[0][0]; //points the matrix for pieces

    int possibleMoves[4][2] = { { -1, -1},
                                {-1,-1 },
                                {-1,-1 },
                                {-1,-1 }

    };//stores possiblemove of a selected and valid piece
    int mulpossibleMoves[4][2] = { { -1, -1},
                                {-1,-1 },
                                {-1,-1 },
                                {-1,-1 }

    };//if a multiple move is possible it stores the possible move


    int* posmove = &possibleMoves[0][0];//points possiblemove
    int* mulposmove = &mulpossibleMoves[0][0];//points mul possiblemove
    int box[2] = { -1,-1 };//stores the selected piece position
    int mulbox[2] = { -1,-1 };//stores the branch from which mutiple move is possible
    int* ptbox = &box[0];
    int* mulptbox = &mulbox[0];
    sf::Text msg;
   
    
    
    public:
        initialBoard()
        {
            msg.setFont(gfont);
            msg.setCharacterSize(60);
            msg.setPosition(50,50);
            msg.setFillColor(sf::Color::Red);
            msg.setOutlineThickness(10);
            msg.setOutlineColor(sf::Color::Yellow);
        };
    

    //checks for the click
    sf::Vector2i getClickedBox()
    {
        return clickedPos;
    }


    int checkClick(sf::RenderWindow& window)
    {
        int* pos = posreset;
        //display turn message

        //check for the piececlicked
        while (window.isOpen())
        {

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                clickedPos = sf::Vector2i(static_cast<int>((sf::Mouse::getPosition()).x - boardPos.x) / 111, static_cast<int>((sf::Mouse::getPosition()).y - boardPos.y) / 111);
                std::cout << clickedPos.x << ",,"<<clickedPos.y << std::endl;
                if (clickedPos.x == -3 || clickedPos.x==-4 && clickedPos.y==8)
                {
                    return 7;
                }
                window.clear();
                setBoard(window);
                //std::cout << "xyz" << "hello" << clickedPos.x << clickedPos.y << std::endl;
                if (turn % 2 == 0 && ((*(pos + clickedPos.y * 8 + clickedPos.x) == 2) || (*(pos + clickedPos.y * 8 + clickedPos.x) == 4)))
                {

                    return 1;

                }
                else if (turn % 2 == 1 && ((*(pos + clickedPos.y * 8 + clickedPos.x) == 1) || (*(pos + clickedPos.y * 8 + clickedPos.x) == 3)))
                {
                    return 2;
                }
                else
                {
                    return 0;
                }
            }
        }
        return -1;
    };
    
    void resetMatrix()
    {
        for (int t = 0; t < 2; t++)
            for (int u = 0; u < 2; u++)
                possibleMoves[t][u] = -1;

        for (int k = 0; k < 2; k++)
        {
            *(ptbox + k) = -1;
        }

        for (int t = 0; t < 2; t++)
            for (int u = 0; u < 2; u++)
                mulpossibleMoves[t][u] = -1;

        for (int k = 0; k < 2; k++)
        {
            *(mulptbox + k) = -1;
        }

    }


    

    //resets possiblemove mulpossiblemove box and mulbox to -1
    


   

    //add the section 
    int pmove(sf::RenderWindow& window)
    {
        int* pbox = ptbox;
        int* pos = posreset;
    
        sf::Clock clock;
        clock.restart();
        bool moved = false;
       
        //std::cout << *ptbox<<*(ptbox+1);
        
        //error solved of pieces disappearing
        for (int l = 0; l < 4; l++)
        {
          
            if (*ptbox == possibleMoves[l][0] && *(ptbox + 1) == possibleMoves[l][1])
                {
                possibleMoves[l][0] = -1;
                possibleMoves[l][1] = -1;
                }
        }
        

        while (!moved)
        {
         
            sf::Time elapsed1 =clock.getElapsedTime();
            int time =(int) elapsed1.asSeconds();
            if (time > 4)
            {
              
                window.clear();
                resetMatrix();
                setBoard(window);
                return 0;
            }
            int k;
            
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {

                int* pos = posreset;
                int* move = posmove;
                int* mulmove = mulposmove;
                sf::Vector2i selectedMove = sf::Mouse::getPosition();
                int a = static_cast <int>(selectedMove.x - boardPos.x) / 111;
                int b = static_cast <int>(selectedMove.y - boardPos.y) / 111;

                if ((*(move + 0) == a &&  *(move + 1) == b) || 
                    (*(move + 2) == a &&   *(move + 3) == b) ||
                    (*(move + 4) == a && *(move + 5) == b) ||
                    ((*(move + 6) == a && *(move + 7) == b) &&
                      *(ptbox)!=a && *(ptbox+1)!=b)
                    )
                {

                    //std::cout << "7:27state entered";
                    k = *(pos + (*(pbox + 1)) * 8 + *pbox);
                    *(pos + (b * 8 + a)) = k;
                    *(pos + (*(pbox + 1)) * 8 + *pbox) = 0;
                    if ((a + *(pbox)) % 2 == 0 || (b+*(pbox+1))%2==0)
                    {
                        int g= (a + *pbox)/2;
                        int h = (b + *(pbox+1))/2;
                       *(pos + h*8 + g) = 0;


                    }
                    std::cout << "play";
    
  
                    if (b == 0 && *(pos + (b * 8 + a))==2)
                    {
                        *(pos + (b * 8 + a)) = 4;
                    }
                    if (b == 7 && *(pos + (b * 8 + a)) == 1)
                    {
                        *(pos + (b * 8 + a)) = 3;
                    }
                    moved = true;
                                    
                }

                //multiple move
                else if ((*(mulmove + 0) == a &&  *(mulmove + 1) == b) ||
                    (*(mulmove + 2) == a &&   *(mulmove + 3) == b) ||
                    (*(mulmove + 4) == a && *(mulmove + 5) == b) ||
                    ((*(mulmove + 6) == a && *(mulmove + 7) == b) &&
                      *(ptbox)!=a && *(ptbox+1)!=b)
                    )
                {

                                     
                    k = *(pos + (*(pbox + 1)) * 8 + *pbox);
                    *(pos + (b * 8 + a)) = k;
                    *(pos + (*(pbox + 1)) * 8 + *pbox) = 0;
                    
                    //this section initialize the first jump made as 0
                    int g = (*(mulbox)+*(box)) / 2;
                    int h= (*(mulbox+1)+*(box+1)) / 2;
                     *(pos + h * 8 + g) = 0;
                    
                    //this section initialize the 2nd jump made as 0 
                    int gg = (*(mulbox)+a) / 2;
                    int hh = (*(mulbox + 1) + b) / 2;
                    *(pos + hh * 8 + gg) = 0;

                    if (b == 0 && *(pos + (b * 8 + a))==2)
                    {
                        *(pos + (b * 8 + a)) = 4;
                    }
                    if (b == 7 && *(pos + (b * 8 + a)) == 1)
                    {
                        *(pos + (b * 8 + a)) = 3;
                    }
                    moved = true;
                   
                }
                else if (*(pos + b * 8 + a) == 0)
                {
                    return 0;
                }
               
            }

        }
        jump.play();
        turn++;
        resetMatrix();

        if (setBoard(window) == 1)
        {
            msg.setString("White wins");
            window.draw(msg);
            window.display();
            system("Pause");
        }
        else if(setBoard(window)==2)
        {
            msg.setString("Black wins");
            window.draw(msg);
            window.display();
            system("Pause");
        }
        return 1;
}

   


   int setBoard(sf::RenderWindow& window)
    {
       int countB=0, countW=0;
       if (turn % 2 == 0)
           turnMsg.setString("Black's Turn");
       else
           turnMsg.setString("White's Turn");

       int* pos = posreset;
       window.clear();
       
       int height=window.getSize().x;
       int width = window.getSize().y;
       float xmove = static_cast <float> (height - 995) / 2;
       float ymove = 0;//static_cast <float> (width - 995) / 2;
       sf::Vector2f move(xmove, ymove);
       sf::Vector2f i11(56, 59);
       boardPos = (move + i11);
        sboard.move(move);
        
        window.draw(sbck);
 
        window.draw(sboard);

        sboard.setPosition(0, 0);

        int h = window.getSize().x;
        int w = window.getSize().y;
     
        sf::Text Back;
        back.setFont(gfont);
        back.setCharacterSize(30);
        back.setString("Back");
            
        window.draw(turnMsg); 
              for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (initPos[i][j] == 1)
                {
                    countW++;
                   // //std::cout << i << "," << j << ":contains white" << std::endl;
                    swhite.setPosition(boardPos + sf::Vector2f(static_cast <float>(j * 111), static_cast <float> (i * 111)));
                    window.draw(swhite);
                }
                else if (initPos[i][j] == 2)
                {
                    countB++;
                    ////std::cout << i << "," << j << ":contains black" << std::endl;
                    sblack.setPosition(boardPos + sf::Vector2f(static_cast <float> (j * 111), static_cast <float> (i * 111)));
                    window.draw(sblack);

                }
                else if (initPos[i][j] == 3)
                {
                    countW++;
                    ////std::cout << i << "," << j << ":contains black king" << std::endl;
                    swhiteKing.setPosition(boardPos + sf::Vector2f(static_cast <float>(j * 111), static_cast <float>( i * 111)));
                    window.draw(swhiteKing);

                }
                else if (initPos[i][j] == 4)
                {
                    countB++;
                    ////std::cout << i << "," << j << ":contains black king" << std::endl;
                    sblackKing.setPosition(boardPos + sf::Vector2f(static_cast <float>(j * 111), static_cast <float>(i * 111)));
                    window.draw(sblackKing);
                }

            }
        }
              back.setPosition(0, 950);
              window.draw(back);
        window.display();

        if (countB == 0)
        {
            //std::cout << "White wins";
            return 1;
        }
        else if (countW == 0)
        {
            //std::cout << "Black wins";
            return 2;
        }
        else
            return 0;
    }

    
};



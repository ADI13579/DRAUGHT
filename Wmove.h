#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include"compare.h"
#include"Board.h"

class Wmove :public initialBoard
{
	public:
        //checks every possible move for white piece except multiple move 
        bool whiteMove(sf::Vector2i clickPos, sf::RenderWindow& window)
        {
            setBoard(window);
            window.display();
            window.display();
            int* pos = posreset;
            int* pbox = ptbox;
            resetMatrix();

            sf::Vector2i box(clickPos.x, clickPos.y);
            //if it is not king piece
            if (*(pos + box.y * 8 + box.x) == 1)
            {
                int a = box.x, b = box.y;

                int j = *(pos + (b * 8 + a));


                move.setSize(sf::Vector2f(111, 111));
                if (j == 1)
                {
                    *pbox = a;
                    *(pbox + 1) = b;
                    if (b == 7)
                    {
                        return 0;;
                    }
                    if (a == 0)
                    {

                        if ((*(pos + (b + 2) * 8 + a + 2) == 0) && ((*(pos + (b + 1) * 8 + a + 1) == 2) || (*(pos + (b + 1) * 8 + a + 1) == 4)) && comp::compare(b + 2, a + 2, b + 1, a + 1))
                        {
                            sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>((a + 2) * 111), static_cast <float>((b + 2) * 111)));
                            move.setPosition(rbox);
                            window.draw(move);
                            possibleMoves[1][0] = a + 2;
                            possibleMoves[1][1] = b + 2;
                            multiplemoveWhite(j, a + 2, b + 2, window);

                        }
                        else if (*(pos + (b + 1) * 8 + a + 1) == 0 && comp::compare(b + 1, a + 1))
                        {
                            sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>(a + 1) * 111, static_cast <float>(b + 1) * 111));
                            move.setPosition(rbox);
                            window.draw(move);
                            possibleMoves[1][0] = a + 1;
                            possibleMoves[1][1] = b + 1;
                            //std::cout << "HUIOHUASDHI" << std::endl;

                        }
                    }
                    else if (a == 7)
                    {


                        if ((*(pos + (b + 2) * 8 + a - 2) == 0) && (*(pos + (b + 1) * 8 + a - 1) == 2 || *(pos + (b + 1) * 8 + a - 1) == 4) && comp::compare(b + 2, a - 2, b + 1, a - 1))
                        {
                            sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 2) * 111, static_cast <float>(b + 2) * 111));
                            move.setPosition(lbox);
                            window.draw(move);
                            possibleMoves[0][0] = a - 2;
                            possibleMoves[0][1] = b + 2;
                            multiplemoveWhite(j, a - 2, b + 2, window);

                        }
                        else if ((*(pos + (b + 1) * 8 + a - 1) == 0) && comp::compare(b + 1, a - 1))
                        {
                            sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 1) * 111, static_cast <float> (b + 1) * 111));
                            move.setPosition(lbox);
                            window.draw(move);
                            possibleMoves[0][0] = a - 1;
                            possibleMoves[0][1] = b + 1;


                        }
                        else
                        {
                            return 0;;

                        }
                    }
                    else if (a > 0 && a < 7)
                    {
                        //if there are pieces in two consecutive diagonals and have no move possible
                        if ((*(pos + (b + 1) * 8 + (a - 1)) == 1 || *(pos + (b + 1) * 8 + (a - 1)) == 2 || *(pos + (b + 1) * 8 + (a - 1)) == 3 || *(pos + (b + 1) * 8 + (a - 1)) == 4)
                            && (*(pos + (b + 2) * 8 + (a - 2)) == 1 || *(pos + (b + 2) * 8 + (a - 2)) == 2 || *(pos + (b + 2) * 8 + (a - 2)) == 3 || *(pos + (b + 2) * 8 + (a - 2)) == 4 && a - 2 >= 0 && b + 2 <= 7)
                            && (*(pos + (b + 1) * 8 + (a + 1)) == 1 || *(pos + (b + 1) * 8 + (a + 1)) == 2 || *(pos + (b + 1) * 8 + (a + 1)) == 3 || *(pos + (b + 1) * 8 + (a + 1)) == 4)
                            && (*(pos + (b + 2) * 8 + (a + 2)) == 1 || *(pos + (b + 2) * 8 + (a + 2)) == 2 || *(pos + (b + 2) * 8 + (a + 2)) == 3 || *(pos + (b + 2) * 8 + (a + 2)) == 4 && b + 2 <= 7 && a + 2 <= 7))
                        {
                            return 0;;
                        }
                        //if white is selected and both diagonals have white.
                        else if ((*(pos + (b + 1) * 8 + a - 1) == 1 || *(pos + (b + 1) * 8 + a - 1) == 3) && (*(pos + (b + 1) * 8 + a + 1) == 1 || *(pos + (b + 1) * 8 + a + 1) == 3) && comp::compare(b + 1, a - 1, a + 1, 0))
                        {
                            return 0;;
                        }


                        //if a jump in diagonal is possible
                        if ((*(pos + (b + 2) * 8 + a + 2) == 0) && (*(pos + (b + 1) * 8 + a + 1) == 2 || *(pos + (b + 1) * 8 + a + 1) == 4) && comp::compare(b + 2, a + 2, b + 1, a + 1))
                        {
                            sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>((a + 2) * 111), static_cast <float>((b + 2) * 111)));
                            move.setPosition(rbox);
                            window.draw(move);
                            possibleMoves[1][0] = a + 2;
                            possibleMoves[1][1] = b + 2;
                            multiplemoveWhite(j, a + 2, b + 2, window);
                        }
                        //if diagonal move is possible
                        else if (*(pos + (b + 1) * 8 + a + 1) == 0 && comp::compare(b + 1, a + 1))
                        {

                            sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>(a + 1) * 111, static_cast <float> (b + 1) * 111));
                            move.setPosition(rbox);
                            window.draw(move);
                            possibleMoves[1][0] = a + 1;
                            possibleMoves[1][1] = b + 1;


                        }
                        //check if left jump is possible
                        if ((*(pos + (b + 2) * 8 + a - 2) == 0) && (*(pos + (b + 1) * 8 + a - 1) == 2 || *(pos + (b + 1) * 8 + a - 1) == 4) && comp::compare(b + 2, a - 2, b + 1, a - 1))
                        {
                            sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 2) * 111, static_cast <float> (b + 2) * 111));
                            move.setPosition(lbox);
                            window.draw(move);
                            possibleMoves[0][0] = a - 2;
                            possibleMoves[0][1] = b + 2;
                            multiplemoveWhite(j, a - 2, b + 2, window);

                        }
                        //jump left
                        else if ((*(pos + (b + 1) * 8 + a - 1) == 0) && comp::compare(b + 1, a - 1))
                        {
                            sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 1) * 111, static_cast <float> (b + 1) * 111));
                            move.setPosition(lbox);
                            window.draw(move);
                            possibleMoves[0][0] = a - 1;
                            possibleMoves[0][1] = b + 1;

                        }

                    }

                    else
                    {
                        return 0;;
                    }
                    window.display();

                    pmove(window);
                    //std::cout << "Matrix";
                    for (int p = 0; p < 8; p++)
                    {

                        for (int q = 0; q < 8; q++)
                        {
                            //std::cout << *(pos++);
                        }
                        //std::cout << std::endl;
                    }

                }

            }

            //king move
            if (*(pos + box.y * 8 + box.x) == 3)
            {
                int a = box.x, b = box.y;

                int j = *(pos + (b * 8 + a));


                move.setSize(sf::Vector2f(111, 111));
                //checks for move of king
                if (j == 3)
                {
                    *pbox = a;
                    *(pbox + 1) = b;
                    if (a == 0)
                    {

                        if ((*(pos + (b + 2) * 8 + a + 2) == 0) && ((*(pos + (b + 1) * 8 + a + 1) == 2) || (*(pos + (b + 1) * 8 + a + 1) == 4)) && comp::compare(b + 2, a + 2, b + 1, a + 1))
                        {
                            sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>((a + 2) * 111), static_cast <float>((b + 2) * 111)));
                            move.setPosition(rbox);
                            window.draw(move);
                            possibleMoves[0][0] = a + 2;
                            possibleMoves[0][1] = b + 2;
                            multiplemoveWhite(j, a + 2, b + 2, window);

                        }
                        else if (*(pos + (b + 1) * 8 + a + 1) == 0 && comp::compare(b + 1, a + 1))
                        {
                            sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>(a + 1) * 111, static_cast <float>(b + 1) * 111));
                            move.setPosition(rbox);
                            window.draw(move);
                            possibleMoves[0][0] = a + 1;
                            possibleMoves[0][1] = b + 1;

                        }


                        if ((*(pos + (b - 2) * 8 + a + 2) == 0) && (*(pos + (b - 1) * 8 + a + 1) == 2 || *(pos + (b - 1) * 8 + a + 1) == 4) && comp::compare(b - 2, a + 2, b - 1, a + 1))
                        {
                            sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>(a + 2) * 111, static_cast <float>(b - 2) * 111));
                            move.setPosition(rbox);
                            window.draw(move);
                            possibleMoves[1][0] = a + 2;
                            possibleMoves[1][1] = b - 2;
                            multiplemoveWhite(j, a + 2, b - 2, window);

                        }
                        else if ((*(pos + (b - 1) * 8 + a + 1) == 0) && comp::compare(b - 1, a + 1))
                        {
                            sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>(a + 1) * 111, static_cast <float>(b - 1) * 111));
                            move.setPosition(rbox);
                            window.draw(move);
                            possibleMoves[1][0] = a + 1;
                            possibleMoves[1][1] = b - 1;
                        }

                    }
                    else if (a == 7)
                    {
                        if ((*(pos + (b - 2) * 8 + a - 2) == 0) && (*(pos + (b - 1) * 8 + a - 1) == 2 || (*(pos + (b - 1) * 8 + a - 1)) == 4) && comp::compare(b - 2, a - 2, b - 1, a - 1))
                        {

                            sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 2) * 111, static_cast <float>(b - 2) * 111));
                            move.setPosition(lbox);
                            window.draw(move);
                            possibleMoves[0][0] = a - 2;
                            possibleMoves[0][1] = b - 2;
                            multiplemoveWhite(j, a - 2, b - 2, window);



                        }
                        else if (*(pos + (b - 1) * 8 + (a - 1)) == 0 && comp::compare(b - 1, a - 1))
                        {
                            sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>((a - 1) * 111), static_cast <float>((b - 1) * 111)));
                            move.setPosition(lbox);
                            window.draw(move);
                            possibleMoves[0][0] = a - 1;
                            possibleMoves[0][1] = b - 1;

                        }



                        if ((*(pos + (b + 2) * 8 + a - 2) == 0) && (*(pos + (b + 1) * 8 + a - 1) == 2 || *(pos + (b + 1) * 8 + a - 1) == 4) && comp::compare(b + 2, a - 2, b + 1, a - 1))
                        {
                            sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 2) * 111, static_cast <float>(b + 2) * 111));
                            move.setPosition(lbox);
                            window.draw(move);
                            possibleMoves[1][0] = a - 2;
                            possibleMoves[1][1] = b + 2;
                            multiplemoveWhite(j, a - 2, b + 2, window);


                        }
                        else if ((*(pos + (b + 1) * 8 + a - 1) == 0) && comp::compare(b + 1, a - 1))
                        {
                            sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 1) * 111, static_cast <float> (b + 1) * 111));
                            move.setPosition(lbox);
                            window.draw(move);
                            possibleMoves[1][0] = a - 1;
                            possibleMoves[1][1] = b + 1;

                        }
                        else
                        {
                            return 0;;
                        }
                    }
                    else if (a > 0 && a < 7)
                    {
                        //if the two places in consecutive diagonals  and has no move available
                        if ((*(pos + (b + 1) * 8 + (a - 1)) == 1 || *(pos + (b + 1) * 8 + (a - 1)) == 2 || *(pos + (b + 1) * 8 + (a - 1)) == 3 || *(pos + (b + 1) * 8 + (a - 1)) == 4)
                            && (*(pos + (b + 2) * 8 + (a - 2)) == 1 || *(pos + (b + 2) * 8 + (a - 2)) == 2 || *(pos + (b + 2) * 8 + (a - 2)) == 3 || *(pos + (b + 2) * 8 + (a - 2)) == 4 && a - 2 >= 0 && b + 2 <= 7)
                            && (*(pos + (b + 1) * 8 + (a + 1)) == 1 || *(pos + (b + 1) * 8 + (a + 1)) == 2 || *(pos + (b + 1) * 8 + (a + 1)) == 3 || *(pos + (b + 1) * 8 + (a + 1)) == 4)
                            && (*(pos + (b + 2) * 8 + (a + 2)) == 1 || *(pos + (b + 2) * 8 + (a + 2)) == 2 || *(pos + (b + 2) * 8 + (a + 2)) == 3 || *(pos + (b + 2) * 8 + (a + 2)) == 4 && b + 2 <= 7 && a + 2 <= 7)
                            && (*(pos + (b - 1) * 8 + (a - 1)) == 1 || *(pos + (b - 1) * 8 + (a - 1)) == 2 || *(pos + (b - 1) * 8 + (a - 1)) == 3 || *(pos + (b - 1) * 8 + (a - 1)) == 4)
                            && (*(pos + (b - 2) * 8 + (a - 2)) == 1 || *(pos + (b - 2) * 8 + (a - 2)) == 2 || *(pos + (b - 2) * 8 + (a - 2)) == 3 || *(pos + (b - 2) * 8 + (a - 2)) == 4 && b - 2 >= 0 && a - 2 >= 0)
                            && (*(pos + (b - 1) * 8 + (a + 1)) == 1 || *(pos + (b - 1) * 8 + (a + 1)) == 2 || *(pos + (b - 1) * 8 + (a + 1)) == 3 || *(pos + (b - 1) * 8 + (a + 1)) == 4)
                            && (*(pos + (b - 2) * 8 + (a + 2)) == 1 || *(pos + (b - 2) * 8 + (a + 2)) == 2 || *(pos + (b - 2) * 8 + (a + 2)) == 3 || *(pos + (b - 2) * 8 + (a + 2)) == 4 && b + 2 <= 7 && a + 2 <= 7))
                        {
                            return 0;;
                        }

                        //if a jump in diagonal is possible
                        if ((*(pos + (b + 2) * 8 + a + 2) == 0) && (*(pos + (b + 1) * 8 + a + 1) == 2 || *(pos + (b + 1) * 8 + a + 1) == 4) && comp::compare(b + 2, a + 2, b + 1, a + 1))
                        {
                            sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>((a + 2) * 111), static_cast <float>((b + 2) * 111)));
                            move.setPosition(rbox);
                            window.draw(move);
                            possibleMoves[0][0] = a + 2;
                            possibleMoves[0][1] = b + 2;
                            multiplemoveWhite(j, a + 2, b + 2, window);

                        }

                        //if diagonal move is possible
                        else if (*(pos + (b + 1) * 8 + a + 1) == 0 && b + 1 <= 7 && comp::compare(b + 1, a + 1))
                        {
                            sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>(a + 1) * 111, static_cast <float> (b + 1) * 111));
                            move.setPosition(rbox);
                            window.draw(move);
                            possibleMoves[0][0] = a + 1;
                            possibleMoves[0][1] = b + 1;

                        }
                        //check if left jump is possible
                        if ((*(pos + (b + 2) * 8 + a - 2) == 0) && (*(pos + (b + 1) * 8 + a - 1) == 2 || *(pos + (b + 1) * 8 + a - 1) == 4) && comp::compare(b + 2, a - 2, b + 1, a - 1))
                        {

                            sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 2) * 111, static_cast <float> (b + 2) * 111));
                            move.setPosition(lbox);
                            window.draw(move);
                            possibleMoves[1][0] = a - 2;
                            possibleMoves[1][1] = b + 2;
                            multiplemoveWhite(j, a - 2, b + 2, window);

                        }
                        //jump left
                        else if ((*(pos + (b + 1) * 8 + a - 1) == 0) && comp::compare(b + 1, a - 1))
                        {
                            sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 1) * 111, static_cast <float> (b + 1) * 111));
                            move.setPosition(lbox);
                            window.draw(move);
                            possibleMoves[1][0] = a - 1;
                            possibleMoves[1][1] = b + 1;

                        }




                        //if a jump in diagonal is possible
                        if ((*(pos + (b - 2) * 8 + a + 2) == 0) && (*(pos + (b - 1) * 8 + a + 1) == 2 || *(pos + (b - 1) * 8 + a + 1) == 4) && comp::compare(b - 2, a + 2, b - 1, a + 1))
                        {
                            sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>(a + 2) * 111, static_cast <float> (b - 2) * 111));
                            move.setPosition(rbox);
                            window.draw(move);
                            possibleMoves[2][0] = a + 2;
                            possibleMoves[2][1] = b - 2;
                            multiplemoveWhite(j, a + 2, b - 2, window);

                        }


                        else if ((*(pos + (b - 1) * 8 + a + 1) == 0) && comp::compare(b - 1, a + 1))
                        {
                            sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>(a + 1) * 111, static_cast <float>(b - 1) * 111));
                            move.setPosition(rbox);
                            window.draw(move);
                            possibleMoves[2][0] = a + 1;
                            possibleMoves[2][1] = b - 1;
                        }


                        if ((*(pos + (b - 2) * 8 + a - 2) == 0) && (*(pos + (b - 1) * 8 + a - 1) == 2 || *(pos + (b - 1) * 8 + a - 1) == 4) && comp::compare(b - 2, a - 2, b - 1, a - 1))
                        {

                            sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 2) * 111, static_cast <float>(b - 2) * 111));
                            move.setPosition(lbox);
                            window.draw(move);
                            possibleMoves[3][0] = a - 2;
                            possibleMoves[3][1] = b - 2;
                            multiplemoveWhite(j, a - 2, b - 2, window);


                        }
                        else if (*(pos + (b - 1) * 8 + (a - 1)) == 0 && comp::compare(b - 1, a - 1))
                        {
                            sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>((a - 1) * 111), static_cast <float>((b - 1) * 111)));
                            move.setPosition(lbox);
                            window.draw(move);
                            possibleMoves[3][0] = a - 1;
                            possibleMoves[3][1] = b - 1;

                        }

                    }

                    else
                    {
                        return 0;;
                    }

                    window.display();
                    pmove(window);
                    //std::cout << "Matrix";
                    for (int p = 0; p < 8; p++)
                    {

                        for (int q = 0; q < 8; q++)
                        {
                            //std::cout << *(pos++);
                        }
                        //std::cout << std::endl;
                    }



                }
            }
            return true;
        }
        void multiplemoveWhite(int j, int a, int b, sf::RenderWindow& window)
        {
            int* pos = posreset;


            move.setSize(sf::Vector2f(111, 111));
            *mulptbox = a;
            *(mulptbox + 1) = b;
            if (j == 1)
            {

                if (a == 0)
                {

                    if ((*(pos + (b + 2) * 8 + a + 2) == 0) && ((*(pos + (b + 1) * 8 + a + 1) == 2) || (*(pos + (b + 1) * 8 + a + 1) == 4)) && comp::compare(b + 2, a + 2, b + 1, a + 1))
                    {
                        sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>((a + 2) * 111), static_cast <float>((b + 2) * 111)));
                        move.setPosition(rbox);
                        window.draw(move);
                        mulpossibleMoves[1][0] = a + 2;
                        mulpossibleMoves[1][1] = b + 2;


                    }

                }
                else if (a == 7)
                {


                    if ((*(pos + (b + 2) * 8 + a - 2) == 0) && (*(pos + (b + 1) * 8 + a - 1) == 2 || *(pos + (b + 1) * 8 + a - 1) == 4) && comp::compare(b + 2, a - 2, b + 1, a - 1))
                    {
                        sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 2) * 111, static_cast <float>(b + 2) * 111));
                        move.setPosition(lbox);
                        window.draw(move);
                        mulpossibleMoves[0][0] = a - 2;
                        mulpossibleMoves[0][1] = b + 2;

                    }


                }
                else if (comp::compare(a - 1, a + 1))
                {

                    //if a jump in diagonal is possible
                    if ((*(pos + (b + 2) * 8 + a + 2) == 0) && (*(pos + (b + 1) * 8 + a + 1) == 2 || *(pos + (b + 1) * 8 + a + 1) == 4) && comp::compare(b + 2, a + 2, b + 1, a + 1))
                    {
                        sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>((a + 2) * 111), static_cast <float>((b + 2) * 111)));
                        move.setPosition(rbox);
                        window.draw(move);
                        mulpossibleMoves[1][0] = a + 2;
                        mulpossibleMoves[1][1] = b + 2;
                    }

                    //check if left jump is possible
                    if ((*(pos + (b + 2) * 8 + a - 2) == 0) && (*(pos + (b + 1) * 8 + a - 1) == 2 || *(pos + (b + 1) * 8 + a - 1) == 4) && comp::compare(b + 2, a - 2, b + 1, a - 1))
                    {
                        sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 2) * 111, static_cast <float> (b + 2) * 111));
                        move.setPosition(lbox);
                        window.draw(move);
                        mulpossibleMoves[0][0] = a - 2;
                        mulpossibleMoves[0][1] = b + 2;

                    }
                }




            }

            if (j == 3)
            {
                if (a == 0)
                {

                    if ((*(pos + (b + 2) * 8 + a + 2) == 0) && ((*(pos + (b + 1) * 8 + a + 1) == 2) || (*(pos + (b + 1) * 8 + a + 1) == 4)) && comp::compare(b + 2, a + 2, b + 1, a + 1))
                    {
                        //std::cout << "this is checked";
                        sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>((a + 2) * 111), static_cast <float>((b + 2) * 111)));
                        move.setPosition(rbox);
                        window.draw(move);
                        mulpossibleMoves[0][0] = a + 2;
                        mulpossibleMoves[0][1] = b + 2;
                    }

                    if ((*(pos + (b - 2) * 8 + a + 2) == 0) && (*(pos + (b - 1) * 8 + a + 1) == 2 || *(pos + (b - 1) * 8 + a + 1) == 4) && comp::compare(b - 2, a + 2, b - 1, a + 1))
                    {
                        sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>(a + 2) * 111, static_cast <float>(b - 2) * 111));
                        move.setPosition(rbox);
                        window.draw(move);
                        mulpossibleMoves[1][0] = a + 2;
                        mulpossibleMoves[1][1] = b - 2;
                    }


                }
                else if (a == 7)
                {
                    if ((*(pos + (b - 2) * 8 + a - 2) == 0) && (*(pos + (b - 1) * 8 + a - 1) == 2 || (*(pos + (b - 1) * 8 + a - 1)) == 4) && comp::compare(b - 2, a - 2, b - 1, a - 1))
                    {

                        sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 2) * 111, static_cast <float>(b - 2) * 111));
                        move.setPosition(lbox);
                        window.draw(move);
                        mulpossibleMoves[0][0] = a - 2;
                        mulpossibleMoves[0][1] = b - 2;
                    }



                    if ((*(pos + (b + 2) * 8 + a - 2) == 0) && (*(pos + (b + 1) * 8 + a - 1) == 2 || *(pos + (b + 1) * 8 + a - 1) == 4) && comp::compare(b + 2, a - 2, b - 1, a - 1))
                    {
                        sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 2) * 111, static_cast <float>(b + 2) * 111));
                        move.setPosition(lbox);
                        window.draw(move);
                        mulpossibleMoves[1][0] = a - 2;
                        mulpossibleMoves[1][1] = b + 2;
                    }

                }
                else if (a > 0 && a < 7)
                {


                    //if a jump in diagonal is possible
                    if ((*(pos + (b + 2) * 8 + a + 2) == 0) && (*(pos + (b + 1) * 8 + a + 1) == 2 || *(pos + (b + 1) * 8 + a + 1) == 4) && comp::compare(b + 2, a + 2, b + 1, a + 1))
                    {
                        sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>((a + 2) * 111), static_cast <float>((b + 2) * 111)));
                        move.setPosition(rbox);
                        window.draw(move);
                        mulpossibleMoves[0][0] = a + 2;
                        mulpossibleMoves[0][1] = b + 2;
                    }

                    //check if left jump is possible
                    if ((*(pos + (b + 2) * 8 + a - 2) == 0) && (*(pos + (b + 1) * 8 + a - 1) == 2 || *(pos + (b + 1) * 8 + a - 1) == 4) && comp::compare(b + 2, a - 2, b + 1, a - 1))
                    {

                        sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 2) * 111, static_cast <float> (b + 2) * 111));
                        move.setPosition(lbox);
                        window.draw(move);
                        mulpossibleMoves[1][0] = a - 2;
                        mulpossibleMoves[1][1] = b + 2;
                    }


                    //if a jump in diagonal is possible
                    if ((*(pos + (b - 2) * 8 + a + 2) == 0) && (*(pos + (b - 1) * 8 + a + 1) == 2 || *(pos + (b - 1) * 8 + a + 1) == 4) && comp::compare(b - 2, a + 2, b - 1, a + 1))
                    {
                        sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>(a + 2) * 111, static_cast <float> (b - 2) * 111));
                        move.setPosition(rbox);
                        window.draw(move);
                        mulpossibleMoves[2][0] = a + 2;
                        mulpossibleMoves[2][1] = b - 2;
                    }



                    if ((*(pos + (b - 2) * 8 + a - 2) == 0) && (*(pos + (b - 1) * 8 + a - 1) == 2 || *(pos + (b - 1) * 8 + a - 1) == 4) && comp::compare(b - 2, a - 2, b - 1, a - 1))
                    {

                        sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 2) * 111, static_cast <float>(b - 2) * 111));
                        move.setPosition(lbox);
                        window.draw(move);
                        mulpossibleMoves[3][0] = a - 2;
                        mulpossibleMoves[3][1] = b - 2;
                    }
                }
            }
        }


};
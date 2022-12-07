#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include"compare.h"
#include"Board.h"
class Bmove :public initialBoard
{

public:
    //checks the possible movement for black piece except consecutive move
    bool blackMove(sf::Vector2i clickPos, sf::RenderWindow& window)
    {
        setBoard(window);
        int* pos = posreset;
        int* pbox = ptbox;
        sf::Vector2i box(clickPos.x, clickPos.y);
        //if it is not king piece
        if (*(pos + box.y * 8 + box.x) == 2)
        {
            int a = box.x, b = box.y;

            int j = *(pos + (b * 8 + a));


           
            if (j == 2)
            {
                *pbox = a;
                *(pbox + 1) = b;
                if (a == 7)
                {

                    if ((*(pos + (b - 2) * 8 + a - 2) == 0) && (*(pos + (b - 1) * 8 + a - 1) == 1 || (*(pos + (b - 1) * 8 + a - 1)) == 3) && comp::compare(b - 2, a - 2, b - 1, a - 1))
                    {

                        sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 2) * 111, static_cast <float>(b - 2) * 111));
                        move.setPosition(lbox);
                        window.draw(move);
                        possibleMoves[1][0] = a - 2;
                        possibleMoves[1][1] = b - 2;
                        multipleMoveBlack(j, a - 2, b - 2, window);
                    }
                    else if (*(pos + (b - 1) * 8 + (a - 1)) == 0 && comp::compare(a - 1, b - 1))
                    {
                        sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>((a - 1) * 111), static_cast <float>((b - 1) * 111)));
                        move.setPosition(lbox);
                        window.draw(move);
                        possibleMoves[1][0] = a - 1;
                        possibleMoves[1][1] = b - 1;

                    }

                }
                else if (a == 0)
                {


                    if ((*(pos + (b - 2) * 8 + a + 2) == 0) && (*(pos + (b - 1) * 8 + a + 1) == 1 || *(pos + (b - 1) * 8 + a + 1) == 3) && comp::compare(b - 2, a + 2, b - 1, a + 1))
                    {
                        sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>(a + 2) * 111, static_cast <float>(b - 2) * 111));
                        move.setPosition(rbox);
                        window.draw(move);
                        possibleMoves[0][0] = a + 2;
                        possibleMoves[0][1] = b - 2;
                        multipleMoveBlack(j, a + 2, b - 2, window);
                    }
                    else if ((*(pos + (b - 1) * 8 + a + 1) == 0) && comp::compare(b - 1, a + 1))
                    {
                        sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>(a + 1) * 111, static_cast <float>(b - 1) * 111));
                        move.setPosition(rbox);
                        window.draw(move);
                        possibleMoves[0][0] = a + 1;
                        possibleMoves[0][1] = b - 1;


                    }
                    else
                    {
                        return false;

                    }
                }
                else if (a > 0 && a < 7 && b != 0)
                {




                    //if the diagonals are black or white and has no move available
                    if ((*(pos + (b - 1) * 8 + (a - 1)) == 1 || *(pos + (b - 1) * 8 + (a - 1)) == 2 || *(pos + (b - 1) * 8 + (a - 1)) == 3 || *(pos + (b - 1) * 8 + (a - 1)) == 4)
                        && (*(pos + (b - 2) * 8 + (a - 2)) == 1 || *(pos + (b - 2) * 8 + (a - 2)) == 2 || *(pos + (b - 2) * 8 + (a - 2)) == 3 || *(pos + (b - 2) * 8 + (a - 2)) == 4 && b - 2 >= 0 && a - 2 >= 0)
                        && (*(pos + (b - 1) * 8 + (a + 1)) == 1 || *(pos + (b - 1) * 8 + (a + 1)) == 2 || *(pos + (b - 1) * 8 + (a + 1)) == 3 || *(pos + (b - 1) * 8 + (a + 1)) == 4)
                        && (*(pos + (b - 2) * 8 + (a + 2)) == 1 || *(pos + (b - 2) * 8 + (a + 2)) == 2 || *(pos + (b - 2) * 8 + (a + 2)) == 3 || *(pos + (b - 2) * 8 + (a + 2)) == 4 && b + 2 <= 7 && a + 2 <= 7))
                    {
                        return false;
                    }
                    else if ((*(pos + (b - 1) * 8 + a + 1) == 2 || *(pos + (b - 1) * 8 + a + 1) == 4) && (*(pos + (b - 1) * 8 + a - 1) == 2 || *(pos + (b - 1) * 8 + a - 1) == 4) && comp::compare(b - 1, a + 1, a - 1, 0))
                    {

                        return false;
                    }

                    //check for right jump move 
                    if ((*(pos + (b + 2) * 8 + a + 2) == 0) && (*(pos + (b + 1) * 8 + a + 1) == 2 || *(pos + (b + 1) * 8 + a + 1) == 4) && b + 2 <= 7 && a + 2 <= 7 && comp::compare(b + 2, b + 1, a + 2, a + 1))
                    {
                        sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>((a + 2) * 111), static_cast <float>((b + 2) * 111)));
                        move.setPosition(rbox);
                        window.draw(move);
                        possibleMoves[1][0] = a + 2;
                        possibleMoves[1][1] = b + 2;
                        multipleMoveBlack(j, a + 2, b + 2, window);

                    }

                    //if a jump in diagonal is possible
                    if ((*(pos + (b - 2) * 8 + a + 2) == 0) && (*(pos + (b - 1) * 8 + a + 1) == 1 || *(pos + (b - 1) * 8 + a + 1) == 3) && comp::compare(b - 2, a + 2, b - 1, a + 1))
                    {
                        sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>(a + 2) * 111, static_cast <float> (b - 2) * 111));
                        move.setPosition(rbox);
                        window.draw(move);
                        possibleMoves[0][0] = a + 2;
                        possibleMoves[0][1] = b - 2;
                        multipleMoveBlack(j, a + 2, b - 2, window);
                    }
                    else if ((*(pos + (b - 1) * 8 + a + 1) == 0) && comp::compare(b - 1, a + 1))
                    {
                        //std::cout << "current condition";
                        sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>(a + 1) * 111, static_cast <float>(b - 1) * 111));
                        move.setPosition(rbox);
                        window.draw(move);
                        possibleMoves[0][0] = a + 1;
                        possibleMoves[0][1] = b - 1;


                    }
                    if ((*(pos + (b - 2) * 8 + a - 2) == 0) && (*(pos + (b - 1) * 8 + a - 1) == 1 || *(pos + (b - 1) * 8 + a - 1) == 3) && comp::compare(b - 2, a - 2, b - 1, a - 1))
                    {

                        sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 2) * 111, static_cast <float>(b - 2) * 111));
                        move.setPosition(lbox);
                        window.draw(move);
                        possibleMoves[1][0] = a - 2;
                        possibleMoves[1][1] = b - 2;
                        multipleMoveBlack(j, a - 2, b - 2, window);

                    }
                    else if (*(pos + (b - 1) * 8 + (a - 1)) == 0 && comp::compare(b - 1, a - 1))
                    {
                        //std::cout << std::endl << "current condition" << std::endl;
                        sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>((a - 1) * 111), static_cast <float>((b - 1) * 111)));
                        move.setPosition(lbox);
                        window.draw(move);
                        possibleMoves[1][0] = a - 1;
                        possibleMoves[1][1] = b - 1;

                    }

                }

                else
                {
                    return false;
                }
                window.display();

                if (pmove(window))
                {
                    return true;
                }
                else
                {
                    return false;
                }
                //std::cout << "Matrix";
                

            }
        }

        //if it is king peice
        else if (*(pos + box.y * 8 + box.x) == 4)
        {
            //std::cout << "seems like king move";
            // //std::cout << "part entered";
            int a = box.x, b = box.y;
            int j = *(pos + (b * 8 + a));


            move.setSize(sf::Vector2f(111, 111));
            //checks for forward move of king
            if (j == 4)
            {
                *pbox = a;
                *(pbox + 1) = b;
                if (a == 0)
                {

                    {
                        if ((*(pos + (b + 2) * 8 + a + 2) == 0) && ((*(pos + (b + 1) * 8 + a + 1) == 1) || (*(pos + (b + 1) * 8 + a + 1) == 3)) && comp::compare(b + 2, a + 2, b + 1, a + 1))
                        {
                            sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>((a + 2) * 111), static_cast <float>((b + 2) * 111)));
                            move.setPosition(rbox);
                            window.draw(move);
                            possibleMoves[3][0] = a + 2;
                            possibleMoves[3][1] = b + 2;
                            multipleMoveBlack(j, a + 2, b + 2, window);
                        }
                        else if (*(pos + (b + 1) * 8 + a + 1) == 0 && comp::compare(a + 1, b + 1))
                        {
                            sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>(a + 1) * 111, static_cast <float>(b + 1) * 111));
                            move.setPosition(rbox);
                            window.draw(move);
                            possibleMoves[3][0] = a + 1;
                            possibleMoves[3][1] = b + 1;
                        }


                        if ((*(pos + (b - 2) * 8 + a + 2) == 0) && (*(pos + (b - 1) * 8 + a + 1) == 1 || *(pos + (b - 1) * 8 + a + 1) == 3) && comp::compare(b - 2, a + 1, b - 1, a + 2))
                        {
                            sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>(a + 2) * 111, static_cast <float>(b - 2) * 111));
                            move.setPosition(rbox);
                            window.draw(move);
                            possibleMoves[0][0] = a + 2;
                            possibleMoves[0][1] = b - 2;
                            multipleMoveBlack(j, a + 2, b - 2, window);
                        }
                        else if ((*(pos + (b - 1) * 8 + a + 1) == 0) && comp::compare(b - 1, a + 1))
                        {
                            sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>(a + 1) * 111, static_cast <float>(b - 1) * 111));
                            move.setPosition(rbox);
                            window.draw(move);
                            possibleMoves[0][0] = a + 1;
                            possibleMoves[0][1] = b - 1;
                        }

                    }
                }
                else if (a == 7)
                {

                    if ((*(pos + (b + 2) * 8 + a - 2) == 0) && (*(pos + (b + 1) * 8 + a - 1) == 1 || *(pos + (b + 1) * 8 + a - 1) == 3) && comp::compare(b + 2, a - 2, b + 1, a - 1))
                    {
                        sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 2) * 111, static_cast <float>(b + 2) * 111));
                        move.setPosition(lbox);
                        window.draw(move);
                        possibleMoves[2][0] = a - 2;
                        possibleMoves[2][1] = b + 2;
                        multipleMoveBlack(j, a - 2, b + 2, window);
                    }
                    else if ((*(pos + (b + 1) * 8 + a - 1) == 0) && comp::compare(b + 1, a - 1))
                    {
                        sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 1) * 111, static_cast <float> (b + 1) * 111));
                        move.setPosition(lbox);
                        window.draw(move);
                        possibleMoves[2][0] = a - 1;
                        possibleMoves[2][1] = b + 1;

                    }

                    if ((*(pos + (b - 2) * 8 + a - 2) == 0) && (*(pos + (b - 1) * 8 + a - 1) == 1 || (*(pos + (b - 1) * 8 + a - 1)) == 3) && comp::compare(b - 2, a - 2, b - 1, a - 1))
                    {
                        sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 2) * 111, static_cast <float>(b - 2) * 111));
                        move.setPosition(lbox);
                        window.draw(move);
                        possibleMoves[1][0] = a - 2;
                        possibleMoves[1][1] = b - 2;
                        multipleMoveBlack(j, a - 2, b - 2, window);

                    }
                    if (*(pos + (b - 1) * 8 + (a - 1)) == 0 && (b - 1 < 8 && b - 1 >= 0 && a - 1 < 8 && a - 1 >= 0) && comp::compare(b - 1, a - 1))
                    {
                        sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>((a - 1) * 111), static_cast <float>((b - 1) * 111)));
                        move.setPosition(lbox);
                        window.draw(move);
                        possibleMoves[1][0] = a - 1;
                        possibleMoves[1][1] = b - 1;
                    }
                }

                else if (comp::compare(a - 1, a + 1))
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
                        return false;
                    }

                    //if a jump in diagonal is possible
                    if ((*(pos + (b + 2) * 8 + a + 2) == 0) && (*(pos + (b + 1) * 8 + a + 1) == 1 || *(pos + (b + 1) * 8 + a + 1) == 3) && comp::compare(b + 2, a + 2, b + 1, a + 1))
                    {
                        sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>((a + 2) * 111), static_cast <float>((b + 2) * 111)));
                        move.setPosition(rbox);
                        window.draw(move);
                        possibleMoves[3][0] = a + 2;
                        possibleMoves[3][1] = b + 2;
                        multipleMoveBlack(j, a + 2, b + 2, window);
                    }
                    //if diagonal move is possible
                    else if (*(pos + (b + 1) * 8 + a + 1) == 0 && comp::compare(b + 1, a + 1))
                    {
                        sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>(a + 1) * 111, static_cast <float> (b + 1) * 111));
                        move.setPosition(rbox);
                        window.draw(move);
                        possibleMoves[3][0] = a + 1;
                        possibleMoves[3][1] = b + 1;

                    }
                    //check if left jump is possible
                    if ((*(pos + (b + 2) * 8 + a - 2) == 0) && (*(pos + (b + 1) * 8 + a - 1) == 1 || *(pos + (b + 1) * 8 + a - 1) == 3) && comp::compare(b + 2, a - 2, b + 1, a - 1))
                    {

                        sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 2) * 111, static_cast <float> (b + 2) * 111));
                        move.setPosition(lbox);
                        window.draw(move);
                        possibleMoves[2][0] = a - 2;
                        possibleMoves[2][1] = b + 2;
                        multipleMoveBlack(j, a - 2, b + 2, window);
                    }
                    //jump left
                    else if ((*(pos + (b + 1) * 8 + a - 1) == 0) && comp::compare(b + 1, a - 1))
                    {
                        sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 1) * 111, static_cast <float> (b + 1) * 111));
                        move.setPosition(lbox);
                        window.draw(move);
                        possibleMoves[2][0] = a - 1;
                        possibleMoves[2][1] = b + 1;

                    }


                    //if white is selected and both diagonals have black.
                    if ((*(pos + (b - 1) * 8 + a + 1) == 2 || *(pos + (b - 1) * 8 + a + 1) == 4) && (*(pos + (b - 1) * 8 + a - 1) == 2 || *(pos + (b - 1) * 8 + a - 1) == 4) && comp::compare(b - 1, a + 1, a - 1, 0))
                    {
                        return false;
                    }



                    //if a jump in diagonal is possible
                    if ((*(pos + (b - 2) * 8 + a + 2) == 0) && (*(pos + (b - 1) * 8 + a + 1) == 1 || *(pos + (b - 1) * 8 + a + 1) == 3) && comp::compare(b - 2, a + 2, b - 1, a + 1))
                    {
                        sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>(a + 2) * 111, static_cast <float> (b - 2) * 111));
                        move.setPosition(rbox);
                        window.draw(move);
                        possibleMoves[0][0] = a + 2;
                        possibleMoves[0][1] = b - 2;
                        multipleMoveBlack(j, a + 2, b - 2, window);
                    }
                    else if ((*(pos + (b - 1) * 8 + a + 1) == 0) && comp::compare(b - 1, a + 1))
                    {
                        sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>(a + 1) * 111, static_cast <float>(b - 1) * 111));
                        move.setPosition(rbox);
                        window.draw(move);
                        possibleMoves[0][0] = a + 1;
                        possibleMoves[0][1] = b - 1;


                    }
                    if ((*(pos + (b - 2) * 8 + a - 2) == 0) && (*(pos + (b - 1) * 8 + a - 1) == 1 || *(pos + (b - 1) * 8 + a - 1) == 3) && comp::compare(b - 2, a - 2, b - 1, a - 1))
                    {

                        sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 2) * 111, static_cast <float>(b - 2) * 111));
                        move.setPosition(lbox);
                        window.draw(move);
                        possibleMoves[1][0] = a - 2;
                        possibleMoves[1][1] = b - 2;
                        multipleMoveBlack(j, a - 2, b - 2, window);
                    }
                    else if (*(pos + (b - 1) * 8 + (a - 1)) == 0 && comp::compare(a - 1, b - 1))
                    {
                        sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>((a - 1) * 111), static_cast <float>((b - 1) * 111)));
                        move.setPosition(lbox);
                        window.draw(move);
                        possibleMoves[1][0] = a - 1;
                        possibleMoves[1][1] = b - 1;

                    }

                }

                else
                {
                    return false;
                }

                window.display();
                for (int i = 0; i < 8; i++)
                {
                    //std::cout << std::endl;
                    for (int j = 0; j < 8; j++)
                    {
                        //std::cout <<(*(abcd.posreset)++);
                    }
                    //std::cout << std::endl;
                }
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





    };
    void multipleMoveBlack(int j, int a, int b, sf::RenderWindow& window)
    {

        //std::cout << std::endl << "Virtal Value" << j << a << b << std::endl;
        int* pos = posreset;


        move.setSize(sf::Vector2f(111, 111));
        ////std::cout << std::endl << a << b;
        *(mulptbox) = a;
        *(mulptbox + 1) = b;
        //std::cout << "Find out the error" << *mulptbox << *(mulptbox + 1) << std::endl;

        if (j == 2)
        {

            //std::cout << std::endl << a << "j" << b << std::endl;

            //std::cout << std::endl << a << b;
            if (a == 7)
            {

                if ((*(pos + (b - 2) * 8 + a - 2) == 0) && (*(pos + (b - 1) * 8 + a - 1) == 1 || (*(pos + (b - 1) * 8 + a - 1)) == 3) && comp::compare(b - 2, a - 2, b - 1, a - 1))
                {

                    sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 2) * 111, static_cast <float>(b - 2) * 111));
                    move.setPosition(lbox);
                    window.draw(move);
                    mulpossibleMoves[1][0] = a - 2;
                    mulpossibleMoves[1][1] = b - 2;


                }
            }
            else if (a == 0)
            {


                if ((*(pos + (b - 2) * 8 + a + 2) == 0) && (*(pos + (b - 1) * 8 + a + 1) == 1 || *(pos + (b - 1) * 8 + a + 1) == 3) && comp::compare(b - 2, a + 2, b - 1, a + 1))
                {
                    sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>(a + 2) * 111, static_cast <float>(b - 2) * 111));
                    move.setPosition(rbox);
                    window.draw(move);
                    mulpossibleMoves[0][0] = a + 2;
                    mulpossibleMoves[0][1] = b - 2;
                }

            }
            else if (a > 0 && a < 7 && b != 0)
            {




                //check for right jump move over white 
                if ((*(pos + (b + 2) * 8 + a + 2) == 0) && (*(pos + (b + 1) * 8 + a + 1) == 2 || *(pos + (b + 1) * 8 + a + 1) == 4) && comp::compare(b + 2, a + 2, b + 1, a + 1))
                {
                    sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>((a + 2) * 111), static_cast <float>((b + 2) * 111)));
                    move.setPosition(rbox);
                    window.draw(move);
                    mulpossibleMoves[1][0] = a + 2;
                    mulpossibleMoves[1][1] = b + 2;


                }

                //if a jump in diagonal is possible
                if ((*(pos + (b - 2) * 8 + a + 2) == 0) && (*(pos + (b - 1) * 8 + a + 1) == 1 || *(pos + (b - 1) * 8 + a + 1) == 3) && comp::compare(b - 2, a + 2, b - 1, a + 1))
                {
                    sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>(a + 2) * 111, static_cast <float> (b - 2) * 111));
                    move.setPosition(rbox);
                    window.draw(move);
                    mulpossibleMoves[0][0] = a + 2;
                    mulpossibleMoves[0][1] = b - 2;

                }

                if ((*(pos + (b - 2) * 8 + a - 2) == 0) && (*(pos + (b - 1) * 8 + a - 1) == 1 || *(pos + (b - 1) * 8 + a - 1) == 3) && comp::compare(b - 2, a - 2, b - 1, a - 1))
                {

                    sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 2) * 111, static_cast <float>(b - 2) * 111));
                    move.setPosition(lbox);
                    window.draw(move);
                    mulpossibleMoves[1][0] = a - 2;
                    mulpossibleMoves[1][1] = b - 2;
                }
            }



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
        if (j == 4)
        {
            if (a == 0)
            {

                if ((*(pos + (b + 2) * 8 + a + 2) == 0) && ((*(pos + (b + 1) * 8 + a + 1) == 1) || (*(pos + (b + 1) * 8 + a + 1) == 3)) && comp::compare(b + 2, a + 2, b + 1, a + 1))
                {
                    //std::cout << "this is checked";
                    sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>((a + 2) * 111), static_cast <float>((b + 2) * 111)));
                    move.setPosition(rbox);
                    window.draw(move);
                    mulpossibleMoves[0][0] = a + 2;
                    mulpossibleMoves[0][1] = b + 2;
                }


                if ((*(pos + (b - 2) * 8 + a + 2) == 0) && (*(pos + (b - 1) * 8 + a + 1) == 1 || *(pos + (b - 1) * 8 + a + 1) == 3) && comp::compare(b - 2, a + 2, b - 1, a + 1))
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
                if ((*(pos + (b - 2) * 8 + a - 2) == 0) && (*(pos + (b - 1) * 8 + a - 1) == 1 || (*(pos + (b - 1) * 8 + a - 1)) == 3) && comp::compare(b - 2, a - 2, b - 1, a - 1))
                {

                    sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 2) * 111, static_cast <float>(b - 2) * 111));
                    move.setPosition(lbox);
                    window.draw(move);
                    mulpossibleMoves[0][0] = a - 2;
                    mulpossibleMoves[0][1] = b - 2;
                }




                if ((*(pos + (b + 2) * 8 + a - 2) == 0) && (*(pos + (b + 1) * 8 + a - 1) == 1 || *(pos + (b + 1) * 8 + a - 1) == 3) && comp::compare(b + 2, a - 2, b + 1, a - 1))
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
                if ((*(pos + (b + 2) * 8 + a + 2) == 0) && (*(pos + (b + 1) * 8 + a + 1) == 1 || *(pos + (b + 1) * 8 + a + 1) == 3) && comp::compare(b + 2, a + 2, b + 1, a + 1))
                {
                    sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>((a + 2) * 111), static_cast <float>((b + 2) * 111)));
                    move.setPosition(rbox);
                    window.draw(move);
                    mulpossibleMoves[0][0] = a + 2;
                    mulpossibleMoves[0][1] = b + 2;
                }

                //check if left jump is possible
                if ((*(pos + (b + 2) * 8 + a - 2) == 0) && (*(pos + (b + 1) * 8 + a - 1) == 1 || *(pos + (b + 1) * 8 + a - 1) == 3) && comp::compare(b + 2, a - 2, b + 1, a - 1))
                {

                    sf::Vector2f lbox(boardPos + sf::Vector2f(static_cast <float>(a - 2) * 111, static_cast <float> (b + 2) * 111));
                    move.setPosition(lbox);
                    window.draw(move);
                    mulpossibleMoves[1][0] = a - 2;
                    mulpossibleMoves[1][1] = b + 2;
                }


                //if a jump in diagonal is possible
                if ((*(pos + (b - 2) * 8 + a + 2) == 0) && (*(pos + (b - 1) * 8 + a + 1) == 1 || *(pos + (b - 1) * 8 + a + 1) == 3) && comp::compare(b - 2, a + 2, b - 1, a + 1))
                {
                    sf::Vector2f rbox(boardPos + sf::Vector2f(static_cast <float>(a + 2) * 111, static_cast <float> (b - 2) * 111));
                    move.setPosition(rbox);
                    window.draw(move);
                    mulpossibleMoves[2][0] = a + 2;
                    mulpossibleMoves[2][1] = b - 2;
                }



                if ((*(pos + (b - 2) * 8 + a - 2) == 0) && (*(pos + (b - 1) * 8 + a - 1) == 1 || *(pos + (b - 1) * 8 + a - 1) == 3) && comp::compare(b - 2, a - 2, b - 1, a - 1))
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
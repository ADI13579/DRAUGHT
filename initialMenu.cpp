#include"Board.h"
#include"Bmove.h"
#include"Wmove.h"
#include"computer.h"
#include"initialMenu.h"
#include"compHard.h"

int pceasy(initialBoard& abcd, sf::RenderWindow& window)
{
    Bmove  blackP;
    Pc_easy white;


    while (window.isOpen())
    {
        std::cout << turn;
        std::cout << "loop" << std::endl;
        if ((turn % 2) == 0)
        {
            std::cout << "call black" << std::endl;
            int a = abcd.checkClick(window);
            if (a == 7)
            {
                return 7;
            }
            if (a == 1 && turn % 2 == 0)
            {
                sf::Vector2i clickPos = abcd.getClickedBox();
                std::cout << std::endl << "call black" << clickPos.x << clickPos.y << std::endl << std::endl;
                if (blackP.blackMove(clickPos, window))
                {
                    //turn++;
                }
            }
        }
        else if (turn % 2 == 1)
        {

            std::cout << "white move" << std::endl << "moved";
            white.makeMoveC(window);
            turn++;
        }
    }
    return 0;
};
int pchard(initialBoard& abcd, sf::RenderWindow& window)
{
    Bmove  blackP;
    Pc_hard white;


    while (window.isOpen())
    {
        std::cout << turn;
        std::cout << "loop" << std::endl;
        if ((turn % 2) == 0)
        {
            std::cout << "call black" << std::endl;
            int a = abcd.checkClick(window);
            if (a == 7)
            {
                return 7;
            }
            if (a == 1 && turn % 2 == 0)
            {
                sf::Vector2i clickPos = abcd.getClickedBox();
                std::cout << std::endl << "call black" << clickPos.x << clickPos.y << std::endl << std::endl;
                if (blackP.blackMove(clickPos, window))
                {
                    //turn++;
                }
            }
        }
        else if (turn % 2 == 1)
        {

            std::cout << "white move" << std::endl << "moved";
            white.makeMoveC(window);
            turn++;
        }
    }
    return 0;
};
int multiplayer(initialBoard& abcd, sf::RenderWindow& window)
{
    Bmove blackPiece;
    Wmove whitePiece;
    while (window.isOpen())
    {
        //newT matrix;
        int b = 0;
        int a = abcd.checkClick(window);
        std::cout << a;
        if (a == 7)
        {
            return 7;
        }
        if (a == 1)
        {
            sf::Vector2i clickPos = abcd.getClickedBox();
            std::cout << std::endl << "call black" << clickPos.x << clickPos.y << std::endl << std::endl;
            blackPiece.blackMove(clickPos, window);
        }
        else if (a == 2)
        {
            sf::Vector2i clickPos = abcd.getClickedBox();
            std::cout << std::endl << "call white" << clickPos.x << clickPos.y << std::endl << std::endl;
            whitePiece.whiteMove(clickPos, window);
        }
    }
};

void initialMenu(sf::RenderWindow &window)
{
    int chk=0;
    turn++;
    initialBoard abcd;
    initMenu initialize(window),*ptr;
    ptr = &initialize;
    int opt=initialize.hover(window);
    initMenu* rules = &initialize;
    abcd.setBoard(window);
    
    std::cout <<"Returned /n /n /n /n"<< opt;
    
    if (opt == 1)
    {
        chk=pchard(abcd, window);
    }
    else if (opt == 2)
    {
        chk=pceasy(abcd, window);
    }
    else if (opt == 3)
    {
        chk = multiplayer(abcd, window);
    }
    if (opt == 5)
    {
        initialize.show_rules();
    }
    if (opt == 6)
    {
       
        window.close();

    }

    if (chk == 7)
    {
        //delete ptr;
        initialMenu(window);
    }
    std::cout<<initialize.hover(window); 
     
}
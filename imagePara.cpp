#include"imagePara.h"
imagePara::imagePara()
{
    //backbtn.move(0, 800);
    Sbuffer.loadFromFile("sounds/jump.ogg");
    jump.setBuffer(Sbuffer);
    std::cout << "called" << std::endl;
    //loading images with constructor
    blackKing.loadFromFile("images/blackKingPiece.png");
    black.loadFromFile("images/blackPiece.png");
    whiteKing.loadFromFile("images/whiteKingPiece.png");
    white.loadFromFile("images/whitePiece.png");

    sblack.setTexture(black);
    sblackKing.setTexture(blackKing);
    swhiteKing.setTexture(whiteKing);
    swhite.setTexture(white);




    board_background.loadFromFile("images/board_background.png");
    board.loadFromFile("images/gboard.png");
    sbck.setTexture(board_background);
    sboard.setTexture(board);

    //fills move with blue color
    move.setFillColor(sf::Color::Blue);

    //this  section formats the text
    sf::Text back;
    gfont.loadFromFile("fonts/gfont.ttf");
    turnMsg.setCharacterSize(50);
    turnMsg.setFont(gfont);
    turnMsg.setPosition(1500, 300);
    back.setFont(gfont);
    back.setCharacterSize(50);
    back.setPosition(0,800);
    back.setString("BACK");



    float xmove = 0;// static_cast <float> (h - 995) / 2;
    float ymove = -90;// static_cast <float> (w - 995) / 2;
    sf::Vector2f move(xmove, ymove);
    sf::Vector2f i11(56, 59);
    boardPos = (move + i11);
};
g++ -c imagePara.cpp board.cpp  initialMenu.cpp main.cpp 
g++  imagePara.o board.o  initialMenu.o main.o -o sfml-app -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app
#include "GameWord.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

GameWord::GameWord()
{
    gridLenght = 15;
    gridHeight = 13;
    setUpInitialState();
    setUpTiles();

}

GameWord::~GameWord()
{
    //dtor
}

void GameWord::setUpInitialState(){
    setUpTiles();
}




void GameWord::setUpTiles(){
    tiles.clear();
    std::vector<GameTile *> Row;
    for(int i = 0; i < gridLenght; i++){
        Row.push_back(new GameTile("res/img/wall.png",50*i,0,false));
    }
    tiles.push_back(Row);
    Row.clear();

    for(int j = 1; j < gridHeight-1; j++){
        Row.push_back(new GameTile("res/img/wall.png",0,j*50,false));
        for(int i = 1; i < gridLenght-1; i++){
            if(i%2 == 0 && j%2==0){
                Row.push_back(new GameTile("res/img/wall.png",50*i,j*50,false));
            }else{
                Row.push_back(new GameTile("res/img/grass.png",50*i,j*50,false));
            }


        }
        Row.push_back(new GameTile("res/img/wall.png",50*(gridLenght-1),j*50,false));
        tiles.push_back(Row);
        Row.clear();
    }

    for(int i = 0; i < gridLenght; i++){
        Row.push_back(new GameTile("res/img/wall.png",50*i,50*(gridHeight-1),false));
    }
    tiles.push_back(Row);

}

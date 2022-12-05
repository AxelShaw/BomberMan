#include "GameWord.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

GameWord::GameWord()
{
    gridLenght = 15;
    gridHeight = 13;
    setUpTiles();
}

GameWord::~GameWord()
{
    //dtor
}


//creation of the map with unbreakable wall and bow and grass
//set up box and garss and wall in tiles
void GameWord::setUpTiles(){
    //set tableau for placemnt of box
    vector<vector<int> > boxplacemnt(gridLenght, vector<int> (gridHeight));
    setUpVectorBox(boxplacemnt);
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
            if(j%2==0){
                if(i%2==0){
                     Row.push_back(new GameTile("res/img/wall.png",50*i,j*50,false));
                }else{
                    if(i==1 || i == gridHeight){
                        Row.push_back(new GameTile("res/img/grass.png",50*i,j*50,true));
                    }else{
                        Row.push_back(new GameTile("res/img/box.png",50*i,j*50,false));
                    }
                }

            }else{
                if(boxplacemnt[i][j] == 1){
                    Row.push_back(new GameTile("res/img/box.png",50*i,j*50,false));
                }else{
                    Row.push_back(new GameTile("res/img/grass.png",50*i,j*50,true));
                }

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

//creation of the map with destructible box
void GameWord::setUpVectorBox(vector<vector<int> >& v){
    for(int i = 1; i < gridLenght-1; i=i+2){
        if(i == 1 || i == gridHeight-2){
            v[3][i] = 1;
            v[4][i] = 1;
            v[6][i] = 1;
            v[8][i] = 1;
            v[9][i] = 1;
            v[10][i] = 1;
            v[11][i] = 1;
        }else{
            if((i+1)%4 == 0){
                v[1][i] = 1;
                v[2][i] = 1;
                v[4][i] = 1;
                v[5][i] = 1;
                v[6][i] = 1;
                v[8][i] = 1;
                v[9][i] = 1;
                v[10][i] = 1;
                v[12][i] = 1;
                v[13][i] = 1;
            }else{
                v[1][i] = 1;
                v[3][i] = 1;
                v[4][i] = 1;
                v[5][i] = 1;
                v[7][i] = 1;
                v[8][i] = 1;
                v[9][i] = 1;
                v[11][i] = 1;
                v[12][i] = 1;
                v[13][i] = 1;
            }
        }
    }
}

//get tiles
vector< vector<GameTile *>> GameWord::getTiles(){
    return tiles;
}


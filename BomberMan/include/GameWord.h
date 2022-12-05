#ifndef GAMEWORD_H
#define GAMEWORD_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include<GameTile.h>
#include<vector>


using namespace sf;


class GameWord
{
    private:
        //inital game world ( 2d)
        void setUpInitialState();
        //set up texture in game world
        void setUpTiles();
        //set up box in game world
        void setUpVectorBox(vector<vector<int> > &v);
        //vector of texture
        vector< vector<GameTile *>> tiles;

    public:
        GameWord();
        virtual ~GameWord();
        int gridLenght;
        int gridHeight;
        //get vector of texture
        vector< vector<GameTile *>> getTiles();
};

#endif // GAMEWORD_H

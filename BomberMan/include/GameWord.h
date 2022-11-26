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
        void setUpInitialState();
        void setUpTiles();
        void setUpVectorBox(vector<vector<int> > &v);
        vector< vector<GameTile *>> tiles;

    public:
        GameWord();
        virtual ~GameWord();
        int gridLenght;
        int gridHeight;
        vector< vector<GameTile *>> getTiles();
};

#endif // GAMEWORD_H

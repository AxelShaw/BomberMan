#ifndef GAMEWORD_H
#define GAMEWORD_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include<GameTile.h>
#include<vector>

using namespace sf;


class GameWord
{
    public:
        GameWord();
        virtual ~GameWord();
        vector< vector<GameTile *>> tiles;
        int gridLenght;
        int gridHeight;

    private:
        void setUpInitialState();
        void setUpTiles();
};

#endif // GAMEWORD_H

#ifndef GAMEWORD_H
#define GAMEWORD_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include<GameTile.h>
#include<vector>
#include<Player.h>

using namespace sf;


class GameWord
{
    public:
        GameWord();
        virtual ~GameWord();
        vector< vector<GameTile *>> tiles;
        vector< vector<Player *>> players;
        int gridLenght;
        int gridHeight;

    private:
        void setUpInitialState();
        void setUpInitialPlayer();

        void setUpTiles();
        void setUpPlayers();

        void setUpVectorBox(vector<vector<int> > &v);

};

#endif // GAMEWORD_H

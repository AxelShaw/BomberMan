#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include<iostream>
#include <SFML/Graphics.hpp>
#include<Bomb.h>

using namespace sf;

using namespace std;


class Player
{
    private:
        int rangeBomb;
        vector<Bomb *> bombs;

    public:
        Player(int rangeBomb);
        virtual ~Player();
        int getRangeBomb();
        void setUpInitialState();
        vector<Bomb *> getBomb();
};

#endif // PLAYER_H

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
        int vie;

    public:
        Player(int rangeBomb, int vie=3);
        virtual ~Player();
        int getRangeBomb();
        void setUpInitialState();
        vector<Bomb *> getBomb();
        int takeDamage();
        int getVie();
};

#endif // PLAYER_H

#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include<iostream>
#include <SFML/Graphics.hpp>
#include<Bomb.h>
#include<Life.h>

using namespace sf;

using namespace std;


class Player
{
    private:
        int rangeBomb;
        vector<Bomb *> bombs;
        vector<Life*> lifes;
        int vie;

    public:
        Player(int rangeBomb, int vie=3);
        virtual ~Player();
        int getRangeBomb();
        void setUpInitialState();
        vector<Bomb *> getBomb();
        vector<Life *> getLife();
        int takeDamage();
        int getVie();
        void setUpLife(int nb);
};

#endif // PLAYER_H

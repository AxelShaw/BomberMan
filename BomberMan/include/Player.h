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
        //set rande bomb and nb life
        Player(int rangeBomb, int vie=3);
        virtual ~Player();
        //get bomb's range of player
        int getRangeBomb();
        //set up initial state of nb bomb
        void setUpInitialState();
        //vector pointer bomb
        vector<Bomb *> getBomb();
        //vector pointer life
        vector<Life *> getLife();
        //function when player get in explosion
        int takeDamage();
        //get player'life
        int getVie();
        //set player's life
        void setUpLife(int nb);
        //add bomb when take bonus in game
        void addBomb();
        //add range when take bonus in game
        void addRangeBomb();
};

#endif // PLAYER_H

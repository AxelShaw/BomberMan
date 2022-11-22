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
        void setUpInitialState();

    public:
        Player();
        virtual ~Player();

        vector<Bomb *> bombs;



};

#endif // PLAYER_H

#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include<iostream>
#include <SFML/Graphics.hpp>


using namespace sf;

using namespace std;


class Player
{


    private:
        int nbVie;
        string Pseudo;
        bool IsAlive;

        Sprite sprite;

    public:
        Player(int nbVie, string Pseudo, bool IsAlive);
        virtual ~Player();
        int getNbVie();




};

#endif // PLAYER_H

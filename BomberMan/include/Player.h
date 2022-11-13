#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include<iostream>

using namespace std;


class Player
{


    private:
        int nbVie;
        int nbBombe;
        string Pseudo;


    public:
        Player(nbVie = 3, int nbBombe = 5, string Pseudo="okok");
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);

        int getNbVie();
        int getNbBombe();

        string str()const

};

#endif // PLAYER_H

#include "Player.h"
#include<string>
#include<iostream>

using namespace std;

Player::Player(int nbVie, int nbBombe, string Pseudo)
{
    this->nbVie=nbVie;
    this->nbBombe=nbBombe;
    this->Pseudo=Pseudo;
}

Player::~Player()
{
    //dtor
}

Player::Player(const Player& other)
{
    //copy ctor
}

Player& Player::operator=(const Player& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


int Player::getNbVie(){
    return nbVie;
}
int Player::getNbBombe(){
    return nbBombe;
}

string Player::str()const
{
    res = "player " + Pseudo;

    return res;
}

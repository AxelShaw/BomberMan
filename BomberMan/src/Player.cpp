#include "Player.h"
#include<string>
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


Player::Player(int nbVie, string Pseudo, bool IsAlive)
{
    this->nbVie=nbVie;
    this->Pseudo=Pseudo;
    this->IsAlive=IsAlive;
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


string Player::str()const
{
    return "test";
}



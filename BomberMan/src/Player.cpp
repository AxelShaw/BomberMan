#include "Player.h"
#include<string>
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


Player::Player(int nbVie, string Pseudo, bool IsAlive)
{
    this->nbVie = nbVie;
    this->Pseudo = Pseudo;
    this->IsAlive = IsAlive;


}


Player::~Player()
{
    //dtor
}


int Player::getNbVie(){
    return nbVie;
}




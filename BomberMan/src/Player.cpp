#include "Player.h"
#include<string>
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


Player::Player(int rangeBomb, int vie)
{
    setUpInitialState();
    this->rangeBomb = rangeBomb;
    this->vie = vie;
}


Player::~Player()
{
}

void Player::setUpInitialState(){
    bombs.push_back(new Bomb("res/img/bomb.png",false));
    bombs.push_back(new Bomb("res/img/bomb.png",false));
}
int Player::getRangeBomb(){
    return rangeBomb;
}

vector<Bomb *> Player::getBomb(){
    return bombs;
}

int Player::takeDamage(){
    return vie - 1;
}

int Player::getVie(){
    return vie;
}





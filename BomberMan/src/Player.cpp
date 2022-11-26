#include "Player.h"
#include<string>
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


Player::Player(int rangeBomb)
{
    setUpInitialState();
    this->rangeBomb = rangeBomb;
}


Player::~Player()
{
    //dtor
}

void Player::setUpInitialState(){
    bombs.push_back(new Bomb("res/img/bomb.png",false));
    bombs.push_back(new Bomb("res/img/bomb.png",false));
}
int Player::getRangeBomb(){
    return rangeBomb;
}





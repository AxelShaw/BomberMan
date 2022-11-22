#include "Player.h"
#include<string>
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


Player::Player()
{
    setUpInitialState();
}


Player::~Player()
{
    //dtor
}

void Player::setUpInitialState(){
    bombs.push_back(new Bomb("res/img/bomb.png",false));
    bombs.push_back(new Bomb("res/img/bomb.png",false));
}





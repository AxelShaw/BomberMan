#include "Player.h"
#include<string>
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


Player::Player(int rangeBomb, int vie)
{
    //initial bomb in player
    setUpInitialState();
    //range bomb for bomb of player
    this->rangeBomb = rangeBomb;
    //set life of player
    this->vie = vie;
}


Player::~Player()
{
}
//initial state of nb bomb in player
void Player::setUpInitialState(){
    bombs.push_back(new Bomb("res/img/bomb.png",false));
}

//add bomb in player when take bonus
void Player::addBomb(){
    bombs.push_back(new Bomb("res/img/bomb.png",false));
}
//get range bomb
int Player::getRangeBomb(){
    return rangeBomb;
}

//add range bomb when player take bonus
void Player::addRangeBomb(){
    rangeBomb += 1;
}

//get player's bomb
vector<Bomb *> Player::getBomb(){
    return bombs;
}

//player take damage
int Player::takeDamage(){
    return vie - 1;
}

//get player's life
int Player::getVie(){
    return vie;
}

//set up life whith spite
void Player::setUpLife(int nb){
    for(int i = 0; i < nb ; i++){
        lifes.push_back(new Life("res/img/heart.png"));
    }
}

//get player's life
vector<Life *> Player::getLife(){
    return lifes;
}






#include "Player.h"
#include<string>
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


Player::Player(string texturePlayer, float x ,float y,int nbVie, string Pseudo, bool IsAlive)
{
    if(!setUpSprite(texturePlayer)){
        //error texture load
    }

    pos = Vector2f(x,y);
    spriteP.setPosition(pos);
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



bool Player::setUpSprite(string textureName){
    if(!texture.loadFromFile(textureName))
    {
        //handler error image
    }
    texture.setSmooth(true);
    spriteP.setTexture(texture);
    spriteP.setTextureRect(IntRect(0,0,50,50));
    return true;
}



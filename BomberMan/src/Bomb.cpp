#include "Bomb.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Game.h>

Bomb::Bomb(string textureName,float x , float y,bool isExplode, int range,int speed)
{
    if(!setUpSprite(textureName)){
        //error texture load
    }

    pos = Vector2f(x,y);
    sprite.setPosition(pos);
    this->isExplode = isExplode;
    this->range = range;
    this->speed = speed;
}

bool Bomb::setUpSprite(string textureName){
    if(!texture.loadFromFile(textureName))
    {
        //handler error image
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0,0,50,50));
    return true;
}

Bomb::~Bomb()
{
    //dtor
}

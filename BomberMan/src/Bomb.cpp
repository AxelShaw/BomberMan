#include "Bomb.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Bomb::Bomb(string textureName, bool place)
{
    if(!setUpSprite(textureName)){
            //error texture load
    }

    sprite.setPosition(-100,-100);

    this->place = place;
}

Bomb::~Bomb()
{
    //dtor
}

bool Bomb::setUpSprite(string textureName){
    if(!texture.loadFromFile(textureName))
        {
            //handler error image
        }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    return true;
}

void Bomb::setPosition(int x , int y){
    sprite.setPosition(x,y);
}

bool Bomb::getPlace(){
    return place;
}
void Bomb::setPlace(bool change){
    place = change;
}

Sprite Bomb::getSprite(){
    return sprite;
}

#include "Bomb.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Bomb::Bomb(string textureName, bool place)
{
    //laod sprite for the bomb
    if(!setUpSprite(textureName)){
            //error texture load
    }

    //set position of the sprite in -100 -100 for not see them
    sprite.setPosition(-100,-100);

    //set if is place or not
    this->place = place;
}

Bomb::~Bomb()
{
    //dtor
}

//for set up the texture and the sprite
bool Bomb::setUpSprite(string textureName){
    // set texxture of the bomb and load in sprite
    if(!texture.loadFromFile(textureName))
        {
            //handler error image
        }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    return true;
}

//set the position of the bomb
void Bomb::setPosition(int x , int y){
    sprite.setPosition(x,y);
}

//take the position of the bomb
bool Bomb::getPlace(){
    return place;
}

//set the boolean for say that bomb is place in the game o not
void Bomb::setPlace(bool change){
    place = change;
}

//gat the sprite od the bomb
Sprite Bomb::getSprite(){
    return sprite;
}

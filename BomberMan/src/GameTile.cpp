#include "GameTile.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

GameTile::GameTile(string textureName,float x,float y,bool passable){
    if(!setUpSprite(textureName)){
        //error texture load
    }

    pos = Vector2f(x,y);
    sprite.setPosition(pos);
    isPassable = passable;
}

GameTile::~GameTile()
{
    //dtor
}

bool GameTile::setUpSprite(string textureName){
    if(!texture.loadFromFile(textureName))
    {
        //handler error image
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0,0,50,50));
    return true;
}

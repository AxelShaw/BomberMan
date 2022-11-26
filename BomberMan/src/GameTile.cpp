#include "GameTile.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

GameTile::GameTile(string textureName,int x,int y,bool passable){
    if(!setUpSprite(textureName)){
        //error texture load
    }

    this->textureName = textureName;

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

bool GameTile::getPassable(){
    return isPassable;
}

string GameTile::getTextureName(){
    return textureName;
}

void GameTile::SetTextureName(){
    textureName = "res/img/grass.png";

    if(!texture.loadFromFile(textureName))
    {
        //handler error image
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0,0,50,50));
    isPassable = true;
}

#include "GameTile.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace sf;

GameTile::GameTile(string textureName,int x,int y,bool passable){
    //setup texture of the game
    if(!setUpSprite(textureName)){
        //error texture load
    }

    this->textureName = textureName;

    //setup position de la texture
    pos = Vector2f(x,y);
    //setup sprite
    sprite.setPosition(pos);
    //if elemnt as collison or not
    isPassable = passable;
}

GameTile::~GameTile()
{
    //dtor
}

//set up the sprite
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

//get the collision
bool GameTile::getPassable(){
    return isPassable;
}

//get the texture
string GameTile::getTextureName(){
    return textureName;
}

//set the texture when explosion and bonus in the game
void GameTile::SetTextureName(){
    int v1 = rand() % 6;

    if(v1 == 0){
        textureName = "res/img/BombBonus.png";
    }else{
        if(v1 == 1){
            textureName = "res/img/RangeBonus.png";
        }else{
            textureName = "res/img/grass.png";
        }
    }

    if(!texture.loadFromFile(textureName))
    {
        //handler error image
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0,0,50,50));
    isPassable = true;
}

//set grass when take bonus
void GameTile::SetTextureGrass(){

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

//get sprite
Sprite GameTile::getSprite(){
    return sprite;
}

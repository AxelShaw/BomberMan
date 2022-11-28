#include "Life.h"

Life::Life(string textureName)
{
    if(!setUpSprite(textureName)){
            //error texture load
    }
}

Life::~Life()
{
    //dtor
}

bool Life::setUpSprite(string textureName){
    if(!texture.loadFromFile(textureName))
        {
            //handler error image
        }
        texture.setSmooth(true);
        sprite.setTexture(texture);
    return true;
}

Sprite Life::getSprite(){
    return sprite;
}

void Life::setPosition(int x , int y){
    sprite.setPosition(x,y);
}

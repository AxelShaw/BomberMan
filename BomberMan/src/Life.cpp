#include "Life.h"

Life::Life(string textureName)
{
    //set texture
    if(!setUpSprite(textureName)){
            //error texture load
    }
}

Life::~Life()
{
    //dtor
}
//set up texture and sprites for life
bool Life::setUpSprite(string textureName){
    if(!texture.loadFromFile(textureName))
        {
            //handler error image
        }
        texture.setSmooth(true);
        sprite.setTexture(texture);
    return true;
}

//get sprite life
Sprite Life::getSprite(){
    return sprite;
}

//set position sprite
void Life::setPosition(int x , int y){
    sprite.setPosition(x,y);
}

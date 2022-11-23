#include "Explosion.h"

Explosion::Explosion()
{
    if(!setUpSprite("res/img/macron_explosion.png")){
            //error texture load
    }

    sprite.setPosition(100,100);
}

Explosion::~Explosion()
{
    //dtor
}

bool Explosion::setUpSprite(string textureName){
    if(!texture.loadFromFile(textureName))
        {
            //handler error image
        }
        texture.setSmooth(true);
        sprite.setTexture(texture);
    return true;
}

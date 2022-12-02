#include "Explosion.h"

Explosion::Explosion()
{
    if(!setUpSprite("res/img/explosion.png")){
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

int Explosion::getXpos(){
    return xpos;
}

void Explosion::setXpos(int x){
    this->xpos = x;
}

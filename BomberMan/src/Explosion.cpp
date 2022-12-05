#include "Explosion.h"

Explosion::Explosion()
{
    //laod sprite for the  explosion
    if(!setUpSprite("res/img/explosion.png")){
            //error texture load
    }
}

Explosion::~Explosion()
{
    //dtor
}

//set up texture and sprite of the explosion
bool Explosion::setUpSprite(string textureName){
    if(!texture.loadFromFile(textureName))
        {
            //handler error image
        }
        texture.setSmooth(true);
        sprite.setTexture(texture);
    return true;
}

//get the position of the explosion
int Explosion::getXpos(){
    return xpos;
}

//set the posision in the axe X for done animation
void Explosion::setXpos(int x){
    this->xpos = x;
}

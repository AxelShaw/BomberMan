#ifndef EXPLOSION_H
#define EXPLOSION_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Game.h>

using namespace sf;
using namespace std;


class Explosion
{
    private:
        Texture texture;
        int xpos=0;

    public:
        Explosion();
        virtual ~Explosion();
        //set up texture and sprite
        bool setUpSprite(string textureName);
        Sprite sprite;
        //clock time for explosion animation
        Clock clock;
        //time next animation time
        Time anime = milliseconds(50);
        //get pos X in image
        int getXpos();
        //set pos x in image
        void setXpos(int x);
};

#endif // EXPLOSION_H

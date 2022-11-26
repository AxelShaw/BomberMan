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
        bool setUpSprite(string textureName);
        Sprite sprite;
        Clock clock;
        Time anime = milliseconds(50);
        int getXpos();
        void setXpos(int x);
};

#endif // EXPLOSION_H

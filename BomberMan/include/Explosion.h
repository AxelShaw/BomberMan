#ifndef EXPLOSION_H
#define EXPLOSION_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Game.h>

using namespace sf;
using namespace std;


class Explosion
{
    public:
        Explosion();
        virtual ~Explosion();
        bool setUpSprite(string textureName);
        Sprite sprite;

        Clock clock;
        int xpos=0;

        Time anime = milliseconds(50);

    private:
        Texture texture;
};

#endif // EXPLOSION_H

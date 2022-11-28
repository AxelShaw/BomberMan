#ifndef LIFE_H
#define LIFE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Game.h>

class Life
{
    private:
        Texture texture;
        bool place;
        Sprite sprite;
    public:
        Life(string textureName);
        virtual ~Life();
        bool setUpSprite(string textureName);
        Sprite getSprite();
        void setPosition(int x , int y);
};

#endif // LIFE_H

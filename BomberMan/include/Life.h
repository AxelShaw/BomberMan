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
    //texture life
        Life(string textureName);
        virtual ~Life();
        //set up texture life
        bool setUpSprite(string textureName);
        //get life's sprite
        Sprite getSprite();
        //set position sprite's life
        void setPosition(int x , int y);
};

#endif // LIFE_H

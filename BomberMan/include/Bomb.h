#ifndef BOMB_H
#define BOMB_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Game.h>

using namespace sf;
using namespace std;


class Bomb
{
    private:
        Texture texture;
        bool place;
        Sprite sprite;

    public:
        Bomb(string textureName, bool place);
        virtual ~Bomb();
        bool setUpSprite(string textureName);
        Sprite getSprite();
        void setPosition(int x , int y);
        bool getPlace();
        void setPlace(bool change);
        Clock clock;
};

#endif // BOMB_H

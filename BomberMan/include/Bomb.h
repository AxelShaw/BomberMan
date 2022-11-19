#ifndef BOMB_H
#define BOMB_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Game.h>

using namespace sf;



using namespace sf;
using namespace std;


class Bomb
{
    public:
        Bomb(string textureName,float x,float y,bool isExplode, int range,int speed);
        virtual ~Bomb();
        bool setUpSprite(string textureName);
        Sprite sprite;

    private:

        int range;
        bool isExplode;
        Vector2f pos;
        Texture texture;
        int speed;
};

#endif // BOMB_H

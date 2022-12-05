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
        //set texture and pce or not
        Bomb(string textureName, bool place);
        virtual ~Bomb();
        //setup sprite
        bool setUpSprite(string textureName);
        //get sprite
        Sprite getSprite();
        //set sprite's position
        void setPosition(int x , int y);
        //get place
        bool getPlace();
        //set place
        void setPlace(bool change);
        //clock time
        Clock clock;
};

#endif // BOMB_H

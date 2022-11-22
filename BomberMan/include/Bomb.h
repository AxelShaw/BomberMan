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
        Bomb(string textureName, bool place);
        virtual ~Bomb();
        bool setUpSprite(string textureName);
        Sprite sprite;
        void setPosition(int x , int y);

        bool getPlace();
        void setPlace(bool change);

        Clock clock;


    private:
        Texture texture;
        bool place;


};

#endif // BOMB_H

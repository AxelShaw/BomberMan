#ifndef GAMETILE_H
#define GAMETILE_H
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


class GameTile
{
    public:
        GameTile(string textureName,float x,float y,bool passable);
        virtual ~GameTile();
        bool setUpSprite(string textureName);
        Sprite sprite;

    private:
        Vector2f pos;
        Texture texture;
        bool isPassable;
};

#endif // GAMETILE_H

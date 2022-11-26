#ifndef GAMETILE_H
#define GAMETILE_H
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


class GameTile
{
    public:
        GameTile(string textureName,int x,int y,bool passable);
        virtual ~GameTile();
        bool setUpSprite(string textureName);
        Sprite sprite;
        bool getPassable();
        string getTextureName();
        void SetTextureName();

    private:
        Vector2f pos;
        Texture texture;
        bool isPassable;
        string textureName;
};

#endif // GAMETILE_H

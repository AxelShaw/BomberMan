#ifndef GAMETILE_H
#define GAMETILE_H
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


class GameTile
{
    private:
        Vector2f pos;
        Texture texture;
        bool isPassable;
        string textureName;
        Sprite sprite;

    public:
        //set texture and position ( x, y ) ans if as colison or not
        GameTile(string textureName,int x,int y,bool passable);
        virtual ~GameTile();µ
        //setup sprite texture
        bool setUpSprite(string textureName);
        //get sprite
        Sprite getSprite();
        //get collision or not
        bool getPassable();
        //get texture name
        string getTextureName();
        //set texture name when box explose
        void SetTextureName();
        //set texture in grass when bonus was taken
        void SetTextureGrass();
};

#endif // GAMETILE_H

#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include<iostream>
#include <SFML/Graphics.hpp>


using namespace sf;

using namespace std;


class Player
{


    private:
        Vector2f pos;
        int nbVie;
        string Pseudo;
        bool IsAlive;
        Texture texture;

    public:
        Player(string texturePlayer,float x,float y,int nbVie, string Pseudo, bool IsAlive);
        virtual ~Player();
        bool setUpSprite(string textureName);
        int getNbVie();
        Sprite spriteP;


};

#endif // PLAYER_H

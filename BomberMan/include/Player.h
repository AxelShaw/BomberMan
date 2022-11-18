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
        int nbVie;
        string Pseudo;
        bool IsAlive;
        Texture texture;
        bool up;
        bool down;
        bool right;
        bool left;
        Sprite spriteP;

    public:
        Player(Sprite spriteP,int nbVie, string Pseudo, bool IsAlive);
        virtual ~Player();
        bool setUpSprite(string textureName);
        int getNbVie();
        void processEvents(Keyboard key, bool checkPressed );
        void update();




};

#endif // PLAYER_H

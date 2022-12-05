#ifndef GAME_H
#define GAME_H
#include<string>
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<Explosion.h>
#include<GameWord.h>

using namespace sf;
using namespace std;

class Explosion;

class Game
{
    private:
        float velocity = 3;
        FloatRect nextPos;
        Music music;

    public:
        Game();
        virtual ~Game();
        Game(const Game& other);
        Game& operator=(const Game& other);
        //launch game window
        void launchGame(RenderWindow& window);
        //set image and music for players
        void setImage();
        //set movement for players
        void setMouvement();
        //create explosion for bomb
        void createExplosion(int x, int y, int range);
        //liste de pointeur d'explosion
        vector<Explosion *> EploP;
        //time after explosion start
        Time secondEndBomb = seconds(2);
        //time after end animation bomb
        Time secondEndExp = milliseconds(350);
        //if player is touch by explosion
        void PlayerTouch();
        //create gameword
        GameWord gameWord = GameWord();
        //start menu whit window
        void StartMenu(RenderWindow& window);
};

#endif // GAME_H

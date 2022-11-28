#ifndef GAME_H
#define GAME_H
#include<string>
#include<iostream>
#include <SFML/Graphics.hpp>
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

    public:
        Game();
        virtual ~Game();
        Game(const Game& other);
        Game& operator=(const Game& other);
        void launchGame(RenderWindow& window);
        void setImage();
        void setPlayer();
        void MoveUp(Sprite spritePs);
        void MoveDown(Sprite spritePs);
        void MoveRight(Sprite spritePs);
        void MoveLeft(Sprite spritePs);
        void setMouvement();
        void createExplosion(int x, int y, int range);
        vector<Explosion *> EploP;
        Time secondEndBomb = seconds(2);
        Time secondEndExp = milliseconds(350);
        void PlayerTouch();
        GameWord gameWord = GameWord();
};

#endif // GAME_H

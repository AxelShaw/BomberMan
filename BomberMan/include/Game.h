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

        void setMouvement(GameWord gameWord);

        void createExplosion(int x, int y, GameWord gameWord, int range);

        vector<Explosion *> EploP;

        Time secondEndBomb = seconds(5);

        Time secondEndExp = milliseconds(350);


    private:
        float velocity = 3;
        FloatRect nextPos;
};

#endif // GAME_H

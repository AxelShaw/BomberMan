#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include<vector>
#include<Player.h>

using namespace sf;
using namespace std;

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

    private:
        Player* player;
};

#endif // GAME_H

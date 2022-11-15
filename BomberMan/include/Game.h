#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Game
{
    public:
        Game();
        virtual ~Game();
        Game(const Game& other);
        Game& operator=(const Game& other);

        void launchGame(RenderWindow& window);

        void setImage();

    protected:

    private:
};

#endif // GAME_H

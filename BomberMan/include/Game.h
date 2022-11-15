#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <iostream>


class Game
{


    private:
        sf::RenderWindow* window;
        sf::Event event;
        sf::VideoMode vdMode;

        void initVariables();
        void initWindow();

    public:
        Game();
        virtual ~Game();
        Game(const Game& other);
        Game& operator=(const Game& other);

        const bool getWindowIsOpen() const;


        void pollEvent();
        void update();
        void render();


};

#endif // GAME_H

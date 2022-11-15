#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Texture wallTexture;
Sprite wallSprite;

Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}

Game::Game(const Game& other)
{
    //copy ctor
}

Game& Game::operator=(const Game& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void Game::launchGame(RenderWindow& window)
{
    // 60fps
    window.setFramerateLimit(60);

    setImage();

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if(event.type == Event::Closed){
                    window.close();
            }
        }

        window.clear();
        window.draw(wallSprite);
        window.display();
    }
}

void Game::setImage(){

    if(!wallTexture.loadFromFile("res/img/wall.png"))
    {
        //handler error image
    }

    wallSprite.setTexture(wallTexture);
}

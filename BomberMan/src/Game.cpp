#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include<GameWord.h>
#include<Player.h>

using namespace sf;

Texture wallTexture;
Texture playerTexture;
Sprite wallSprite;
Sprite playerSprite;

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

    GameWord gameWord = GameWord();

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
        for(int i = 0 ; i<gameWord.gridHeight; i++){
            for(int j = 0 ; j<gameWord.gridLenght; j++){
                window.draw(gameWord.tiles[i][j]->sprite);

            }
        }

        window.draw(gameWord.players[50][200]->spriteP);




        window.display();
    }
}

void Game::setImage(){

    if(!wallTexture.loadFromFile("res/img/wall.png"))
    {
        //handler error image
    }
    if(!playerTexture.loadFromFile("res/img/player.png"))
    {
        //handler error image
    }

    wallSprite.setTexture(wallTexture);
    playerSprite.setTexture(playerTexture);
}

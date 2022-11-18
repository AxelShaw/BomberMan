#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include<GameWord.h>
#include<Player.h>

using namespace sf;

Texture wallTexture;
Texture playerTexture;

Sprite wallSprite;
Sprite spriteP;

Game::Game()
{
    setUpPlayers();
    setUpInitialPlayer();

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
void Game::setUpPlayers(){

}

void Game::setUpInitialPlayer(){
    setUpPlayers();
}

void Game::launchGame(RenderWindow& window)
{

    if(!playerTexture.loadFromFile("res/img/player.png"))
    {
        //handler error image
    }

    spriteP.setTexture(playerTexture);



    // 60fps
    window.setFramerateLimit(60);

    setImage();

    GameWord gameWord = GameWord();
    Game game = Game();




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

        Player player(spriteP,3,"P1",true);
        spriteP.setPosition(Vector2f(0,0));
        window.draw(spriteP);
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
    spriteP.setTexture(playerTexture);
}

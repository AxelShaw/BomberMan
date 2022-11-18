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

    if(!playerTexture.loadFromFile("res/img/player.png"))
    {
        //handler error image
    }

    spriteP.setTexture(playerTexture);

    Player player(spriteP,3,"P1",true);
    spriteP.setPosition(Vector2f(0,0));



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
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Up)
                {
                    MoveUp();
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    MoveDown();
                }
                if (event.key.code == sf::Keyboard::Right)
                {
                    MoveRight();
                }
                if (event.key.code == sf::Keyboard::Left)
                {
                    MoveLeft();
                }
            }

        }

        window.clear();

        for(int i = 0 ; i<gameWord.gridHeight; i++){
            for(int j = 0 ; j<gameWord.gridLenght; j++){
                window.draw(gameWord.tiles[i][j]->sprite);

            }
        }


        window.draw(spriteP);
        window.display();
    }
}
void Game::MoveDown(){
    Vector2f movement;
    movement.y +=5.0;

    player->getSprite().move(movement);
}
void Game::MoveUp(){
    Vector2f movement;
    movement.y -=5.0;

    player->getSprite().move(movement);
}

void Game::MoveRight(){
    Vector2f movement;
    movement.x +=5.0;

    player->getSprite().move(movement);

}
void Game::MoveLeft(){
    Vector2f movement;
    movement.x -=5.0;

    player->getSprite().move(movement);

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

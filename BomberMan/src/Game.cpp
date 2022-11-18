#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include<GameWord.h>
#include<Player.h>

using namespace sf;

Texture wallTexture;
Texture playerTexture1;
Texture playerTexture2;

Sprite wallSprite;
Sprite spriteP1;
Sprite spriteP2;

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
    // 60fps
    window.setFramerateLimit(60);

    setImage();

    Player player1(3,"P1",true);

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

        if(Keyboard::isKeyPressed(Keyboard::Up)){
            Vector2f movement;
            movement.y -=3.5;
            spriteP1.move(movement);
        }
        if(Keyboard::isKeyPressed(Keyboard::Down)){
            Vector2f movement;
            movement.y +=3.5;
            spriteP1.move(movement);
        }
        if(Keyboard::isKeyPressed(Keyboard::Right)){
            Vector2f movement;
            movement.x +=3.5;
            spriteP1.move(movement);
        }
        if(Keyboard::isKeyPressed(Keyboard::Left)){
            Vector2f movement;
            movement.x -=3.5;
            spriteP1.move(movement);
        }

        if(Keyboard::isKeyPressed(Keyboard::Z)){
            Vector2f movement;
            movement.y -=3.5;
            spriteP2.move(movement);
        }
        if(Keyboard::isKeyPressed(Keyboard::S)){
            Vector2f movement;
            movement.y +=3.5;
            spriteP2.move(movement);
        }
        if(Keyboard::isKeyPressed(Keyboard::D)){
            Vector2f movement;
            movement.x +=3.5;
            spriteP2.move(movement);
        }
        if(Keyboard::isKeyPressed(Keyboard::Q)){
            Vector2f movement;
            movement.x -=3.5;
            spriteP2.move(movement);
        }

        window.clear();

        for(int i = 0 ; i<gameWord.gridHeight; i++){
            for(int j = 0 ; j<gameWord.gridLenght; j++){
                window.draw(gameWord.tiles[i][j]->sprite);

            }
        }

        window.draw(spriteP1);
        window.draw(spriteP2);
        window.display();
    }
}

void Game::setImage(){

    if(!wallTexture.loadFromFile("res/img/wall.png"))
    {
        //handler error image
    }
    if(!playerTexture1.loadFromFile("res/img/player.png"))
    {
        //handler error image
    }

    if(!playerTexture2.loadFromFile("res/img/player.png"))
    {
        //handler error image
    }

    wallSprite.setTexture(wallTexture);
    spriteP1.setTexture(playerTexture1);
    spriteP1.setPosition(55,55);

    spriteP2.setTexture(playerTexture2);
    spriteP2.setPosition(655,555);

}

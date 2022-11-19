#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include<GameWord.h>
#include<Player.h>

using namespace sf;

Texture playerTexture1;
Texture playerTexture2;
Texture bombTexture;
Texture bombTexture2;

Sprite spriteP1;
Sprite spriteP2;
Sprite spriteBomb;
Sprite spriteBomb2;

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
            if(Keyboard::isKeyPressed(Keyboard::Escape)){
                window.close();
            }
        }

        setMouvement(gameWord);

        if(Keyboard::isKeyPressed(Keyboard::Space)){
            for(int i = 0 ; i<gameWord.gridHeight; i++){
                for(int j = 0 ; j<gameWord.gridLenght; j++){
                    if(spriteP1.getGlobalBounds().intersects(gameWord.tiles[i][j]->sprite.getGlobalBounds())){
                        spriteBomb.setPosition(gameWord.tiles[i][j]->sprite.getPosition().x,gameWord.tiles[i][j]->sprite.getPosition().y);
                    }
                }
            }
        }
        if(Keyboard::isKeyPressed(Keyboard::M)){
            for(int i = 0 ; i<gameWord.gridHeight; i++){
                for(int j = 0 ; j<gameWord.gridLenght; j++){
                    if(spriteP2.getGlobalBounds().intersects(gameWord.tiles[i][j]->sprite.getGlobalBounds())){
                        spriteBomb2.setPosition(gameWord.tiles[i][j]->sprite.getPosition().x,gameWord.tiles[i][j]->sprite.getPosition().y);
                    }
                }
            }
        }

        window.clear();

        for(int i = 0 ; i<gameWord.gridHeight; i++){
            for(int j = 0 ; j<gameWord.gridLenght; j++){
                window.draw(gameWord.tiles[i][j]->sprite);
            }
        }

        window.draw(spriteBomb);
        window.draw(spriteBomb2);
        window.draw(spriteP1);
        window.draw(spriteP2);
        window.display();
    }
}

void Game::setImage(){

    if(!playerTexture1.loadFromFile("res/img/player.png"))
    {
        //handler error image
    }

    if(!playerTexture2.loadFromFile("res/img/player.png"))
    {
        //handler error image
    }
    if(!bombTexture.loadFromFile("res/img/bomb.png"))
    {
        //handler error image
    }

    if(!bombTexture2.loadFromFile("res/img/bomb.png"))
    {
        //handler error image
    }

    spriteP1.setTexture(playerTexture1);
    spriteP1.setPosition(55,55);

    spriteP2.setTexture(playerTexture2);
    spriteP2.setPosition(655,555);

    spriteBomb.setTexture(bombTexture);
    spriteBomb.setPosition(-100,-100);

    spriteBomb2.setTexture(bombTexture2);
    spriteBomb2.setPosition(-100,-100);


}

void Game::setMouvement(GameWord gameWord){
    Vector2f movement2;
    if(Keyboard::isKeyPressed(Keyboard::Up)){
        movement2.y -=velocity;
    }
    if(Keyboard::isKeyPressed(Keyboard::Down)){
        movement2.y +=velocity;
    }
    if(Keyboard::isKeyPressed(Keyboard::Right)){
        movement2.x +=velocity;
    }
    if(Keyboard::isKeyPressed(Keyboard::Left)){
        movement2.x -=velocity;
    }

    for(int i = 0 ; i<gameWord.gridHeight; i++){
        for(int j = 0 ; j<gameWord.gridLenght; j++){
            if(!gameWord.tiles[i][j]->getPassable()){
                FloatRect playerBounds = spriteP2.getGlobalBounds();
                FloatRect wallBounds = gameWord.tiles[i][j]->sprite.getGlobalBounds();
                nextPos = playerBounds;
                nextPos.left += movement2.x;
                nextPos.top += movement2.y;
                if(wallBounds.intersects(nextPos)){
                    movement2.x = 0;
                    movement2.y = 0;
                }
            }
        }
    }
    spriteP2.move(movement2);

    Vector2f movement;
    if(Keyboard::isKeyPressed(Keyboard::Z)){
        movement.y -=velocity;
    }
    if(Keyboard::isKeyPressed(Keyboard::S)){
        movement.y +=velocity;
    }
    if(Keyboard::isKeyPressed(Keyboard::D)){
        movement.x +=velocity;
    }
    if(Keyboard::isKeyPressed(Keyboard::Q)){
        movement.x -=velocity;
    }

    for(int i = 0 ; i<gameWord.gridHeight; i++){
        for(int j = 0 ; j<gameWord.gridLenght; j++){
            if(!gameWord.tiles[i][j]->getPassable()){
                FloatRect playerBounds = spriteP1.getGlobalBounds();
                FloatRect wallBounds = gameWord.tiles[i][j]->sprite.getGlobalBounds();
                nextPos = playerBounds;
                nextPos.left += movement.x;
                nextPos.top += movement.y;
                if(wallBounds.intersects(nextPos)){
                    movement.x = 0;
                    movement.y = 0;
                }
            }
        }
    }
    spriteP1.move(movement);
}

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include<GameWord.h>
#include<Player.h>

using namespace sf;

Texture playerTexture1;
Texture playerTexture2;

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

    GameWord gameWord = GameWord();

    Player player1 = Player();
    Player player2 = Player();

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

            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Space)
                {
                    for(int i = 0 ; i<gameWord.gridHeight; i++){
                       for(int j = 0 ; j<gameWord.gridLenght; j++){
                            for(int k = 0 ; k<player1.bombs.size(); k++){
                                if(spriteP1.getGlobalBounds().intersects(gameWord.tiles[i][j]->sprite.getGlobalBounds()) && player1.bombs[k]->getPlace() == false){
                                    player1.bombs[k]->setPosition(gameWord.tiles[i][j]->sprite.getPosition().x,gameWord.tiles[i][j]->sprite.getPosition().y);
                                    player1.bombs[k]->setPlace(true);
                                    player1.bombs[k]->clock.restart();
                                    goto jump1;
                                }
                            }
                        }
                    }
                    jump1:;
                }

                if (event.key.code == Keyboard::M)
                {
                    for(int i = 0 ; i<gameWord.gridHeight; i++){
                       for(int j = 0 ; j<gameWord.gridLenght; j++){
                            for(int k = 0 ; k<player2.bombs.size(); k++){
                                if(spriteP2.getGlobalBounds().intersects(gameWord.tiles[i][j]->sprite.getGlobalBounds()) && player2.bombs[k]->getPlace() == false){
                                    player2.bombs[k]->setPosition(gameWord.tiles[i][j]->sprite.getPosition().x,gameWord.tiles[i][j]->sprite.getPosition().y);
                                    player2.bombs[k]->setPlace(true);
                                    player2.bombs[k]->clock.restart();
                                    goto jump2;
                                }
                            }
                        }
                    }
                    jump2:;
                }
            }
        }

        setMouvement(gameWord);

        window.clear();

        for(int i = 0 ; i<gameWord.gridHeight; i++){
            for(int j = 0 ; j<gameWord.gridLenght; j++){
                window.draw(gameWord.tiles[i][j]->sprite);
            }
        }

        for(int i = 0 ; i<player1.bombs.size(); i++){
            if(player1.bombs[i]->clock.getElapsedTime() > secondEndBomb && player1.bombs[i]->getPlace() == true){
                createExplosion(player1.bombs[i]->sprite.getPosition().x,player1.bombs[i]->sprite.getPosition().y);
                player1.bombs[i]->setPlace(false);
                player1.bombs[i]->setPosition(-100,-100);
            }
            window.draw(player1.bombs[i]->sprite);
        }


        for(int i = 0 ; i<player2.bombs.size(); i++){
            if(player2.bombs[i]->clock.getElapsedTime() > secondEndBomb && player2.bombs[i]->getPlace() == true){
                createExplosion(player2.bombs[i]->sprite.getPosition().x,player2.bombs[i]->sprite.getPosition().y);
                player2.bombs[i]->setPlace(false);
                player2.bombs[i]->setPosition(-100,-100);
            }
            window.draw(player2.bombs[i]->sprite);
        }

        for(int i=0; i < EploP1.size() ; i++){
            window.draw(EploP1[i]->sprite);
            if(EploP1[i]->clock.getElapsedTime() > secondEndExp){
                EploP1.erase(EploP1.begin() + i);
            }else{
                if(EploP1[i]->clock.getElapsedTime() > EploP1[i]->anime){
                    EploP1[i]->xpos = EploP1[i]->xpos + 50;
                    EploP1[i]->sprite.setTextureRect(IntRect(EploP1[i]->xpos,0,50,50));
                    EploP1[i]->anime = EploP1[i]->anime + milliseconds(50);
                }

            }
        }

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

    spriteP1.setTexture(playerTexture1);
    spriteP1.setPosition(55,55);

    spriteP2.setTexture(playerTexture2);
    spriteP2.setPosition(655,555);

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

void Game::createExplosion(int x, int y){


    EploP1.push_back(new Explosion());
    EploP1[EploP1.size()-1]->sprite.setPosition(x,y);
    EploP1[EploP1.size()-1]->sprite.setTextureRect(IntRect(EploP1[EploP1.size()-1]->xpos,0,50,50));
    EploP1[EploP1.size()-1]->clock.restart();

}

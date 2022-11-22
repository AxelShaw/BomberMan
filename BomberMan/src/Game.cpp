#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include<GameWord.h>
#include<Player.h>

using namespace sf;

Texture playerTexture1;
Texture playerTexture2;
Texture exploTexture;

Sprite spriteP1;
Sprite spriteP2;
Sprite spriteExplo;

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

    int xpos = 0 ;
    Clock clock50mS;
    Time time50mS;
    clock50mS.restart();
    double m50s;

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
            window.draw(player1.bombs[i]->sprite);
        }

        for(int i = 0 ; i<player2.bombs.size(); i++){
            window.draw(player2.bombs[i]->sprite);
        }


        time50mS = clock50mS.getElapsedTime();
         m50s = time50mS.asMilliseconds();

        window.draw(spriteP1);
        window.draw(spriteP2);

        window.draw(spriteExplo);

        if(m50s > 50){
            xpos+= 50;
            if(xpos>= 350){
                xpos=0;

            }
            spriteExplo.setTextureRect(IntRect(xpos,0,50,50));
            clock50mS.restart();
        }

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
    if(!exploTexture.loadFromFile("res/img/macron_explosion.png")){
        //handler error image
    }

    spriteP1.setTexture(playerTexture1);
    spriteP1.setPosition(55,55);

    spriteP2.setTexture(playerTexture2);
    spriteP2.setPosition(655,555);

    spriteExplo.setTexture(exploTexture);
    spriteExplo.setTextureRect(IntRect(0,0,50,50));
    spriteExplo.setPosition(300,300);

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

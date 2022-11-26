#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
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

    Player player1 = Player(1);
    Player player2 = Player(1);

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
                            for(int k = 0 ; k<player1.getBomb().size(); k++){
                                if(spriteP1.getGlobalBounds().intersects(gameWord.getTiles()[i][j]->getSprite().getGlobalBounds()) && player1.getBomb()[k]->getPlace() == false){
                                    player1.getBomb()[k]->setPosition(gameWord.getTiles()[i][j]->getSprite().getPosition().x,gameWord.getTiles()[i][j]->getSprite().getPosition().y);
                                    player1.getBomb()[k]->setPlace(true);
                                    player1.getBomb()[k]->clock.restart();
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
                            for(int k = 0 ; k<player2.getBomb().size(); k++){
                                if(spriteP2.getGlobalBounds().intersects(gameWord.getTiles()[i][j]->getSprite().getGlobalBounds()) && player2.getBomb()[k]->getPlace() == false){
                                    player2.getBomb()[k]->setPosition(gameWord.getTiles()[i][j]->getSprite().getPosition().x,gameWord.getTiles()[i][j]->getSprite().getPosition().y);
                                    player2.getBomb()[k]->setPlace(true);
                                    player2.getBomb()[k]->clock.restart();
                                    goto jump2;
                                }
                            }
                        }
                    }
                    jump2:;
                }
            }
        }

        setMouvement();

        window.clear();

        for(int i = 0 ; i<gameWord.gridHeight; i++){
            for(int j = 0 ; j<gameWord.gridLenght; j++){
                window.draw(gameWord.getTiles()[i][j]->getSprite());
            }
        }

        for(int i = 0 ; i<player1.getBomb().size(); i++){
            if(player1.getBomb()[i]->clock.getElapsedTime() > secondEndBomb && player1.getBomb()[i]->getPlace() == true){
                createExplosion(player1.getBomb()[i]->getSprite().getPosition().x,player1.getBomb()[i]->getSprite().getPosition().y, player1.getRangeBomb());
                player1.getBomb()[i]->setPlace(false);
                player1.getBomb()[i]->setPosition(-100,-100);
            }
            window.draw(player1.getBomb()[i]->getSprite());
        }


        for(int i = 0 ; i<player2.getBomb().size(); i++){
            if(player2.getBomb()[i]->clock.getElapsedTime() > secondEndBomb && player2.getBomb()[i]->getPlace() == true){
                createExplosion(player2.getBomb()[i]->getSprite().getPosition().x,player2.getBomb()[i]->getSprite().getPosition().y, player2.getRangeBomb());
                player2.getBomb()[i]->setPlace(false);
                player2.getBomb()[i]->setPosition(-100,-100);
            }
            window.draw(player2.getBomb()[i]->getSprite());
        }

        window.draw(spriteP1);
        window.draw(spriteP2);

        for(int i=0; i < EploP.size() ; i++){
            window.draw(EploP[i]->sprite);
            if(EploP[i]->clock.getElapsedTime() > secondEndExp){
                EploP.erase(EploP.begin() + i);
            }else{
                if(EploP[i]->clock.getElapsedTime() > EploP[i]->anime){
                    EploP[i]->setXpos(EploP[i]->getXpos() + 50);
                    EploP[i]->sprite.setTextureRect(IntRect(EploP[i]->getXpos(),0,50,50));
                    EploP[i]->anime = EploP[i]->anime + milliseconds(50);
                }

            }
            if(spriteP1.getGlobalBounds().intersects(EploP[i]->sprite.getGlobalBounds())){
                PlayerTouch();
                player1 = Player(1);
                player2 = Player(1);
                player2.getBomb().clear();
                player1.getBomb().clear();
                player1.setUpInitialState();
                player2.setUpInitialState();
            }

             if(spriteP2.getGlobalBounds().intersects(EploP[i]->sprite.getGlobalBounds())){
                PlayerTouch();
                player1 = Player(1);
                player2 = Player(1);
                player2.getBomb().clear();
                player1.getBomb().clear();
                player1.setUpInitialState();
                player2.setUpInitialState();
            }

        }

        window.display();

    }
    EploP.clear();
    player2.getBomb().clear();
    player1.getBomb().clear();
    gameWord.getTiles().clear();

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

void Game::setMouvement(){
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
            if(!gameWord.getTiles()[i][j]->getPassable()){
                FloatRect playerBounds = spriteP2.getGlobalBounds();
                FloatRect wallBounds = gameWord.getTiles()[i][j]->getSprite().getGlobalBounds();
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
            if(!gameWord.getTiles()[i][j]->getPassable()){
                FloatRect playerBounds = spriteP1.getGlobalBounds();
                FloatRect wallBounds = gameWord.getTiles()[i][j]->getSprite().getGlobalBounds();
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

void Game::createExplosion(int x, int y, int range){
    bool end1 = false;
    bool end2 = false;
    bool end3 = false;
    bool end4 = false;

    for(int i = 1; i <= range ; i++){
        if(i == 1){
            EploP.push_back(new Explosion());
            EploP[EploP.size()-1]->sprite.setPosition(x,y);
            EploP[EploP.size()-1]->sprite.setTextureRect(IntRect(EploP[EploP.size()-1]->getXpos(),0,50,50));
            EploP[EploP.size()-1]->clock.restart();
        }

        if(y/50+1*i < gameWord.gridHeight && end1 == false){
            if(gameWord.getTiles()[y/50+1*i][x/50]->getTextureName() != "res/img/wall.png"){
                EploP.push_back(new Explosion());
                EploP[EploP.size()-1]->sprite.setPosition(x,y+(50*i));
                EploP[EploP.size()-1]->sprite.setTextureRect(IntRect(EploP[EploP.size()-1]->getXpos(),0,50,50));
                EploP[EploP.size()-1]->clock.restart();
                if(gameWord.getTiles()[y/50+1*i][x/50]->getTextureName() == "res/img/box.png"){
                    gameWord.getTiles()[y/50+1*i][x/50]->SetTextureName();
                }
            }else{
                end1 = true;
            }
        }
        if(y/50-1*i < gameWord.gridHeight && end2 == false){
            if(gameWord.getTiles()[y/50-1*i][x/50]->getTextureName() != "res/img/wall.png"){
                EploP.push_back(new Explosion());
                EploP[EploP.size()-1]->sprite.setPosition(x,y-(50*i));
                EploP[EploP.size()-1]->sprite.setTextureRect(IntRect(EploP[EploP.size()-1]->getXpos(),0,50,50));
                EploP[EploP.size()-1]->clock.restart();
                if(gameWord.getTiles()[y/50-1*i][x/50]->getTextureName() == "res/img/box.png"){
                    gameWord.getTiles()[y/50-1*i][x/50]->SetTextureName();
                }
            }else{
                end2 = true;
            }
        }

        if(x/50+1*i < gameWord.gridLenght && end3 == false){
            if(gameWord.getTiles()[y/50][x/50+1*i]->getTextureName() != "res/img/wall.png"){
                EploP.push_back(new Explosion());
                EploP[EploP.size()-1]->sprite.setPosition(x+(50*i),y);
                EploP[EploP.size()-1]->sprite.setTextureRect(IntRect(EploP[EploP.size()-1]->getXpos(),0,50,50));
                EploP[EploP.size()-1]->clock.restart();
                if(gameWord.getTiles()[y/50][x/50+1*i]->getTextureName() == "res/img/box.png"){
                    gameWord.getTiles()[y/50][x/50+1*i]->SetTextureName();
                }
            }else{
                end3 = true;
            }
        }
        if(x/50-1*i < gameWord.gridLenght && end4 == false){
            if(gameWord.getTiles()[y/50][x/50-1*i]->getTextureName() != "res/img/wall.png"){
                EploP.push_back(new Explosion());
                EploP[EploP.size()-1]->sprite.setPosition(x-(50*i),y);
                EploP[EploP.size()-1]->sprite.setTextureRect(IntRect(EploP[EploP.size()-1]->getXpos(),0,50,50));
                EploP[EploP.size()-1]->clock.restart();
                if(gameWord.getTiles()[y/50][x/50-1*i]->getTextureName() == "res/img/box.png"){
                    gameWord.getTiles()[y/50][x/50-1*i]->SetTextureName();
                }
            }else{
                end4 = true;
            }
        }
    }
}

void Game::PlayerTouch(){
    EploP.clear();
    spriteP1.setPosition(55,55);
    spriteP2.setPosition(655,555);
    gameWord = GameWord();
}

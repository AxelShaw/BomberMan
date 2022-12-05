#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include<Player.h>
#include<Menu.h>
#include<VictoryView.h>



using namespace sf;

//set up texture of player
Texture playerTexture1;
Texture playerTexture2;

//set up sprite of player
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

    //set image of player and music for the game
    setImage();

    //set stat player
    Player player1 = Player(1);
    player1.setUpLife(3);
    Player player2 = Player(1);
    player2.setUpLife(3);


    while (window.isOpen())
    {
        //create event
        Event event;

        while (window.pollEvent(event))
        {
            //close the window when close the window
            if(event.type == Event::Closed){
                window.close();
            }

            //when press escape close the window and stop the music and start the menu
            if(Keyboard::isKeyPressed(Keyboard::Escape)){
                music.stop();
                window.close();
                StartMenu(window);

            }


            if (event.type == Event::KeyPressed)
            {
                //when press delete shut down or power on the music
                if(Keyboard::isKeyPressed(Keyboard::Delete)){

                    if(music.getStatus()==SoundSource::Status::Playing ){
                        music.pause();
                    }
                    else if(music.getStatus()==SoundSource::Status::Paused ){
                        music.play();
                    }

                }

                //when press space draw bomb and start the clock for explosionfor player 1
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

                //when press space draw bomb and start the clock for explosionfor player 2
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

        //set mouvement for player
        setMouvement();


        //clear the window
        window.clear();

        //draw game world ( 2d )
        for(int i = 0 ; i<gameWord.gridHeight; i++){
            for(int j = 0 ; j<gameWord.gridLenght; j++){
                window.draw(gameWord.getTiles()[i][j]->getSprite());
            }
        }

        // draw bomb and set bomb explosion when clock end for player1
        for(int i = 0 ; i<player1.getBomb().size(); i++){
            if(player1.getBomb()[i]->clock.getElapsedTime() > secondEndBomb && player1.getBomb()[i]->getPlace() == true){
                createExplosion(player1.getBomb()[i]->getSprite().getPosition().x,player1.getBomb()[i]->getSprite().getPosition().y, player1.getRangeBomb());
                player1.getBomb()[i]->setPlace(false);
                player1.getBomb()[i]->setPosition(-100,-100);
            }
            window.draw(player1.getBomb()[i]->getSprite());
        }

        // draw bomb and set bomb explosion when clock end for player2
        for(int i = 0 ; i<player2.getBomb().size(); i++){
            if(player2.getBomb()[i]->clock.getElapsedTime() > secondEndBomb && player2.getBomb()[i]->getPlace() == true){
                createExplosion(player2.getBomb()[i]->getSprite().getPosition().x,player2.getBomb()[i]->getSprite().getPosition().y, player2.getRangeBomb());
                player2.getBomb()[i]->setPlace(false);
                player2.getBomb()[i]->setPosition(-100,-100);
            }
            window.draw(player2.getBomb()[i]->getSprite());
        }

        //draw player
        window.draw(spriteP1);
        window.draw(spriteP2);

        //draw explosion and make collision with player
        //if the player touch explosion he lost a life
        for(int i=0; i < EploP.size() ; i++){
            window.draw(EploP[i]->sprite);
            if(EploP[i]->clock.getElapsedTime() > secondEndExp){
                EploP.erase(EploP.begin() + i);
            }else{
                //animation explosion
                if(EploP[i]->clock.getElapsedTime() > EploP[i]->anime){
                    EploP[i]->setXpos(EploP[i]->getXpos() + 50);
                    EploP[i]->sprite.setTextureRect(IntRect(EploP[i]->getXpos(),0,50,50));
                    EploP[i]->anime = EploP[i]->anime + milliseconds(50);
                }

            }
            //set up next game
            if(spriteP1.getGlobalBounds().intersects(EploP[i]->sprite.getGlobalBounds())){
                PlayerTouch();
                player1 = Player(1, player1.takeDamage());
                player2 = Player(1, player2.getVie());
                player2.getBomb().clear();
                player1.getBomb().clear();
                player1.setUpLife(player1.getVie());
                player2.setUpLife(player2.getVie());
            }
            //set up next game
             if(spriteP2.getGlobalBounds().intersects(EploP[i]->sprite.getGlobalBounds())){
                PlayerTouch();
                player1 = Player(1, player1.getVie());
                player2 = Player(1, player2.takeDamage());
                player2.getBomb().clear();
                player1.getBomb().clear();
                player1.setUpLife(player1.getVie());
                player2.setUpLife(player2.getVie());
            }
        }

        //open victory view when the life of the player is equals to 0 for player 1
        if(player1.getVie() == 0){
            window.close();
            music.stop();
            EploP.clear();
            player2.getBomb().clear();
            player1.getBomb().clear();
            gameWord.getTiles().clear();
            RenderWindow windowWin(VideoMode(750, 650), "BomberMan - Win");
            VictoryView victory;
            victory.launchVictory(windowWin,"res/img/P2_v3.png");

        }
        //open victory view when the life of the player is equals to 0 for player 2
        if(player2.getVie() == 0){
            window.close();
            music.stop();
            EploP.clear();
            player2.getBomb().clear();
            player1.getBomb().clear();
            gameWord.getTiles().clear();
            RenderWindow windowWin(VideoMode(750, 650), "BomberMan - Win");
            VictoryView victory;
            victory.launchVictory(windowWin,"res/img/P1_v3.png");
        }

        //draw life player1
        for(int i=0 ;i < player1.getLife().size(); i++){
            player1.getLife()[i]->setPosition(5+50*i,5);
            window.draw(player1.getLife()[i]->getSprite());
        }

        //draw life player1
        for(int i=0 ;i < player2.getLife().size(); i++){
            player2.getLife()[i]->setPosition(605+50*i,605);
            window.draw(player2.getLife()[i]->getSprite());
        }

        //draw bonus in the game
        for(int i = 0 ; i<gameWord.gridHeight; i++){
            for(int j = 0 ; j<gameWord.gridLenght; j++){
                if(gameWord.getTiles()[i][j]->getTextureName() == "res/img/RangeBonus.png" && spriteP1.getGlobalBounds().intersects(gameWord.getTiles()[i][j]->getSprite().getGlobalBounds())){
                    gameWord.getTiles()[i][j]->SetTextureGrass();
                    player1.addRangeBomb();
                }
                if(gameWord.getTiles()[i][j]->getTextureName() == "res/img/BombBonus.png" && spriteP1.getGlobalBounds().intersects(gameWord.getTiles()[i][j]->getSprite().getGlobalBounds())){
                    gameWord.getTiles()[i][j]->SetTextureGrass();
                    player1.addBomb();
                }
                if(gameWord.getTiles()[i][j]->getTextureName() == "res/img/RangeBonus.png" && spriteP2.getGlobalBounds().intersects(gameWord.getTiles()[i][j]->getSprite().getGlobalBounds())){
                    gameWord.getTiles()[i][j]->SetTextureGrass();
                    player2.addRangeBomb();
                }
                if(gameWord.getTiles()[i][j]->getTextureName() == "res/img/BombBonus.png" && spriteP2.getGlobalBounds().intersects(gameWord.getTiles()[i][j]->getSprite().getGlobalBounds())){
                    gameWord.getTiles()[i][j]->SetTextureGrass();
                    player2.addBomb();
                }
            }
        }

        window.display();

    }
    //clear game when stop
    music.stop();
    EploP.clear();
    player2.getBomb().clear();
    player1.getBomb().clear();
    gameWord.getTiles().clear();
}

//load texture for image and music
void Game::setImage(){

    //laod player1 texture
    if(!playerTexture1.loadFromFile("res/img/P1_v3.png"))
    {
        //handler error image
    }
    //loadplayer 2 texture
    if(!playerTexture2.loadFromFile("res/img/P2_v3.png"))
    {
        //handler error image
    }

    //setup music
    if (!music.openFromFile("res/audio/musicbattle.wav")){
    // erreur
    }
    music.play();
    music.setLoop(true);
    music.setVolume(50);


    //setup sprite for player 1 and 2
    spriteP1.setTextureRect(IntRect(0,0,30,35));
    spriteP1.setTexture(playerTexture1);
    spriteP1.setPosition(55,55);

    spriteP2.setTextureRect(IntRect(0,0,30,35));
    spriteP2.setTexture(playerTexture2);
    spriteP2.setPosition(655,555);

}


//set mouvement of the player and make collision
void Game::setMouvement(){

    //mouvement player 2
    Vector2f movement2;
    if(Keyboard::isKeyPressed(Keyboard::Up)){
        movement2.y -=velocity;
        spriteP2.setTextureRect(IntRect(60,0,30,35));
    }
    if(Keyboard::isKeyPressed(Keyboard::Down)){
        movement2.y +=velocity;
        spriteP2.setTextureRect(IntRect(0,0,30,35));
    }
    if(Keyboard::isKeyPressed(Keyboard::Right)){
        movement2.x +=velocity;
        spriteP2.setTextureRect(IntRect(30,0,30,35));
    }
    if(Keyboard::isKeyPressed(Keyboard::Left)){
        movement2.x -=velocity;
        spriteP2.setTextureRect(IntRect(90,0,30,35));
    }

    //colision whit wall and box player 2
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

    //mouvment player 1
    Vector2f movement;
    if(Keyboard::isKeyPressed(Keyboard::Z)){
        movement.y -=velocity;
        spriteP1.setTextureRect(IntRect(60,0,30,35));
    }
    if(Keyboard::isKeyPressed(Keyboard::S)){
        movement.y +=velocity;
        spriteP1.setTextureRect(IntRect(0,0,30,35));
    }
    if(Keyboard::isKeyPressed(Keyboard::D)){
        movement.x +=velocity;
        spriteP1.setTextureRect(IntRect(30,0,30,35));
    }
    if(Keyboard::isKeyPressed(Keyboard::Q)){
        movement.x -=velocity;
        spriteP1.setTextureRect(IntRect(90,0,30,35));
    }

    //colision whit wall and box player 1
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

//creation of an explosion and break box in game
void Game::createExplosion(int x, int y, int range){
    //set for end when explosion toutch the wall
    bool end1 = false;
    bool end2 = false;
    bool end3 = false;
    bool end4 = false;

    for(int i = 1; i <= range ; i++){
        //draw explosition
        if(i == 1){
            EploP.push_back(new Explosion());
            EploP[EploP.size()-1]->sprite.setPosition(x,y);
            EploP[EploP.size()-1]->sprite.setTextureRect(IntRect(EploP[EploP.size()-1]->getXpos(),0,50,50));
            EploP[EploP.size()-1]->clock.restart();
        }

        //destroy box when explosion touch them and set position X for animation of explosion
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
        //destroy box when explosion touch them and set position X for animation of explosion
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
        //destroy box when explosion touch them and set position X for animation of explosion
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
        //destroy box when explosion touch them and set position X for animation of explosion
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
//make a new spawn for a player when he die
void Game::PlayerTouch(){
    EploP.clear();
    spriteP1.setPosition(55,55);
    spriteP2.setPosition(655,555);
    gameWord = GameWord();
}
//start menu
void Game::StartMenu(RenderWindow& window){
    window.close();
    RenderWindow windowMenu(VideoMode(1400, 800), "BomberMan - Menu");
    Menu menu(Width,Height);
    menu.launchMenu(windowMenu);
}


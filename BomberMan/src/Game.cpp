#include "Game.h"

Game::Game()
{
    this->initVariables();
    this->initWindow();
}
void Game::initVariables(){
    this->window = nullptr;
}

Game::~Game()
{
    delete this window;
}


const bool Game::getWindowIsOpen() const{
    return this->window->isOpen();
}

void Game::initWindow(){

    this->vdMode.height = 800;
    this->vdMode.width = 1400;
    this->window = new sf::RenderWindow(this->vdMode, "Game");

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

void Game::pollEvent(){
    while(this->window->pollEvent(this->event)){
        switch(this->event.type){

            case sf::Event::Closed:
                this->window.close();
                break;
            case sf::Event::KeyPressed:
                if(this->event.key.code == sf::Keyboard::Escape)
                this->window.close();
                break;

        }
    }

}
void Game::update(){
    this->pollEvent();
}
void Game::render(){
    this->window->clear(sf::Color(255,0,0,255));
}

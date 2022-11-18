#include "Player.h"
#include<string>
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;





Player::Player(Sprite spriteP,int nbVie, string Pseudo, bool IsAlive)
{


    this->nbVie = nbVie;
    this->Pseudo = Pseudo;
    this->IsAlive = IsAlive;
    up = false;
    down = false;
    right = false;
    left = false;

}


Player::~Player()
{
    //dtor
}


int Player::getNbVie(){
    return nbVie;
}


//void Player::processEvents(Keyboard key, bool checkPressed ){
//    if(checkPressed == true){
//        if(key==Keyboard::Z){
//            up = true;
//        }
//        if(key==Keyboard::S){
//            down = true;
//        }
//        if(key==Keyboard::D){
//            right = true;
//        }
//        if(key==Keyboard::Q){
//            left= true;
//        }
//    }
//
//    if(checkPressed == false){
//        up = false;
//        down = false;
//        right = false;
//        left = false;
//    }
//
//}

//void update(){
//    Vector2f movement;
//    if(up){
//        movement.y +=1.0;
//    }
//    if(down){
//        movement.y -=1.0;
//    }
//    if(right){
//        movement.x +=1.0;
//    }
//    if(left){
//        movement.x -=1.0;
//    }
//    Player.move(movement)
//}




bool Player::setUpSprite(string textureName){
    if(!texture.loadFromFile(textureName))
    {
        //handler error image
    }
    texture.setSmooth(true);
    spriteP.setTexture(texture);
    spriteP.setTextureRect(IntRect(0,0,50,50));
    return true;
}




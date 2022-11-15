#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

using namespace std;


class Player : public sf::Drawable
{


    private:
        int nbVie;
        string Pseudo;
        bool IsAlive;
        Texture texture;

    public:
        Player(nbVie = 3, string Pseudo="okok");
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);
        void SetTexture(sf::Texture& texture);
        int getNbVie();

        string str()const

};

#endif // PLAYER_H

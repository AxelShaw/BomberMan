#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Game.h>
#include <About.h>

using namespace sf;

#define MAX 3

const int Width = 1400;
const int Height = 800;

class Menu
{
    private:
        int selectItem;
        Font font;
        Text menuText[MAX];

    public:
        //whight window
        Menu(float width, float height);
        virtual ~Menu();
        //launch menu
        void launchMenu(RenderWindow& window);
        //move up in menu when key press
        void moveUp();
        //move down in menu when key press
        void MoveDown();
        //get select item in menu
        int GetPressedItem();
        //start game window
        void StartGame(RenderWindow& window);
        //start About window
        void StartAbout(RenderWindow& window);
};

#endif // MENU_H

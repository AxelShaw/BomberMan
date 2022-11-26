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
        Menu(float width, float height);
        virtual ~Menu();
        void launchMenu(RenderWindow& window);
        void moveUp();
        void MoveDown();
        int GetPressedItem();
        void StartGame(RenderWindow& window);
        void StartAbout(RenderWindow& window);
};

#endif // MENU_H

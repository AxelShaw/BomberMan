#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>

using namespace sf;

#define MAX 3

const int Width = 1400;
const int Height = 800;

class Menu
{
    public:
        Menu(float width, float height);
        virtual ~Menu();
        void launchMenu(RenderWindow& window);
        void moveUp();
        void MoveDown();
        int GetPressedItem();
        void StartGame(RenderWindow& window);

    private:
        int selectItem;
        Font font;
        Text menuText[MAX];

};

#endif // MENU_H

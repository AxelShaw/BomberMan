#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>

using namespace sf;

#define MAX 3

class Menu
{
    public:
        Menu(float width, float height);
        virtual ~Menu();
        void launchMenu(RenderWindow& window);
        void moveUp();
        void MoveDown();
        int GetPressedItem();

    private:
        int selectItem;
        Font font;
        Text menuText[MAX];

};

#endif // MENU_H

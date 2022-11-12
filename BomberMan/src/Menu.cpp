#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Texture bgTexture;

Sprite bgSprite;

Menu::Menu(float width, float height)
{
    if(!font.loadFromFile("res/fonts/OpenSans-Regular.ttf"))
    {
        //hadler error
    }

    if(!bgTexture.loadFromFile("res/img/FontMenu.jpg"))
    {
        //handler error image
    }

    bgSprite.setTexture(bgTexture);



    menuText[0].setFont(font);
    menuText[0].setColor(Color::Red);
    menuText[0].setString("Play");
    menuText[0].setPosition(Vector2f(width / 2, height / (MAX + 1) * 1));

    menuText[1].setFont(font);
    menuText[1].setColor(Color::White);
    menuText[1].setString("About");
    menuText[1].setPosition(Vector2f(width / 2, height / (MAX + 1) * 2));

    menuText[2].setFont(font);
    menuText[2].setColor(Color::White);
    menuText[2].setString("Exit");
    menuText[2].setPosition(Vector2f(width / 2, height / (MAX + 1) * 3));

    selectItem = 0;

}

Menu::~Menu()
{
    //dtor
}

void Menu::launchMenu(RenderWindow& window)
{
    // 60fps
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type){
                case Event::KeyReleased:
                    switch(event.key.code){
                        case Keyboard::Up:
                            moveUp();
                            break;
                        case Keyboard::Down:
                            MoveDown();
                            break;
                        case Keyboard::Return:
                            switch(GetPressedItem()){
                                case 0:
                                    break;
                                case 1:
                                    break;
                                case 2:
                                    window.close();
                                    break;
                            }

                            break;
                    }
                    break;

                case Event::Closed:
                    window.close();
                    break;
            }
        }

        window.clear();

        window.draw(bgSprite);

        for(int i = 0; i < MAX; i++){
            window.draw(menuText[i]);
        }
        window.display();
    }
}

void Menu::moveUp(){
    if(selectItem -1 >= 0){
        menuText[selectItem].setColor(Color::White);
        selectItem--;
        menuText[selectItem].setColor(Color::Red);

    }
}
void Menu::MoveDown(){

    if(selectItem +1 < MAX){
        menuText[selectItem].setColor(Color::White);
        selectItem++;
        menuText[selectItem].setColor(Color::Red);

    }
}

int Menu::GetPressedItem(){
    return selectItem;
}
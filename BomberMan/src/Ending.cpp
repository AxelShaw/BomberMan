#include "Ending.h"
#include <SFML/Graphics.hpp>
#include "Menu.h"

Ending::Ending()
{
    //ctor
}

Ending::~Ending()
{
    //dtor
}
void Ending::launchEnding(RenderWindow& window)
{

    if(!font.loadFromFile("res/fonts/OpenSans-Regular.ttf"))
    {
        //hadler error
    }

    text[0].setFont(font);
    text[0].setColor(Color::Red);
    text[0].setString("Player 1 Win ! ");
    text[0].setPosition(Vector2f(700/2,400/2));


    // 60fps
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type){
                case Event::Closed:
                    window.close();
                    break;
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                    StartMenu(window);
                }
            }
        }

        window.clear();

        window.draw(text[0]);

        window.display();
    }
}

void Ending::StartMenu(RenderWindow& window){
    window.close();
    RenderWindow windowMenu(VideoMode(1400, 800), "BomberMan - Menu");
    Menu menu(Width,Height);
    menu.launchMenu(windowMenu);
}

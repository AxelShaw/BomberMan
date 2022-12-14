#include "About.h"
#include <SFML/Graphics.hpp>
#include "Menu.h"

using namespace sf;


About::About()
{

}

About::~About()
{
    //dtor
}

About::About(const About& other)
{
    //copy ctor
}

About& About::operator=(const About& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void About::launchAbout(RenderWindow& window)
{
    //cretate a rectangle for view
    RectangleShape rect;

    //set the position of the rectangle and the color
    Vector2f rectP(300,150);
    rect.setPosition(rectP);
    rect.setFillColor(sf::Color (255, 229, 204));
    rect.setSize(Vector2f(800,500));
    rect.setOutlineThickness(10);

    //load the font forthe text
    if(!font.loadFromFile("res/fonts/OpenSans-Regular.ttf"))
    {
        //hadler error
    }

    //set text with the font and the position on the screen
    text[0].setFont(font);
    text[0].setColor(Color::Black);
    text[0].setString("Control player 1 :");
    text[0].setPosition(Vector2f(700/2,400/2));

    text[1].setFont(font);
    text[1].setColor(Color::Black);
    text[1].setString(" Move : Z Q S D");
    text[1].setPosition(Vector2f(700/2,250));

    text[2].setFont(font);
    text[2].setColor(Color::Black);
    text[2].setString(" Drop bomb : Space");
    text[2].setPosition(Vector2f(700/2,300));

    text[3].setFont(font);
    text[3].setColor(Color::Black);
    text[3].setString("Control player 2 :");
    text[3].setPosition(Vector2f(700/2,350));

    text[4].setFont(font);
    text[4].setColor(Color::Black);
    text[4].setString(" Move : directional arrow");
    text[4].setPosition(Vector2f(700/2,400));

    text[5].setFont(font);
    text[5].setColor(Color::Black);
    text[5].setString(" Drop bomb : M");
    text[5].setPosition(Vector2f(700/2,450));

    text[6].setFont(font);
    text[6].setColor(Color::Black);
    text[6].setString("Press Escape to leave window");
    text[6].setPosition(Vector2f(700/2,600));

    text[7].setFont(font);
    text[7].setColor(Color::Black);
    text[7].setString("Press Delete to cut music");
    text[7].setPosition(Vector2f(700/2,550));

    // 60fps
    window.setFramerateLimit(60);

    //draw element and press key event when the window is open
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
        window.draw(rect);
        window.draw(text[0]);
        window.draw(text[1]);
        window.draw(text[2]);
        window.draw(text[3]);
        window.draw(text[4]);
        window.draw(text[5]);
        window.draw(text[6]);
        window.draw(text[7]);
        window.display();
    }
}

//methode for start the menu
void About::StartMenu(RenderWindow& window){
    //create window for menu
    RenderWindow windowMenu(VideoMode(1400, 800), "BomberMan - Menu");
    //create menu
    Menu menu(Width,Height);
    //launch menu
    menu.launchMenu(windowMenu);
}

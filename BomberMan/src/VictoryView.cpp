#include "VictoryView.h"
#include "Menu.h"


Texture tropheeTexture;

Sprite spritetrophee;

VictoryView::VictoryView()
{
    //ctor
}

VictoryView::~VictoryView()
{
    //dtor
}

void VictoryView::launchVictory(RenderWindow& window,string textureName)
{
    // 60fps
    window.setFramerateLimit(60);

    if(!texture.loadFromFile(textureName))
    {
            //handler error image
    }
    if(!font.loadFromFile("res/fonts/OpenSans-Regular.ttf"))
    {
        //hadler error
    }
    if(!tropheeTexture.loadFromFile("res/img/trophe.png"))
    {
        //handler error image
    }


    spritetrophee.setTexture(tropheeTexture);
    spritetrophee.setPosition(275,250);

    text[0].setFont(font);
    text[0].setColor(Color::White);
    text[0].setString("Player ");
    text[0].setPosition(Vector2f(260,100));

    text[1].setFont(font);
    text[1].setColor(Color::White);
    text[1].setString("Win! ");
    text[1].setPosition(Vector2f(410,100));

    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setPosition(360,100);
    sprite.setTextureRect(IntRect(0,0,30,70));


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if(event.type == Event::Closed){
                window.close();
            }

            if(Keyboard::isKeyPressed(Keyboard::Escape)){
                window.close();
                StartMenu(window);
            }
        }
        window.clear();
        window.draw(sprite);
        window.draw(spritetrophee);
        window.draw(text[0]);
        window.draw(text[1]);
        window.display();

    }

}
void VictoryView::StartMenu(RenderWindow& window){
    window.close();
    RenderWindow windowMenu(VideoMode(1400, 800), "BomberMan - Menu");
    Menu menu(Width,Height);
    menu.launchMenu(windowMenu);
}

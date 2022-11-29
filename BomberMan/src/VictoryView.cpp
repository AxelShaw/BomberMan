#include "VictoryView.h"

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
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setPosition(0,0);

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
            }
        }
        window.clear();
        window.draw(sprite);
        window.display();

    }

}

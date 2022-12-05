#ifndef VICTORYVIEW_H
#define VICTORYVIEW_H
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class VictoryView
{
    private:
        Texture texture;
        Sprite sprite;
        Text text[2];
        Font font;

    public:
        VictoryView();
        virtual ~VictoryView();
        //start victory view whit window and texture player win
        void launchVictory(RenderWindow& window,string textureName);
        //start menu window
        void StartMenu(RenderWindow& window);
};

#endif // VICTORYVIEW_H

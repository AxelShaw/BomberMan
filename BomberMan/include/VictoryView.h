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
        void launchVictory(RenderWindow& window,string textureName);
        void StartMenu(RenderWindow& window);
};

#endif // VICTORYVIEW_H

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

    public:
        VictoryView();
        virtual ~VictoryView();
        void launchVictory(RenderWindow& window,string textureName);
};

#endif // VICTORYVIEW_H

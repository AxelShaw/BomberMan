#include <SFML/Graphics.hpp>
#include <iostream>
#include <Menu.h>
#include <Game.h>

using namespace std;
using namespace sf;

int main()
{
    const int Width = 1400;
    const int Height = 800;

    Game game;

    while(game.getWindowIsOpen()){
        game.update():

        game.render();
    }

    //RenderWindow window(VideoMode(Width, Height), "Bomber Man");

    //Menu menu(Width, Height);




    //menu.launchMenu(window);

}

#include <SFML/Graphics.hpp>
#include <iostream>
#include <Menu.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace sf;

int main()
{
    //set a random
    srand (time(NULL));

    //create the window
    RenderWindow window(VideoMode(Width, Height), "Bomber Man");

    //create menu
    Menu menu(Width, Height);

    //lunch menu
    menu.launchMenu(window);
}

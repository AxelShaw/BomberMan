#include <SFML/Graphics.hpp>
#include <iostream>
#include <Menu.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace sf;

int main()
{
    srand (time(NULL));

    RenderWindow window(VideoMode(Width, Height), "Bomber Man");

    Menu menu(Width, Height);

    menu.launchMenu(window);
}

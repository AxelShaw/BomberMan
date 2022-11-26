#include <SFML/Graphics.hpp>
#include <iostream>
#include <Menu.h>

using namespace std;
using namespace sf;

int main()
{



    RenderWindow window(VideoMode(Width, Height), "Bomber Man");

    Menu menu(Width, Height);

    menu.launchMenu(window);
}

#include <SFML/Graphics.hpp>
#include <iostream>
#include <Menu.h>

using namespace std;
using namespace sf;

int main()
{
    const int Width = 1400;
    const int Height = 800;

    RenderWindow window(VideoMode(Width, Height), "Bomber Man");

    Player pla;
    cout<<pla.str()<<endl;
    Menu menu(Width, Height);


    menu.launchMenu(window);

}

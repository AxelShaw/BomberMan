#ifndef ABOUT_H
#define ABOUT_H
#include <SFML/Graphics.hpp>

using namespace sf;


class About
{
    private:
        RectangleShape rect;
        Text text[8];
        Font font;

    public:
        About();
        virtual ~About();
        About(const About& other);
        About& operator=(const About& other);
        //launch about window
        void launchAbout(RenderWindow& window);
        //launch menu window
        void StartMenu(RenderWindow& window);
};

#endif // ABOUT_H

#ifndef ABOUT_H
#define ABOUT_H
#include <SFML/Graphics.hpp>

using namespace sf;


class About
{
    private:
        RectangleShape rect;
        Text text[7];
        Font font;

    public:
        About();
        virtual ~About();
        About(const About& other);
        About& operator=(const About& other);
        void launchAbout(RenderWindow& window);
        void StartMenu(RenderWindow& window);
};

#endif // ABOUT_H

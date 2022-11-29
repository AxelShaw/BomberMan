#ifndef ENDING_H
#define ENDING_H
#include <SFML/Graphics.hpp>

using namespace sf;


class Ending
{


    private:
        Text text[2];
        Font font;


    public:
        Ending();
        virtual ~Ending();
        void launchEnding(RenderWindow& window);
        void StartMenu(RenderWindow& window);

};

#endif // ENDING_H

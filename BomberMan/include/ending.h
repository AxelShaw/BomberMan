#ifndef ENDING_H
#define ENDING_H
#include <SFML/Graphics.hpp>

using namespace sf;

class ending
{


    private:
        Text text[1];
        Font font;


    public:
        ending();
        virtual ~ending();
        void launchAbout(RenderWindow& window);
        void StartMenu(RenderWindow& window);


};

#endif // ENDING_H
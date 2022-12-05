#include "Menu.h"


using namespace sf;

//create texture and sprite for background
Texture bgTexture;

Sprite bgSprite;

//taille dela fenetre
const int WidthGame = 750;
const int HeightGame = 650;

Menu::Menu(float width, float height)
{
    //load font for text
    if(!font.loadFromFile("res/fonts/OpenSans-Regular.ttf"))
    {
        //hadler error
    }

    //load background
    if(!bgTexture.loadFromFile("res/img/FontMenu.jpg"))
    {
        //handler error image
    }

    //set up texture for background
    bgSprite.setTexture(bgTexture);


    //set font and color and position for text
    menuText[0].setFont(font);
    menuText[0].setColor(Color::Red);
    menuText[0].setString("Play");
    menuText[0].setPosition(Vector2f(width / 2, height / (MAX + 1) * 1));

    menuText[1].setFont(font);
    menuText[1].setColor(Color::White);
    menuText[1].setString("About");
    menuText[1].setPosition(Vector2f(width / 2, height / (MAX + 1) * 2));

    menuText[2].setFont(font);
    menuText[2].setColor(Color::White);
    menuText[2].setString("Exit");
    menuText[2].setPosition(Vector2f(width / 2, height / (MAX + 1) * 3));

    //item selected by user
    selectItem = 0;

}

Menu::~Menu()
{
    //dtor
}
//launch menu
void Menu::launchMenu(RenderWindow& window)
{
    // 60fps
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        //event and key event in menu for select elemnt of the menu ( play, about, exit)
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type){
                case Event::KeyReleased:
                    switch(event.key.code){
                    //press up for move up in menu
                        case Keyboard::Up:
                            moveUp();
                            break;
                    //press down for move down in menu
                        case Keyboard::Down:
                            MoveDown();
                            break;
                        case Keyboard::Return:
                            switch(GetPressedItem()){
                                case 0:
                                    StartGame(window);
                                    break;
                                case 1:
                                    StartAbout(window);
                                    break;
                                case 2:
                                    window.close();
                                    break;
                            }

                            break;
                        default:
                            break;
                    }
                    break;

                case Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }

        window.clear();

        //draw background
        window.draw(bgSprite);

        //draw text
        for(int i = 0; i < MAX; i++){
            window.draw(menuText[i]);
        }
        window.display();
    }
}

//movement up for select element in menu
void Menu::moveUp(){
    if(selectItem -1 >= 0){
        menuText[selectItem].setColor(Color::White);
        selectItem--;
        menuText[selectItem].setColor(Color::Red);

    }
}
//movement down for select element in menu
void Menu::MoveDown(){

    if(selectItem +1 < MAX){
        menuText[selectItem].setColor(Color::White);
        selectItem++;
        menuText[selectItem].setColor(Color::Red);

    }
}

int Menu::GetPressedItem(){
    return selectItem;
}

void Menu::StartGame(RenderWindow& window){
    window.close();
    RenderWindow windowGame(VideoMode(WidthGame, HeightGame), "BomberMan - Game");
    Game game;
    game.launchGame(windowGame);
}

void Menu::StartAbout(RenderWindow& window){
    window.close();
    RenderWindow windowAbout(VideoMode(Width, Height), "BomberMan - About");
    About about;
    about.launchAbout(windowAbout);
}

#ifndef BOMB_H
#define BOMB_H
#include <iostream>


class Bomb
{
    private:
        int posX;
        int posY;

    public:
        Bomb(int posX,int posY);
        virtual ~Bomb();
        Bomb(const Bomb& other);
        Bomb& operator=(const Bomb& other);





};

#endif // BOMB_H

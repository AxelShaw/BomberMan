#include "Bomb.h"

Bomb::Bomb( int PosX, int PosY)
{
    this->PosX=PosX;
    this->PosY=PosY;
}
}

Bomb::~Bomb()
{
    //dtor
}

Bomb::Bomb(const Bomb& other)
{
    //copy ctor
}

Bomb& Bomb::operator=(const Bomb& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

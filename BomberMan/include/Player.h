#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        Player();
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);

    protected:

    private:
};

#endif // PLAYER_H

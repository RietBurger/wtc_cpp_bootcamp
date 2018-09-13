#ifndef PLAYER_H
# define PLAYER_H
#include "Objects.hpp"

class Player : public Objects
{
    public:
        std::string name;
        int     health;
        int     score;

    Player(WINDOW * win, int y, int x, char c, std::string name);
    Player(Player const & src);
    int getCount(void) const;
    ~Player();

    void stats();
};

#endif
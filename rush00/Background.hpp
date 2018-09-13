#ifndef BACKGROUND_H
# define BACKGROUND_H

#include "Objects.hpp"

class Background : public Objects
{
    public:
        std::string name;    

    Background(WINDOW * win, int y, int x, char c, std::string name);
    Background(Background const & src);
    int getCount(void) const;
    ~Background();

    void meteorShower();
};

#endif
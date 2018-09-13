#ifndef BULLETS_H
# define BULLETS_H

#include "Objects.hpp"

class Bullets : public Objects
{
    public:
        std::string	name;
        char	shape;
		bool	isActive;
    

    Bullets(WINDOW * win, int y, int x, char c, std::string name);
    Bullets(Bullets const & src);
	Bullets(void);
    int getCount(void) const;
    ~Bullets();

	void setBullets(WINDOW * win, int y, int x, char c, std::string name);
    void travel();
};

#endif
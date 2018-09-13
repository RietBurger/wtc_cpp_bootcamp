#include "Bullets.hpp"

Bullets::Bullets(WINDOW * win, int y, int x, char c, std::string name) : Objects(win, y, x, c, name)
{
	// std::cout << "\033[01;35m" << this->name << "\033[0m has been added to the fight! " << std::endl;
    this->travel();
} 

Bullets::Bullets(Bullets const & src) : Objects(src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

std::ostream & operator<<(std::ostream & o, Bullets const & i){
    o << "The value of _count by 'o' is : " << i.getCount();
    return o;
}

Bullets::Bullets(void) : Objects()
{
	isActive = false;
	return;
}

int     Bullets::getCount() const{
    return this->_count;
}

Bullets::~Bullets(){
	// std::cout << this->name << " Destroyed..!" << std::endl;
}

void Bullets::travel()
{
    // std::cout << "This is the bullet travelling ----- " << std::endl;
}

void	Bullets::setBullets(WINDOW * win, int y, int x, char c, std::string bulletName)
{
	curwin = win;
	_y = y;
	_x = x + 1;
	character = c;
	name = bulletName;
	isActive = true;
	Objects::_count += 1;
}
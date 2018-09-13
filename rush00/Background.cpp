#include "Background.hpp"

Background::Background(WINDOW * win, int y, int x, char c, std::string name) : Objects(win, y, x, c, name)
{
	std::cout << "\033[01;35m" << this->name << "\033[0m has been added to the fight! " << std::endl;
    this->meteorShower();
} 

Background::Background(Background const & src) : Objects(src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

std::ostream & operator<<(std::ostream & o, Background const & i){
    o << "The value of _count by 'o' is : " << i.getCount();
    return o;
}

int     Background::getCount() const{
    return this->_count;
}

Background::~Background(){
	std::cout << this->name << " Destroyed..!" << std::endl;
}

void Background::meteorShower()
{
    std::cout << "Meteor Shower heading your way!!!" << std::endl;
}
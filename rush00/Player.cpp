#include "Player.hpp"

Player::Player(WINDOW * win, int y, int x, char c, std::string name) : Objects(win, y, x, c, name)
{
    this->health = 100;
	// std::cout << "\033[01;35m" << this->name << "\033[0m has been added to the fight! " << std::endl;
    // this->shoot();
} 

Player::Player(Player const & src) : Objects(src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

std::ostream & operator<<(std::ostream & o, Player const & i){
    o << "The value of _count by 'o' is : " << i.getCount();
    return o;
}

int     Player::getCount() const{
    return this->_count;
}

Player::~Player(){
	std::cout << this->name << " Destroyed..!" << std::endl;
}

void     Player::stats()
{   
    std::string items[] = {"SCORE: ", "TIME: ", "LEVEL: "};
    
    
    // std::cout << "You just shot at someone!" << std::endl;
    // _y = y;
    // _x = x + 1; // x-moves
    // Bullet * blt = new Bullet(playwin, _y, _x, '-', "bullet1");
    // mvwaddch(curwin, _y, _x, '-');
}
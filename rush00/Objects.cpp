#include "Objects.hpp"
#include "Bullets.hpp"

Objects::Objects(WINDOW * win, int y, int x, char c, std::string name) : name(name)
{
    curwin = win;
    _y = y;
    _x = x;
    getmaxyx(curwin, yMax, xMax);
    keypad(curwin, true);
    character = c;
	// std::cout << "\033[01;35m" << this->name << "\033[0m has been added to the fight! " << std::endl;
    this->movement();
    // this->collision();
} 

Objects::Objects(void)
{
	return;
}

Objects::Objects(Objects const & src){
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

std::ostream & operator<<(std::ostream & o, Objects const & i){
    o << "The value of _count by 'o' is : " << i.getCount();
    return o;
}

int     Objects::getCount() const{
    return this->_count;
}

Objects::~Objects(){
	// std::cout << this->name << " Destroyed..! Play again?" << std::endl;
}

void    Objects::movement()
{
    // std::cout << "changed Objects position " << std::endl;

}




// void Objects::createWindow(WINDOW * win, int y, int x, char c)
// {
//     curwin = win;
//     _y = y;
//     _x = x;
//     getmaxyx(curwin, yMax, xMax);
//     keypad(curwin, true);
//     character = c;
//     // B_x = 0;
//     // B_y = 0;
// }

void Objects::mvup()
{
    mvwaddch(curwin, _y, _x, ' ');
    _y--;
    if (_y < 1)
        _y = 1;
}

void Objects::mvdown()
{
    mvwaddch(curwin, _y, _x, ' ');
    _y++;
    if (_y > yMax - 2)
        _y = yMax - 2;
}

void Objects::mvleft()
{
    mvwaddch(curwin, _y, _x, ' ');
    _x--;
    if (_x < 1)
        _x = 1;
}

void Objects::mvright()
{
    mvwaddch(curwin, _y, _x, ' ');
    _x++;
    if (_x > xMax - 2)
        _x = xMax - 2;
}

int Objects::getmv()
{
    int choice = wgetch(curwin);
    switch(choice)
    {
        case KEY_UP:
            mvup();
            break;
        case KEY_DOWN:
            mvdown();
            break;
        case KEY_LEFT:
            mvleft();
            break;
        case KEY_RIGHT:
            mvright();
            break;
        case 27:
            // return (1000);
            break;
        default:
            break;
    }
    return choice;
}

void Objects::display()
{
    mvwaddch(curwin, _y, _x, character);
}

void Objects::display2(char character)
{
    mvwaddch(curwin, _y, _x, character);
}
#ifndef OBJECTS_H
# define OBJECTS_H

#include <iostream>
#include <ncurses.h>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>


class Objects{
    
    public:
        std::string name;
        char    character;

    Objects(WINDOW * win, int y, int x, char c, std::string name);
    Objects(Objects const & src);
	Objects(void);
    int getCount(void) const;
    ~Objects();

    void movement();

    void mvup();
    void mvdown();
    void mvleft();
    void mvright();
    int getmv();
    void display();
    void display2(char character);
    // void createWindow();
    int     _x;
    int     _y;
    int     yMax;
    int     _count;
    
    protected:
        
        
        
        int     xMax;
        
        WINDOW * curwin;

        int     winX;
        int     winY;

};

#endif
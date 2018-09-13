#ifndef CLASS_H
# define CLASS_H

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>


class Shells
{
    public:

    

    Shells();
    Shells(Shells const & src);
    ~Shells();
    int getObj();
    void enviro(char *sent);
    std::string exec(const char* cmd);

    private:

};



#endif
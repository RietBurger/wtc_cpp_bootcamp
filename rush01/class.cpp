#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>

#include "class.hpp"

Shells::Shells() {
    std::cout << "constructor" << std::endl;
}

Shells::~Shells(){
    std::cout << "destructor" << std::endl;
}

Shells::Shells(Shells const & src) {
    *this = src;
}

//enviro(av[1]);
void    Shells::enviro(char *sent)
{
    if(const char *env_p = std::getenv(sent))
        std::cout << "Your PATH is: " << env_p << std::endl;
}
// res = exec("sysctl -n machdep.cpu.brand_string");
std::string Shells::exec(const char* cmd) {
   std::array<char, 128> buffer;
   std::string result;
   std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
   if (!pipe) throw std::runtime_error("popen() failed!");
   while (!feof(pipe.get())) {
       if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
           result += buffer.data();
   }
   return result;
}
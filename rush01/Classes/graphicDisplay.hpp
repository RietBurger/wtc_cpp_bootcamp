#ifndef GRAPHIC_DISPLAY_H
#define GRAPHIC_DISPLAY_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <unistd.h>

//classes
#include "Hostname.hpp"
#include "Dateinfo.hpp"
#include "Osinfo.hpp"
#include "RAMinfo.hpp"
#include "CPUinfo.hpp"
#include "NetworkInfo.hpp"
#include "Dateinfo.hpp"
#include "IMonitorDisplay.hpp"

class GraphicDisplay : public IMonitorDisplay
{
    public:
        GraphicDisplay();
        GraphicDisplay(GraphicDisplay const & src);
        GraphicDisplay& operator=( GraphicDisplay const & rhs );
        ~GraphicDisplay();
        virtual void    renderModules(std::string input);
        std::string getName() const;
     private:
        std::string _name;
};
#endif
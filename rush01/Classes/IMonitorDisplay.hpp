#ifndef _IMONITORDISPLAY_HPP
# define _IMONITORDISPLAY_HPP

#include "ft_gkrellm.hpp"

class IMonitorDisplay {
	public:
		// Constructor & Destructor
		IMonitorDisplay();
		virtual ~IMonitorDisplay();

		// Functions
		virtual void	renderModules( std::string input ) = 0;
		
	private:
		IMonitorDisplay( IMonitorDisplay const & copy );
		IMonitorDisplay&	operator=( IMonitorDisplay const & rhs );

};

#endif
#ifndef _NCURSESMODULE_HPP
# define _NCURSESMODULE_HPP

#include "ft_gkrellm.hpp"

class NcursesModule : public IMonitorDisplay {
	
	public:
		// Constructors & destructors
		NcursesModule( std::vector<IMonitorDisplay*> modules ); // Creates a new window
		NcursesModule( NcursesModule const & copy ); // Copy constructor
		~NcursesModule( void );

		// Operator overrides
		NcursesModule&		operator=( NcursesModule const & rhs );

		virtual void	renderModules( Osinfo testOs, Dateinfo testDate, Hostname testHost, Raminfo testRam, Cpuinfo testCpu, NetworkInfo testNetwork );

	private:
		std::vector<IMonitorDisplay*>	_modules;
};

#endif
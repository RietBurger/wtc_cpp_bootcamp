#include "NcursesModule.hpp"

NcursesModule::NcursesModule( std::vector<IMonitorDisplay*> modules ) {

	return ;
}

NcursesModule::NcursesModule( NcursesModule const & copy ) {
	operator=( copy );
	return ;
}

NcursesModule::~NcursesModule( void ) {
	return ;
}

NcursesModule&		NcursesModule::operator=( NcursesModule const & rhs ) {
	if ( this == &rhs )
		return *this;
	return *this;
}

void	NcursesModule::renderModules( Osinfo testOs, Dateinfo testDate, Hostname testHost, Raminfo testRam, Cpuinfo testCpu, NetworkInfo testNetwork ) {

	return ;
}


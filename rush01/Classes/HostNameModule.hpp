#ifndef _HOSTNAMEMODULE_HPP
# define _HOSTNAMEMODULE_HPP

#include "ft_gkrellm.hpp"
#include "IMonitorModule.hpp"

class HostNameModule : public IMonitorModule {
	public:
		// Constructor & Destructor
		HostNameModule( std::string name );
		HostNameModule( HostNameModule const & copy );
		virtual ~HostNameModule( void );

		// Functions
		std::vector<std::string>	getOutput( void ) const;
		std::string					getName( void ) const;

		std::string exec(const char *cmd);
		
	private:
		HostNameModule( void );
		HostNameModule&	operator=( HostNameModule const & rhs );
		
		std::vector<std::string>	_output;
		std::string					_name;
};

#endif
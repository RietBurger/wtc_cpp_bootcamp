#ifndef _IMONITORMODULE_HPP
# define _IMONITORMODULE_HPP

#include "ft_gkrellm.hpp"

class IMonitorModule {
	public:
		IMonitorModule( );
		virtual ~IMonitorModule();

		std::string		getHostNameModule() const;
		std::string		getRamModule() const;
		std::string		getNetworkModule() const;
		std::string		getOSModule() const;
		std::string		getCPUModule() const;
		std::string		getDateTimeModule() const;

		// Functions
		virtual std::string exec(const char *cmd) = 0;
		
	private:
		//IMonitorModule();
		IMonitorModule( IMonitorModule const & copy );
		IMonitorModule&	operator=( IMonitorModule const & rhs );
		
		// IMonitorModule( /* VARS */ );
		std::string _HostNameModule;
		std::string _RamModule;
		std::string _NetworkModule;
		std::string _OSModule;
		std::string _CPUModule;
		std::string _DateTimeModule;
};

#endif
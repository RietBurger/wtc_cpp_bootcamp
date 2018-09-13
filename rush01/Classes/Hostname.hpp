#ifndef HOSTNAME_H
# define HOSTNAME_H

#include "IMonitorModule.hpp"

class Hostname : public IMonitorModule {
	public:
		Hostname();
		Hostname(Hostname const & src);
		Hostname&	operator=( Hostname const & rhs );
		~Hostname();

		std::string getHostname() const;
		std::string getUsername() const;

		std::string exec(const char *cmd);

	private:
		std::string		_hostname;
		std::string		_username;

};

#endif
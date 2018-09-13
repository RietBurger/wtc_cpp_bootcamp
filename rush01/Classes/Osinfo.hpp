#ifndef OSINFO_H
# define OSINFO_H

#include "IMonitorModule.hpp"

class Osinfo : public IMonitorModule {
	public:
		Osinfo();
		Osinfo(Osinfo const & src);
		Osinfo&		operator=( Osinfo const & rhs );
		~Osinfo();

		int 			getCnt() const;
		std::string		getName() const;
		std::string		getVers() const;
		std::string		getBuild() const;
		std::string		getAll() const;

		std::string exec(const char *cmd);

	private:
		int				_cnt;
		std::string		_prodName;
		std::string		_prodVers;
		std::string		_BuildVers;
		std::string		_all;

};

#endif
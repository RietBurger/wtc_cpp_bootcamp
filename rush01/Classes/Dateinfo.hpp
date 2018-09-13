#ifndef DATEINFO_H
# define DATEINFO_H

# include "IMonitorModule.hpp"

class Dateinfo : public IMonitorModule {
	public:

		Dateinfo();
		Dateinfo(Dateinfo const & src);
		Dateinfo&	operator=( Dateinfo const & rhs );
		~Dateinfo();
		
		std::string getDate() const;

		std::string exec(const char *cmd);

	private:
		std::string		_date;

};

#endif
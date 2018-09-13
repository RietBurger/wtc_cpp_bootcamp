#ifndef NETWORKINFO_H
# define NETWORKINFO_H

# include "IMonitorModule.hpp"

class NetworkInfo : public IMonitorModule {
	public:

		NetworkInfo();
		NetworkInfo(NetworkInfo const & src);
		NetworkInfo&	operator=( NetworkInfo const & rhs );
		~NetworkInfo();
		
		std::string getDataPackets() const;

		std::string exec(const char *cmd);

	private:
		std::string		_dataPackets;

};

#endif
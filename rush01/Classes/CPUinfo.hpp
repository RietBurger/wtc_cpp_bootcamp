#ifndef CPUINFO_H
# define CPUINFO_H

# include "IMonitorModule.hpp"

class Cpuinfo : public IMonitorModule {
	public:

		Cpuinfo();
		Cpuinfo(Cpuinfo const & src);
		Cpuinfo&	operator=( Cpuinfo const & rhs );
		~Cpuinfo();

		std::string getCpuUsage() const;
		std::string getClockSpeed() const;
		std::string getNumberOfCores() const;
		std::string getUsers() const;
		std::string getCpuSys() const;
		std::string getCpuIdle() const;
		std::string getProcs() const;
		std::string getLoadAvg() const;
		void setCpuUsage();
		void setProcs();
		void setLoadAvg();

		std::string exec(const char *cmd);

	private:
		std::string _cpuUsage; //top -n0 -l1 | grep 'CPU usage'
		std::string _clockSpeed; //sysctl -n machdep.cpu.brand_string clockspeed and model
		std::string _numberOfCores; //system_profiler SPHardwareDataType | grep Cores
		std::string _cpuInfo;
		std::string _user;
		std::string _sys;
		std::string _idle;
		std::string _processes;
		std::string _loadAvg;

};

#endif
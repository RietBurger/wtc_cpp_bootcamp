#include "Classes/Hostname.hpp"
#include "Classes/Dateinfo.hpp"
#include "Classes/Osinfo.hpp"
#include "Classes/RAMinfo.hpp"
#include "Classes/CPUinfo.hpp"
#include "Classes/NetworkInfo.hpp"
#include "Classes/NcursesModule.hpp"

int main()
{
	Osinfo * testOS = new Osinfo();
	Dateinfo * testDate = new Dateinfo();
	Hostname * testHost = new Hostname();
	Raminfo * testRam = new Raminfo();
	Cpuinfo * testCpu = new Cpuinfo();
	NetworkInfo * testNetwork = new NetworkInfo();

	std::cout << "created" << std::endl;

	NcursesModule	ncursesDisplay;
	
	ncursesDisplay.renderModules( testOS, testDate, testHost, testRam, testCpu, testNetwork );


	std::cout << "\033[32m TEST: \033[0m" << std::endl;
	std::cout << test->getAll() << std::endl;
	std::cout << "\033[32m DATE: \033[0m" << std::endl;
	std::cout << testDate->getDate() << std::endl;
	std::cout << "\033[32m HOST: \033[0m" << std::endl;
	std::cout << testHost->getHostname() << std::endl;
	std::cout << "\033[32m USER: \033[0m" << std::endl;
	std::cout << testHost->getUsername() << std::endl;
	std::cout << "\033[32m RAM_ALL: \033[0m" << std::endl;
	std::cout << testRam->getRamAll() << std::endl;
	std::cout << "\033[32m CPU: \033[0m" << std::endl;
	std::cout << testCpu->getCpu() << std::endl;
	std::cout << "\033[32m CPU_USER: \033[0m" << std::endl;
	std::cout << testCpu->getUsers() << std::endl;
	std::cout << "\033[32m CPU_SYS: \033[0m" << std::endl;
	std::cout << testCpu->getCpuSys() << std::endl;
	std::cout << "\033[32m CPU_IDLE: \033[0m" << std::endl;
	std::cout << testCpu->getCpuIdle() << std::endl;
	std::cout << "\033[32m CPU_PROCESSES: \033[0m" << std::endl;
	std::cout << testCpu->getProcs() << std::endl;
	std::cout << "\033[32m CPU_LOADAVG: \033[0m" << std::endl;
	std::cout << testCpu->getLoadAvg() << std::endl;
	std::cout << "\033[32m CPU_USER: \033[0m" << std::endl;
	std::cout << testCpu->getCpu() << std::endl;
	std::cout << "\033[32m DATAPACKETS: \033[0m" << std::endl;
	std::cout << testNetwork->getDataPackets() << std::endl;


	// std::cout << test;

	delete testDate;
	delete testHost;
	delete testRam;
	delete testCpu;
	delete testNetwork;
	return 0;
}
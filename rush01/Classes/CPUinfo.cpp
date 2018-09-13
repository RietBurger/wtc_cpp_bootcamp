#include "CPUinfo.hpp"

Cpuinfo::Cpuinfo () {
    
    const char *cmd = "sysctl -n machdep.cpu.brand_string";
    const char *cmd1 = "top -n0 -l1 | grep 'CPU usage'";
    const char *cmd2 = "system_profiler SPHardwareDataType | grep Cores";
    
    std::string outp = this->exec(cmd);
    std::string outp2 = this->exec(cmd1);
    std::string outp3 = this->exec(cmd2);

    this->_clockSpeed = outp;
    this->_cpuUsage = outp2;
    this->_numberOfCores = outp3;
    this->_cpuInfo = outp + outp2 + outp3;

    setCpuUsage();
    setLoadAvg();
    setProcs();
}

Cpuinfo::Cpuinfo(Cpuinfo const & src) {
    operator=( src );
	return ;
}

Cpuinfo&	Cpuinfo::operator=( Cpuinfo const & rhs ) {
	if( this == &rhs )
		return *this;
	this->_cpuUsage = rhs.getCpuUsage();
	this->_clockSpeed = rhs.getClockSpeed();
	this->_numberOfCores = rhs.getNumberOfCores();
    this->_user = rhs.getUsers();
    this->_sys = rhs.getCpuSys();
    this->_idle = rhs.getCpuIdle();
    this->_processes = rhs.getProcs();
	return *this;
}

Cpuinfo::~Cpuinfo(){
    // std::cout << "destructed" << std::endl;
}

void Cpuinfo::setCpuUsage()
{
    const char *cmd = "top -n0 -l1 | grep CPU | cut -f1 -d,";
    std::string outp = this->exec(cmd);
    this->_user = outp;

    // const char *
    cmd = "top -n0 -l1 | grep CPU | cut -f2 -d,";
    // std::string 
    outp = this->exec(cmd);
    this->_sys = outp;

    // const char *
    cmd = "top -n0 -l1 | grep CPU | cut -f3 -d,";
    // std::string 
    outp = this->exec(cmd);
    this->_idle = outp;

}

void Cpuinfo::setProcs()
{
    const char *cmd = "top -n0 -l1 | grep Processes";
    std::string outp = this->exec(cmd);
    this->_processes = outp;
}

void Cpuinfo::setLoadAvg()
{
    const char *cmd = "top -n0 -l1 | grep Load";
    std::string outp = this->exec(cmd);
    this->_loadAvg = outp;
}

std::string Cpuinfo::getClockSpeed() const {
    return this->_clockSpeed;
}

std::string Cpuinfo::getCpuUsage() const {
    return this->_cpuUsage;
}

std::string Cpuinfo::getNumberOfCores() const {
    return this->_numberOfCores;
}

std::string Cpuinfo::getUsers() const {
    return this->_user;
}

std::string Cpuinfo::getCpuSys() const
{
    return this->_sys;
}

std::string Cpuinfo::getCpuIdle() const
{
    return this->_idle;
}

std::string Cpuinfo::getProcs() const
{
    return this->_processes;
}

std::string Cpuinfo::getLoadAvg() const
{
    return this->_loadAvg;
}

std::string Cpuinfo::exec(const char* cmd) {
   
   std::array<char, 128> buffer;
   std::string result;
   std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
   if (!pipe) throw std::runtime_error("popen() failed!");
   while (!feof(pipe.get())) {
       if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
           result += buffer.data();
   }   
   return result;
}

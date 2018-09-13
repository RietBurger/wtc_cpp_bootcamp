#include "RAMinfo.hpp"
#include <cstring>

Raminfo::Raminfo () {
    
    setMemReg();
    setPhysMem();
    setRamInfo();
    setRamAll();
}

Raminfo::Raminfo(Raminfo const & src) {
	operator=( src );
	return ;
}

Raminfo&	Raminfo::operator=( Raminfo const & rhs ) {
	if( this == &rhs )
		return *this;
	this->_raminfo = rhs.getRaminfo();
    this->_memReg = rhs.getMemReg();
    this->_physMem = rhs.getPhysMem();
    this->_all = rhs.getRamAll();

	return *this;
}

Raminfo::~Raminfo(){
    // std::cout << "destructed" << std::endl;
}

std::string Raminfo::getRaminfo() const {
    return this->_raminfo;
}

std::string Raminfo::exec(const char* cmd) {

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

void Raminfo::setMemReg()
{
    const char *cmd = "top -n0 -l1 | grep MemRegions:";
    std::string outp = this->exec(cmd);
    this->_memReg = outp;
}

void Raminfo::setPhysMem()
{
    const char *cmd = "top -n0 -l1 | grep PhysMem:";
    std::string outp = this->exec(cmd);
    this->_physMem = outp;
}

void Raminfo::setRamInfo()
{
    // this is for RAM hardware info:
    const char *cmd = "system_profiler SPHardwareDataType";
    std::string outp = this->exec(cmd);
    
    this->_raminfo = outp;
}

void Raminfo::setRamAll()
{
    std::string outp = this->_physMem;
    outp += this->_memReg;
    this->_all = outp;
}

int Raminfo::getCnt() const {
    return this->_cnt;
}

std::string Raminfo::getMemReg() const
{
    return this->_memReg;
}

std::string Raminfo::getPhysMem() const
{
    return this->_physMem;
}

std::string Raminfo::getRamAll() const
{
    return this->_all;
}
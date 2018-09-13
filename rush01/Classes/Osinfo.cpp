#include "Osinfo.hpp"

Osinfo::Osinfo () {

	const char *cmd = "sw_vers";
	std::string outp = this->exec(cmd);
	this->_all = outp;
	

	cmd = "sw_vers | grep ProductName";
	outp = this->exec(cmd);
	this->_prodName = outp;

	cmd = "sw_vers | grep ProductVersion";
	outp = this->exec(cmd);
	this->_prodVers = outp;
	cmd = "sw_vers | grep BuildVersion";
	outp = this->exec(cmd);
	this->_BuildVers = outp;
}

Osinfo::Osinfo(Osinfo const & src) {
	operator=( src );
	return ;
}

Osinfo&		Osinfo::operator=( Osinfo const & rhs ) {
	if( this == &rhs )
		return *this;
	this->_prodName = rhs.getName();
	this->_prodVers = rhs.getVers();
	this->_BuildVers = rhs.getBuild();
	this->_cnt = rhs.getCnt();
	return *this;
}

int			Osinfo::getCnt() const {
    return this->_cnt;
}

std::string	Osinfo::getName() const {
    return this->_prodName;
}

std::string	Osinfo::getVers() const {
    return this->_prodVers;
}

std::string Osinfo::getBuild() const {
    return this->_BuildVers;
}

std::string Osinfo::getAll() const {
    return this->_all;
}

Osinfo::~Osinfo(){

    // std::cout << "destructed" << std::endl;
}

std::string Osinfo::exec(const char* cmd) {
	std::array<char, 128> buffer;
	std::string result;
	std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
	if (!pipe) throw std::runtime_error("popen() failed!");
	while (!feof(pipe.get())) {
		if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
			result += buffer.data();
			// result += '\n';
		//    std::cout << "buffer: " << buffer.data() << std::endl;
		//    std::cout << "result: " << result;
	}   
	return result;
}

// std::ostream & operator<<(std::ostream & o, Osinfo const & i){
//     o << i.getName() << '\n' << i.getVers() << '\n' << i.getBuild() <<
//     i.getBuild();
//     return o;
// }
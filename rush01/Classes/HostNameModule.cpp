#include "HostNameModule.hpp"
#include "IMonitorModule.hpp"

HostNameModule::HostNameModule( std::string name ) : _output(), _name( name ) {
	// get string into and store in output
	std::vector<std::string>	out;

	out.push_back(name); // second value
	this->_output = out;
	return ;
}

HostNameModule::HostNameModule( HostNameModule const & copy ) {
	operator=( copy );
	return ;
}

HostNameModule&		HostNameModule::operator=( HostNameModule const & rhs ) {
	if ( this == &rhs )
		return *this;
	
	this->_output = rhs.getOutput();
	this->_name = rhs.getName();
	return *this;
}

HostNameModule::~HostNameModule( void ) {
	return ;
}

std::vector<std::string>	HostNameModule::getOutput( void ) const {
	return this->_output;
}

std::string					HostNameModule::getName( void ) const {
	return this->_name;
}

std::string exec(const char *cmd) {
	
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
#include "NetworkInfo.hpp"

NetworkInfo::NetworkInfo () {
    
    const char *cmd = "top -n0 -l1 | grep Networks";
    std::string outp = this->exec(cmd);
  
    this->_dataPackets = outp;

}

NetworkInfo::NetworkInfo(NetworkInfo const & src) {
    operator=( src );
	return ;
}

NetworkInfo&	NetworkInfo::operator=( NetworkInfo const & rhs ) {
	if( this == &rhs )
		return *this;
	this->_dataPackets = rhs.getDataPackets();
	return *this;
}

NetworkInfo::~NetworkInfo(){
    // std::cout << "destructed" << std::endl;
}

std::string NetworkInfo::getDataPackets() const {
    return this->_dataPackets;
}

std::string NetworkInfo::exec(const char* cmd) {

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

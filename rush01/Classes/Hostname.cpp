#include "Hostname.hpp"

Hostname::Hostname () {
    
    const char *cmd = "hostname && whoami";
    std::string outp = this->exec(cmd);

    this->_hostname = this->exec("hostname");
    this->_username = this->exec("whoami");

}

Hostname::Hostname(Hostname const & src) {
    operator=( src );
	return ;
}

Hostname&	Hostname::operator=( Hostname const & rhs ) {
	if( this == &rhs )
		return *this;
	this->_hostname = rhs.getHostname();
	this->_username = rhs.getUsername();
	return *this;
}

Hostname::~Hostname(){
    // std::cout << "destructed" << std::endl;
}

std::string Hostname::getHostname() const {
    return this->_hostname;
}

std::string Hostname::getUsername() const {
    return this->_username;
}

std::string Hostname::exec(const char* cmd) {
   
   std::array<char, 128> buffer;
   std::string result;
   std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
   if (!pipe) throw std::runtime_error("popen() failed!");
   while (!feof(pipe.get())) {
       if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
           result += buffer.data();
           //result += '\n';
        //    std::cout << "buffer: " << buffer.data() << std::endl;
        //    std::cout << "result: " << result;
   }   
   return result;

}

// std::ostream & operator<<(std::ostream & o, Hostname const & i){
//     o << i.getHostname() << '\n' << i.getUsername(); 
//     return o;
// }
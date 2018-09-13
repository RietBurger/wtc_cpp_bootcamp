#include "Dateinfo.hpp"

Dateinfo::Dateinfo () {
    
    const char *cmd = "date";
    std::string outp = this->exec(cmd);
  
    this->_date = outp;

}

Dateinfo::Dateinfo(Dateinfo const & src) {
    operator=( src );
	return ;
}

Dateinfo&	Dateinfo::operator=( Dateinfo const & rhs ) {
	if( this == &rhs )
		return *this;
	this->_date = rhs.getDate();
	return *this;
}

Dateinfo::~Dateinfo(){
    // std::cout << "destructed" << std::endl;
}

std::string Dateinfo::getDate() const {
    return this->_date;
}

std::string Dateinfo::exec(const char* cmd) {
   
   std::array<char, 128> buffer;
   std::string result;
   std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
   if (!pipe) throw std::runtime_error("popen() failed!");
   while (!feof(pipe.get())) {
       if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
           result += buffer.data();
        //    result += '\n';
        //    std::cout << "buffer: " << buffer.data() << std::endl;
        //    std::cout << "result: " << result;
   }   
   return result;

}

std::ostream & operator<<(std::ostream & o, Dateinfo const & i){
    o << i.getDate(); 
    return o;
}
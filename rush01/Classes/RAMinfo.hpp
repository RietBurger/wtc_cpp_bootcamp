#ifndef RAMINFO_H
# define RAMINFO_H

# include "IMonitorModule.hpp"

class Raminfo : public IMonitorModule {
	public:

        Raminfo();
        Raminfo(Raminfo const & src);
		Raminfo&	operator=( Raminfo const & rhs );
        ~Raminfo();

        int getCnt() const;
		std::string getRaminfo() const;
        std::string getMemReg() const;
        std::string getPhysMem() const;
		std::string getRamAll() const;
        
        void setMemReg();
        void setPhysMem();
		void setRamInfo();
		void setRamAll();

        std::string exec(const char *cmd);

    private:
        int _cnt;

        std::string _memReg;
        std::string _physMem;
		std::string _raminfo;
		std::string _all;

};

#endif
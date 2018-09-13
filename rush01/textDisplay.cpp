#include "Classes/Hostname.hpp"
#include "Classes/Dateinfo.hpp"
#include "Classes/Osinfo.hpp"
#include "Classes/RAMinfo.hpp"
#include "Classes/CPUinfo.hpp"
#include "Classes/NetworkInfo.hpp"
#include "Classes/Ncurses.hpp"
#include "Classes/graphicDisplay.hpp"


#include <unistd.h>

int		main( void ) {

	GraphicDisplay * gui = new GraphicDisplay();
    gui->renderModules("gui");
	/* NCURSES START */
	initscr();
	noecho();
	cbreak();
	curs_set( FALSE );

	// Get terminal screen size
	int		yMax, xMax;
	getmaxyx( stdscr, yMax, xMax );

	/* MENU WINDOW */
	Ncurses*		menu = new Ncurses( yMax, xMax, ((yMax/2)-11), 5 );

	box( menu->getWin(), 0, 0 );
	refresh();
	menu->refreshWin();

	keypad( menu->getWin(), true );
	nodelay( menu->getWin(), true );
	nodelay( stdscr, true);
	
	std::string		choices[ 7 ] = { "Hostname", "OS Info", "Date/Time", "CPU", "RAM", "Network", "EXIT" };
	int				select = 0;
	int				choice = 0;
	int				highlight;
	int				ch;

	refresh();

	for(;;) {
		nodelay( stdscr, true);
		clear();

		box( menu->getWin(), 0, 0 );
		refresh();
		menu->refreshWin();

		

		for(;;) {
			for( int i = 0; i < 7; i++ ) {
				if ( i == highlight ) {
					wattron( menu->getWin(), A_REVERSE );
				}
				mvwprintw( menu->getWin(), i+3, 2, choices[i].c_str() );
				wattroff( menu->getWin(), A_REVERSE );
			}
			choice = wgetch( menu->getWin() );

			switch( choice ) {
				case KEY_UP:
					highlight--;
					if( highlight == -1 )
						highlight = 0;
					break;
				case KEY_DOWN:
					highlight++;
					if( highlight == 7 )
						highlight = 6;
					break;
				default:
					break;
			}
			if( choice == 10 ) {
				if( choices[highlight] == "EXIT" ) {
					select = -1;
					break;
				} else if( choices[highlight] == "Hostname" ) {
					select = 1;
					break;
				} else if( choices[highlight] == "OS Info" ) {
					select = 2;
					break;
				} else if( choices[highlight] == "Date/Time" ) {
					select = 3;
					break;
				} else if( choices[highlight] == "CPU" ) {
					select = 4;
					break;
				} else if( choices[highlight] == "RAM" ) {
					select = 5;
					break;
				} else if( choices[highlight] == "Network" ) {
					select = 6;
					break;
				}
			}
		}

		if ( select == 1) {
			while((ch = getch()) != 10) {
				Hostname*		testHost = new Hostname();
				move( (yMax/2)-10, (xMax/2)-25 );
				menu->renderModules( testHost->getHostname() );
				delete testHost;
				refresh();
			}
		} else if ( select == 2 ) {
			while((ch = getch()) != 10) {
				Osinfo*		testOS = new Osinfo();
				move( (yMax/2)-10, (xMax/2)-25 );
				menu->renderModules( testOS->getName() );
				move( (yMax/2)-9, (xMax/2)-25 );
				menu->renderModules( testOS->getVers() );
				move( (yMax/2)-8, (xMax/2)-25 );
				menu->renderModules( testOS->getBuild() );
				delete testOS;
				refresh();
			}
		} else if ( select == 3 ) {
			while((ch = getch()) != 10) {
				Dateinfo*		testDate = new Dateinfo();
				move( (yMax/2)-10, (xMax/2)-25 );
				menu->renderModules( testDate->getDate() );
				delete testDate;
				refresh();
			}
		} else if ( select == 4 ) {
			while((ch = getch()) != 10) {
				Cpuinfo*			testCpu = new Cpuinfo();
				move( (yMax/2)-10, (xMax/2)-25 );
				menu->renderModules( testCpu->getClockSpeed() );
				// move( (yMax/2)-9, (xMax/2)-25 );
				// menu->renderModules( testCpu->getCPUModule() );
				move( (yMax/2)-8, (xMax/2)-25 );
				menu->renderModules( testCpu->getNumberOfCores() );
				// move( (yMax/2)-7, (xMax/2)-25 );
				// menu->renderModules( testCpu->getCpuUsage() );
				// move( (yMax/2)-6, (xMax/2)-25 );
				// menu->renderModules( testCpu->getCpuSys() );
				// move( (yMax/2)-5, (xMax/2)-25 );
				// menu->renderModules( testCpu->getCpuIdle() );
				delete testCpu;
			}
		} else if ( select == 5 ){
			while((ch = getch()) != 10) {
				Raminfo*			testRam = new Raminfo();
				move( (yMax/2)-10, (xMax/2)-25 );
				menu->renderModules( testRam->getMemReg() );
				delete testRam;
				refresh();
			}
		} else if ( select == 6 ){
			while((ch = getch()) != 10) {
				NetworkInfo*		testNetwork = new NetworkInfo();
				move( (yMax/2)-10, (xMax/2)-25 );
				menu->renderModules( testNetwork->getDataPackets() );
				delete testNetwork;
				refresh();
			}
		} else if ( select == -1 ){
			break ;
		}
	}
	/* ENDING NCURSES */
	delete menu;
	endwin();
	return 0;
}

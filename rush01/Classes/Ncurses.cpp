#include "Ncurses.hpp"

Ncurses::Ncurses( void ) : IMonitorDisplay(), _maxY( 10 ), _maxX( 10 ), _startY( 1 ), _startX( 1 ) {
	
	this->_win = newwin( 10, 10, 1, 1 );
	wrefresh( this->_win );
	return ;
}

Ncurses::Ncurses( int maxY, int maxX, int startY, int startX ) : IMonitorDisplay(),
						_maxY( maxY ), _maxX( maxX ), _startY( startY ), _startX( startX ) {
	
	this->_win = newwin( 14, 15, startY, startX );
	wrefresh( this->_win );
	return ;
}

Ncurses::Ncurses( Ncurses const & copy ) {
	operator=( copy );
	return ;
}

Ncurses::~Ncurses( void ) {
	return ;
}

Ncurses&		Ncurses::operator=( Ncurses const & rhs ) {
	if ( this == &rhs )
		return *this;
	
	this->_maxY = rhs.getMaxY();
	this->_maxX = rhs.getMaxX();
	this->_startY =  rhs.getStartY();
	this->_startX = rhs.getStartX();
	this->_currYPos = rhs.getCurrYPos();
	this->_currXPos = rhs.getCurrXPos();
	return *this;
}

void	Ncurses::renderModules( std::string input ) {
	//move( (this->_maxY/2)-10, (this->_maxX/2)-10 );
	printw(input.c_str());
	//refresh();
}

int		Ncurses::getMaxY( void ) const {
	return this->_maxY;
}

int		Ncurses::getMaxX( void ) const {
	return this->_maxX;
}

int		Ncurses::getStartY( void ) const {
	return this->_startY;
}

int		Ncurses::getStartX( void ) const {
	return this->_startX;
}

int		Ncurses::getCurrYPos( void ) const {
	return this->_currYPos;
}

int		Ncurses::getCurrXPos( void ) const {
	return this->_currXPos;
}

WINDOW*		Ncurses::getWin( void ) const {
	return this->_win;
}

void	Ncurses::setMaxY( int maxY ) {
	this->_maxY = maxY;
}

void	Ncurses::setMaxX( int maxX ) {
	this->_maxX = maxX;
}

void	Ncurses::setStartY( int startY ) {
	this->_startY = startY;
}

void	Ncurses::setStartX( int startX ) {
	this->_startX = startX;
}

void	Ncurses::setCurrYPos( int currYPos ) {
	this->_currYPos = currYPos;
}

void	Ncurses::setCurrXPos( int currXPos ) {
	this->_currXPos = currXPos;
}

void	Ncurses::refreshWin( void ) {
	wrefresh( this->_win );
}

void	Ncurses::moveWin( int y, int x ) {
	mvwin( this->_win, y, x );
}

void	Ncurses::resizeWin( int y, int x ) {
	wresize( this->_win, y, x );
}

void	Ncurses::moveCursorWin( int y, int x ) {
	wmove( this->_win , y, x );
}

void	Ncurses::clearWin( void ) {
	wclear( this->_win );
}



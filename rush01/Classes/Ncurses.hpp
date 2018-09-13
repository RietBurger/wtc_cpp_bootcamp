#ifndef _NCURSES_HPP
# define _NCURSES_HPP

#include "ft_gkrellm.hpp"
#include "IMonitorDisplay.hpp"

class Ncurses : public IMonitorDisplay {
	
	public:
		// Constructors & destructors
		Ncurses( int maxY, int MaxX, int startY, int startX ); // Creates a new window
		Ncurses( Ncurses const & copy ); // Copy constructor
		~Ncurses( void );

		virtual void	renderModules( std::string input );

		// Getters
		int		getMaxY( void ) const;
		int		getMaxX( void ) const;
		int		getStartY( void ) const;
		int		getStartX( void ) const;
		int		getCurrYPos( void ) const;
		int		getCurrXPos( void ) const;
		WINDOW*		getWin( void ) const;

		// Setters
		void	setMaxY( int maxY );
		void	setMaxX( int maxX );
		void	setStartY( int startY );
		void	setStartX( int startX );
		void	setCurrYPos( int currYPos );
		void	setCurrXPos( int currXPos );

		// Window functions
		void	refreshWin( void );
		void	moveWin( int y, int x );
		void	resizeWin( int y, int x );
		void	moveCursorWin( int y, int x );
		void	clearWin( void );

	private:
		// Variables
		Ncurses( void ); // Creates a new window

		// Operator overrides
		Ncurses&		operator=( Ncurses const & rhs );

		int			_maxY;
		int			_maxX;
		int			_startY;
		int			_startX;
		int			_currYPos;
		int			_currXPos;
		WINDOW*		_win;
};

#endif
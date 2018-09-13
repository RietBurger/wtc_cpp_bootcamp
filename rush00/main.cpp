#include "Objects.hpp"
#include "Player.hpp"
#include "Bullets.hpp"
#include "Background.hpp"


int main()
{
        // NCURSES START
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    // get screen size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    // create a WINDOW for our input
    WINDOW * menuwin = newwin(6, xMax -12, yMax-8, 5);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    // keypad(menuwin, true);

    WINDOW * playwin = newwin(20, 50, (yMax/2)-10, 10);
    box(playwin, 0, 0);

    nodelay(playwin, true);
    Player  * p = new Player(playwin, 1, 1, '>', "Pee1");    
	Bullets * blt = new Bullets();
  
    Player  * e = new Player(playwin, 1, 48, '@', "e");
    Player  * e1 = new Player(playwin, 5, 48, '#', "e1");
    Player  * e2 = new Player(playwin, 7, 48, '$', "e2");

    int ind = 5000;
    while (ind > 5000 || p->health >= 10){
        
        std::string health = "Health: " + std::to_string(p->health) + "\n";
        std::string times = "Time Remaining: " + std::to_string(ind) + "\n";
        std::string score = "Score: " + std::to_string(p->score) + "\n";
        std::string all[3] = {health, times, score};
        for (int i = 0; i < 3; i++){
            mvwprintw(menuwin, i+1, 1, all[i].c_str());
        }
 
        p->display();
        e->display();
        int x = 1;
        usleep(20000);
            
        if (p->getmv() == 32)
		{		
                blt->display2(' ');	
				blt->setBullets(playwin, p->_y, p->_x + x, '-', "bullet1");
				blt->display2('-');     
        } 

        blt->display2(' ');
        blt->_count += 1;
        if (blt->_x != xMax -2) {
            blt->_x += 1;
            blt->display();
        }

        e->display2(' ');
        e->_x -= 0.03;
        e->display();
        if (e->_x == p->_x && e->_y == p->_y){
            if (p->health > 10){
                p->health -= 10;
                
            }
            else if (p->health == 10){
                std::cout << "Game Over!" << std::endl;
                usleep(2000000);
                break;
            }
        }

     if (e->_x == 1){
            e->display2(' ');
            e->_x = 48;
            if (e->_y + 3 < e->yMax - 1)
                e->_y += 3;
            else
                e->_y = 1;
        }

        if (blt->_x == e->_x && blt->_y == e->_y){
            e->display2(' ');
            e->_x = 48;
            if (e->_y + 3 < e->yMax - 1)
                e->_y += 3;
            else
                e->_y = 1;
            // blt->_x = xMax +2;
            p->score += 10;
        }
        
        e1->display2(' ');
        e1->_x -= 0.03;
        e1->display();
        if (e1->_x == p->_x && e1->_y == p->_y){
            if (p->health > 10){
                p->health -= 10;
            }
            else if (p->health == 10){
                std::cout << "Game Over!" << std::endl;
                usleep(2000000);
                break;
            }
        }
        if (e1->_x == 1){
            e1->display2(' ');
            e1->_x = 48;
            if (e1->_y + 4 < e->yMax - 1)
                e1->_y += 4;
            else
                e1->_y = 1;
        }

        if (blt->_x == e1->_x && blt->_y == e1->_y){
            e1->display2(' ');
            e1->_x = 48;
            if (e1->_y + 4 < e2->yMax - 1)
                e1->_y += 4;
            else
                e1->_y = 1;
            // blt->_x = xMax +2;
            p->score += 10;
        }

        e2->display2(' ');
        e2->_x -= 0.03;
        e2->display();
        if (e2->_x == p->_x && e2->_y == p->_y){
            if (p->health > 10){
                p->health -= 10;
            }
            else if (p->health == 10){
                std::cout << "Game Over!" << std::endl;
                usleep(2000000);
				break;
            }
        }
        if (e2->_x == 1){
            e2->display2(' ');
            e2->_x = 48;
            if (e2->_y + 5 < e2->yMax - 1)
                e2->_y += 5;
            else
                e2->_y = 1;
        }

        if (blt->_x == e2->_x && blt->_y == e2->_y){
            e2->display2(' ');
            e2->_x = 48;
            if (e2->_y + 5 < e2->yMax - 1)
                e2->_y += 5;
            else
                e2->_y = 1;
            // blt->_x = xMax +2;
            p->score += 10;
        }

        refresh();
        wrefresh(playwin);
        wrefresh(menuwin);
        
        ind--;
    }
    
    // make sure program waits before exiting...
    
    endwin();

    return 0;
}


#include "gol_config.h"
#include <unistd.h>
#include <ncurses.h>
#include "display.h"

/*
 * important variables, defined elsewhere
 */
extern cell_t env[config_NE][config_ME];
extern int STARTX;
extern int STARTY;
extern int ENDX;
extern int ENDY;
extern WINDOW *win;

/*
 * PRIVATE FUNCTIONS
 */
void create_newwin(int height, int width)
{
	win = newwin(height, width, STARTY, STARTX);   //win variable for WINDOW datatype which is defined in ncurses
	box(win, 0, 0); /* 0, 0 gives default characters
	 * for the vertical and horizontal
	 * lines */
	wrefresh(win); /* show that box */

	return;
}

/*
 * PUBLIC FUNCTIONS
 */
void initDisplay(void)
{
	printf("\ninitializing display...\n");
	usleep(2 * config_TL);
	initscr();      //inbuilt function for initialize screen
	cbreak();
	timeout(TIME_OUT);
	keypad(stdscr, TRUE);  //give functionality to use arrow,f1,f2 and many keys
	create_newwin(config_NE, config_ME);
}

void updateDisplay(void)
{
//	ENDX = COLS - 1;
//	ENDY = LINES - 1;

	int i, j;
	wclear(win);
	for (i = STARTX; i != config_ME; ++i)
		for (j = STARTY; j != config_NE; ++j)
			if (env[j][i] == live)
				mvwaddch(win, j, i, CELL_CHAR); //the character ch is put into the window at the current cursor position of the window and the position of the window cursor is advanced
	wrefresh(win);
}

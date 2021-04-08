
#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <ncurses.h>
#include <stdbool.h>

// window parameters
#define CELL_CHAR '*'
#define TIME_OUT  300

/*
 * functions
 */
void initDisplay(void);

void updateDisplay(void);

#endif /* DISPLAY_H_ */

#include <stdlib.h>
#include <ncurses.h>
#include <signal.h>

// note: <curses.h> includes <stdio.h>.

int main(int argc, char *argv[]){
  (void) initscr(); // initialize the curses lib

  mvaddch(0, 0, 'a');
  mvaddch(1, 1, 'b');
  mvaddch(2, 2, 'c');
  mvaddch(3, 3, 'd');

  refresh();

  start_color();
  
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  
  attron(COLOR_PAIR(1));
  mvaddch(4, 4, 'e');
  attroff(COLOR_PAIR(1));
  
  attron(COLOR_PAIR(2));
  mvprintw(5, 5, "hi!", stdscr);
  attroff(COLOR_PAIR(2));

  refresh();

  getch();
  endwin();
  exit(0);
}

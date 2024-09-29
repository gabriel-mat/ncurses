#include <stdlib.h>
#include <ncurses.h>
#include <signal.h>

// note: <curses.h> includes <stdio.h>.

int main(int argc, char *argv[]){
  (void) initscr(); // initialize the curses lib

  mvaddch(0, 0, 'h');
  mvaddch(1, 1, 'e');
  mvaddch(2, 2, 'l');
  mvaddch(3, 3, 'l');
  mvaddch(4, 4, 'o');

  refresh();

  start_color();
  
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  
  attron(COLOR_PAIR(1));
  mvaddch(5, 5, '!');
  attroff(COLOR_PAIR(1));
  
  attron(COLOR_PAIR(2));
  mvprintw(6, 0, "hi!", stdscr);
  attroff(COLOR_PAIR(2));

  refresh();

  getch();
  endwin();
  exit(0);
}

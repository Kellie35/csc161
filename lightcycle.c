#include <ncurses.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

// You can adjust the frame rate to change the game speed. The demo runs at 4 frames per second.
#define FRAME_RATE 4
#define WIDTH 37
#define LENGTH 27

/**
 * Sleep for a given number of milliseconds
 * \param   ms  The number of milliseconds to sleep for
 */
void sleep_ms(size_t ms) {
  struct timespec ts;
  size_t rem = ms % 1000;
  ts.tv_sec = (ms - rem) / 1000;
  ts.tv_nsec = rem * 1000000;

  // Sleep repeatedly as long as nanosleep is interrupted
  while (nanosleep(&ts, &ts) != 0) {}
}

void print_grid(int grid[WIDTH * LENGTH]){
  for (int row = 0; row < LENGTH; row++){
    for (int col = 0; col < WIDTH){
      if (grid[row, col] == 0){
        attron(COLOR_PAIR(0));
        mvprintw(row, col, "  ");
        attroff(COLOR_PAIR(0));
      }
      else if (grid[row, col] == 1){
        attron(COLOR_PAIR(1));
        mvprintw(row, col, "  ");
        attroff(COLOR_PAIR(1));
      }
      else if (grid[row, col] == 2){
        attron(COLOR_PAIR(2));
        mvprintw(row, col, "  ");
        attroff(COLOR_PAIR(2));
      }
      else {
        mvprintw(row, col, "  ");
      }
    }
  }
}

void load_empty(int grid[WIDTH * LENGTH]){
  for (int row = 0; row < LENGTH; row++){
    for (int col = 0; col < WIDTH; col++){
      if (col == 0 || col == 36 || row == 0 || row == 6){
        grid[row, col] = 0;
      }
    }
  }
}

int main() {
  // Set up ncurses
  initscr();              // Initialize the standard window
  noecho();               // Don't display keys when they are typed
  nodelay(stdscr, true);  // Set up non-blocking input with getch()
  keypad(stdscr, true);   // Allow arrow keys
  curs_set(false);        // Hide the cursor

  // Tell ncurses to initialize color support
  start_color();

  // Color pair 0 is white text on a black background
  init_pair(0, COLOR_WHITE, COLOR_BLACK);

  // Color pair 1 is white text on a blue background
  init_pair(1, COLOR_WHITE, COLOR_BLUE);

  // Color pair 2 is white text on a yellow background
  init_pair(2, COLOR_WHITE, COLOR_YELLOW);


  // TODO: Implement the lightcycle game using a game loop
  int grid[WIDTH * LENGTH];
  bool run = true;
  while (run){
    int input;
    while ((input = getch()) != ERR){
      if (input == KEY_UP){
        mvprintw(10, 10, "UP");
      }
      // else if (input == KEY_DOWN){

      // }
      // else if (input == KEY_RIGHT){

      // }
      // else if (input == KEY_LEFT){

      // }
      // else if (input == 'w'){

      // }
      // else if (input == 's'){

      // }
      // else if (input == 'd'){

      // }
      // else if (input == 'a'){

      // }
      // else if (input == ' '){

      // }
    }

    input = getch();

    //display output


  }

  // Shut down
  endwin();
}

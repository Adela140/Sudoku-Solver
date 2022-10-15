#ifndef SUDOKU_H
#define SUDOKU_H

void load_board(const char* filename, char board[9][9]);
void display_board(char board[9][9]);
bool is_complete(char board[9][9]);
bool make_move(const char position[], char digit, char board[9][9]);
bool coordinates_valid(const char position[]);
bool digit_valid(char digit);
bool square_check(const char position[], char digit, char board[9][9]);
bool row_check(const char position[], char digit, char board[9][9]);
bool column_check(const char position[], char digit, char board[9][9]);

#endif

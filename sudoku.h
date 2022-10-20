#ifndef SUDOKU_H
#define SUDOKU_H

void load_board(const char* filename, char board[9][9]);
void display_board(const char board[9][9]);

/* FUNCTION THAT RETURNS TRUE IF A BOARD IS COMPLETE */
bool is_complete(char board[9][9]);

/* FUNCTION THAT RETURNS TRUE IF PLACING DIGIT IN POSITION IS A VALID MOVE, AND UPDATES BOARD IF IT IS*/
bool make_move(const char position[], char digit, char board[9][9]);

/* FUNCTION THAT RETURNS TRUE IF COORDINATES OF POSITION ARE IN RANGE */
bool coordinates_valid(const char position[]);

/* FUNCTION THAT RETURNS TRUE IF DIGIT IS IN RANGE */
bool digit_valid(char digit);

/* FUNCTION THAT RETURNS TRUE IF THE 3X3 SUB-BOARD DOES NOT CONTAIN A DIGIT */
bool subboard_check(const char position[], char digit, const char board[9][9]);

/* FUNCTION THAT RETURNS TRUE IF A ROW DOES NOT CONTAIN A DIGIT */
bool row_check(const char position[], char digit, const char board[9][9]);

/* FUNCTION THAT RETURNS TRUE IF A COLUMN DOES NOT CONTAIN A DIGIT */
bool column_check(const char position[], char digit, const char board[9][9]);

/* FUNCTION THAT OUTPUTS BOARD INTO FILE AND RETURNS TRUE IF BOARD HAS BEEN IT HAS BEEN SUCCESSFULLY SAVED */
bool save_board(const char* filename, const char board[9][9]);

/* FUNCTION THAT SOLVES THE PUZZLE AND RETURNS TRUE IF A SOLUTION TO BOARD HAS BEEN FOUND */
bool solve_board(char board[9][9]);

/* FUNCTION THAT FINDS THE NEXT EMPTY POSITION AND UPDATES VALUES OF ROW AND COLUMN INDEXES */
void find_empty_position(int &row, int &column, const char board[9][9]);

#endif

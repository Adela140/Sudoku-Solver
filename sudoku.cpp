#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"

using namespace std;

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char* filename, char board[9][9]) {

  cout << "Loading Sudoku board from file '" << filename << "'... ";

  ifstream in(filename);
  if (!in) {
    cout << "Failed!\n";
  }
  assert(in);

  char buffer[512];

  int row = 0;
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    row++;
    in.getline(buffer,512);
  }

  cout << ((row == 9) ? "Success!" : "Failed!") << '\n';
  assert(row == 9);
}

/* internal helper function */
void print_frame(int row) {
  if (!(row % 3)) {
    cout << "  +===========+===========+===========+\n";
  } else {
    cout << "  +---+---+---+---+---+---+---+---+---+\n";
  }
}

/* internal helper function */
void print_row(const char* data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|\n";
}

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]) {
  cout << "    ";
  for (int r=0; r<9; r++) {
    cout << (char) ('1'+r) << "   ";
  }
  cout << '\n';
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}

/* Creating a new type 'Logical', where False=0 and True=1 */
enum Logical {False, True};

/*============================ QUESTION 1 ============================*/

/* DEFINITION OF FUNCTION 'is_complete(board)' */
/* The function returns false if any of the board positions in 
   the 9x9 board matrix are not occupied by a character between 
   '1' and '9', and returns true otherwise*/

bool is_complete(char board[9][9]){

  for(int row=0; row<9; row++){
    for(int column=0; column<9; column++){
      // return false if not a digit or if equal to '0'.
      if(!isdigit(board[row][column]) || board[row][column]=='0') 
	 return False;
      }
  }
    return True;
}
/* END OF FUNCTION DEFINITION */

/*============================ QUESTION 2 ============================*/

/* FUNCTION DEFINITION OF 'make_move(position, digit, board)'
 * It attempts to place a digit on a Sudoku board at a given position 
 * This function returns false if:
   1) the digit is already present in the given row, 
      column or the 3x3 sub-board, or
   2) the arguments passed for position or digit are not valid, or
   3) the position is already occupied 
 * Otherwise it returns true and the board is updated to contain the 
   digit at the particular position 
 * This function uses the following helper functions: 
   'coordinates_valid(position)', 'digit_valid(digit)', 
   'subboard_check(position, digit, board)', 
   'row_check(position, digit, board)' and 
   'column_check(position, digit, row)'.*/

bool make_move(const char position[], char digit, char board[9][9]){
  // Convert the character array 'position' to integer indeces
  int row_index=position[0]-'A';
  int column_index=position[1]-'1';

  // Check if the position is empty (contains '.').
  // If not empty, return false and move is invalid
  if(board[row_index][column_index]!='.') {
    return False;
  }

  // Check if the position passed into the function is valid.
  // Return false if position is out of range
  if(!coordinates_valid(position)){
      return False;
  }

  // Check if the digit passed into the function is valid.
  // Return false if digit is out of range
  if(!digit_valid(digit)){
      return False;
  }

  // Return true if the move is valid with respect to the
  // relevant sub-board, row and column.
  if(subboard_check(position, digit, board) &&
     row_check(position,digit,board) &&
     column_check(position,digit,board)){

    board[row_index][column_index]=digit;
    return True;
  }
  return False;
}
/* END OF FUNCTION DEFINITION */
    
/* FUNCTION DEFINITION OF 'coordinates_valid(position)' 
 * Returns true if the coordinates of the position are in range 
 * Returns false if the argument for position is more than 2 characters 
   (not including the sentinel character), or if the first character 
   is not between 'A' to 'I', or if the second character is not 
   between '1' to '9'.*/
bool coordinates_valid(const char position[]){
  if (strlen(position)==2){
    if (position[0]>='A' && position[0]<='I'){
      if (position[1]>='1' && position[1]<='9')
        return True;
  }
  }
  return False;
}
/* END OF FUNCTION DEFINITION */

/* FUNCTION DEFINITION OF 'digit_valid(digit)'
 * Returns true if digit lies between '1' and '9', 
   otherwise returns false */
bool digit_valid(char digit){
  if(digit>='1' && digit<='9')
    return True;
  return False;
}
/* END OF FUNCTION DEFINITION */

/* FUNCTION DEFINITION OF 'subboard_check(position, digit, board)'
 * It checks whether the 3x3 subboard contains 'digit', by setting 
   the starting point to the upper left corner of the appropriate 
   sub-board and interating through the sub-board.
 * Returns true when the digit does not already appear in the square 
   so the move is valid, otherwise returns false */
bool subboard_check(const char position[], char digit, const char board[9][9]){
  int row_start, column_start;
  // set row_start to the first row in the appropriate sub-board
  if(position[0]>='A' && position[0]<='C')
    row_start=0;
  else if(position[0]>='D' && position[0]<='F')
    row_start=3;
  else
    row_start=6;

  // set column_start to the first column in the appropriate sub-board
  if(position[1]>='1' && position[1]<='3')
    column_start=0;
  else if(position[1]>='4' && position[1]<='6')
    column_start=3;
  else
    column_start=6;

  // iterate through the sub-board and return false if digit is present
  for(int row=row_start;row<row_start+3; row++){
    for(int column=column_start; column<column_start+3; column++){
      if(board[row][column]==digit)
	return False;
    }
  }
  // if digit not present in the sub-board, return true
  return True;
}
/* END OF FUNCTION DEFINITION*/

/* FUNCTION DEFINITION OF 'row_check(position, digit, board)'
 * Returns true when the digit does not already appear in the 
   relevant row, otherwise returns false */
bool row_check(const char position[], char digit, const char board[9][9]){
  // convert the first character in position to integer for the row index
  int row_index= position[0]-'A';
  // iterate through the row and return false if digit is present
  for(int column=0; column<9; column++){
    if(board[row_index][column]==digit)
      return False;
  }
  // if digit not present in the row, return true
  return True;
}
/* END OF FUNCTION DEFINITION */

/* FUNCTION DEFINITION OF 'column_check(position, digit, board)'
 * Returns true when the digit does not already appear in the 
   relevant column, otherwise returns false */
bool column_check(const char position[], char digit, const char board[9][9]){
  // convert the second character in position to integer indicating the column index
  int column_index=position[1]-'1';
  // iterate through the column and return false if digit is present
  for(int row=0; row<9; row++){
    if(board[row][column_index]==digit)
      return False;
  }
  // if digit not present in the column, return true
  return True;
}
/* END OF FUNCTION DEFINITION */

/*============================ QUESTION 3 ============================*/

/* FUNCTION DEFINITION OF 'save_board(filename, board)'
 * Outputs board into file called filename 
 * Returns true if it has been output successfully, 
   otherwise returns false*/
bool save_board(const char* filename, const char board[9][9]){

  ofstream out(filename);
  // return false if filename is read-only
  if(!out){
    return False;
   }
  
  int row=0;
  while(out && row<9){
    for(int column=0; column<9; column++){
      /* return false if the board contains a character that
         is neither '.' or a digit, or if it contains '0'.*/
      if (!(board[row][column] == '.' || isdigit(board[row][column])) || board[row][column]=='0')
	return False;
      out.put(board[row][column]);
    }
    out.put('\n');
    row++;
  }
  // return false if we are not at the end of the whole board
  if (row!=9)
    return False;

  // if saving successful, disconnect the output stream and return true
  out.close();
  return True;
 
}
/* END OF FUNCTION DEFINITION */

/*============================ QUESTION 4 ============================*/

/* FUNCTION DEFINITION OF 'solve_board(board)'
 * Attempts to solve the puzzle recursively 
 * Returns true if a solution is found, leaving board with the solution 
 * Returns false if solution is not found and leaves board in 
   the original state
 * Uses a helper function find_empty_position(row,column,position,board) 
   which looks for the next empty position in board
 * Note: the static variables used for Question 5 have been commented out   */
bool solve_board(char board[9][9]){

  /* STATIC VARIBLES USED FOR QUESTION 5 */
  //static int backtrack_count=0;
  //static int depth =0;
  //depth++;
  //cout<< "depth = " << depth<<endl; 

  int row=0, column=0;

  // return true if board has been completed
  if(is_complete(board)){
       return True;
  }
  // find the next empty position.
  // This void function changes integer values of row and column
  find_empty_position(row,column,board);
  
  // for the empty position, try each digit from '1' to '9'
  for(char digit='1'; digit<='9'; digit++){
    // convert integers row and column of empty index to valid 'position' argument (of type char)
    char position[]={(char)(row+'A'),(char)(column+'1')};
    /* If it is valid to place digit in position, call the solve_board
       function again, which will try to input a digit for the next 
       empty position.
       Returns true if it assigned the correct digit, given all the 
       following empty positions have also been assigned the correct 
       digit */
    if(make_move(position,digit,board)){
      if(solve_board(board))
	return True;
      
      // If it was unsuccessful, assign '.' to the board position.
      board[row][column]='.';
      
      /* STATIC VARIABLE USED TO COUNT BACKTRACKING FOR QUESTION 5*/
      //backtrack_count++;
      //cout<< "Backtrack_count= "<< backtrack_count<<endl;
    }
  }
  // If none of the digits are valid for the position, return false
  return False;
}
/* END OF FUNCTION DEFINITION */

/* FUNCTION DEFINITION OF 'find_empty_position(row,column,board)
 * As row and column are reference parameters, they are changed as we 
   iterate through the board matrix */
void find_empty_position(int &row, int &column, const char board[9][9]){
  for(row=0; row<9; row++){
    for(column=0; column<9; column++){
      // when an empty position is found (containing '.'), return the function
      if (board[row][column]=='.')
	return;
    }
  }
}
/* END OF FUNCTION DEFINITION */
  
 

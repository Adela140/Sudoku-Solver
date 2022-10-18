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

/* QUESTION 1: function 'is_complete(board)', which checks if the Sudoku board is complete and returns false if any of the board positions are not occupied by a real number.*/

bool is_complete(char board[9][9]){

  for(int row=0; row<9; row++){
    for(int column=0; column<9; column++){
      if(!isdigit(board[row][column]))
	 return 0;
      }
  }
    return 1;
}
/* QUESTION 2: function 'make_move(position, digit, board) that attempts to place a digit on a Sudoku board at a gien position*/
/* This function uses the following helper function: 'coordinates_valid(position)', 'digit_valid(digit)', 'square_check(position, digit, board)', 'row_check(position, digit, board)' and 'column_check(position, digit, row)'.*/

bool make_move(const char position[], char digit, char board[9][9]){
  int row_index=position[0]-65;
  int column_index=position[1]-49;

  // making sure that the posiytion is empty. If not empty, return 0 and move is invalid.
  if(board[row_index][column_index]!='.') {
    cout << "Illegal move: Position filled " << position << " " << row_index << " " << column_index << endl;
    return 0;
  }
  
  if(!coordinates_valid(position)){
      return 0;
  }
  if(!digit_valid(digit)){
      return 0;
  }
  
  if(square_check(position, digit, board) && row_check(position,digit,board) && column_check(position,digit,board)){
    board[row_index][column_index]=digit;
    return 1;
  }
  return 0;
}
    
/* boolean function that checks if the board coordinates are valid coordinates*/
bool coordinates_valid(const char position[]){
  if (strlen(position)==2){
    if (position[0]>='A' && position[0]<='I'){
      if(position[1]>='1' && position[1]<='9')
        return 1;
  }
  }
  return 0;
}

/* boolean funciton which checks if the digit to be placed in the board is valid*/
bool digit_valid(char digit){
  if(digit>='1' && digit<='9')
    return 1;
  return 0;
}

/* This boolean function checks whether the 3x3 square contains a certain digit, by setting the starting point of the for loop to the upper left corner of the appropriate square. It returns true when the digit does not already appear and the move is valid. */
bool square_check(const char position[], char digit, char board[9][9]){
  int row_start, column_start;
  if(position[0]>='A' && position[0]<='C')
    row_start=0;
  else if(position[0]>='D' && position[0]<='F')
    row_start=3;
  else
    row_start=6;

  if(position[1]>='1' && position[1]<='3')
    column_start=0;
  else if(position[1]>='4' && position[1]<='6')
    column_start=3;
  else
    column_start=6;

  for(int i=row_start;i<row_start+3; i++){
    for(int j=column_start; j<column_start+3; j++){
      if(board[i][j]==digit)
	return 0;
    }
  }
  return 1;
}

/* boolean function that checks if a certain digit does not already appear in a particular row on board. It returns true when the digit does not already appear and the move is valid.*/
bool row_check(const char position[], char digit, char board[9][9]){
  int row_index= position[0]-65;
  for(int i=0; i<9; i++){
    if(board[row_index][i]==digit)
      return 0;
  }
  return 1;
}
/* boolean function that checks if a certain digit does not already appear in a particular column on board. It returns true when the digit does not already appear and the move is valid.*/

bool column_check(const char position[], char digit, char board[9][9]){
  int column_index=position[1]-49;
  for(int i=0; i<9; i++){
    if(board[i][column_index]==digit)
      return 0;
  }
  return 1;
}

/* QUESTION 3 */

bool save_board(const char* filename, const char board[9][9]){

  ofstream out(filename);
  if(!out){
    //cout<<"Failed!"<<endl;
    return 0;
   }
  // assert(out);
  
  int row=0;
  while(out && row<9){
    for(int n=0; n<9; n++){
      if (!(board[row][n] == '.' || isdigit(board[row][n])))
	return 0;
      //assert(board[row][n] == '.' || isdigit(board[row][n]));
      out.put(board[row][n]);
    }
    out.put('\n');
    row++;
  }
  if (row!=9)
    return 0;

  //assert(row==9);
  out.close();
  return 1;
 
}

/*QUESTION 4*/
bool solve_board(char board[9][9]){
  static int backtrack_count=0;
  static int depth =0;
  depth++;
  cout<< "depth = " << depth<<endl;

  
  char position[3];
  int row=0, column=0;
  
  if(is_complete(board)){
    return 1;
  }
  // Find the next empty position. This void function changes row and column.
  find_empty_position(row,column,position,board);
  
  // For the empty position, try each digit from 1 to 9
  for(char digit='1'; digit<='9'; digit++){
    if(make_move(position,digit,board)){
      if(solve_board(board))
	return 1;
      // If it was unsuccessful, assign '.' to the board index.//
      board[row][column]='.';
      backtrack_count++;
      cout<< backtrack_count<<endl;
    }
  }
  return 0;
} 

void find_empty_position(int &row, int &column, char position[], const char board[9][9]){
  for(row=0; row<9; row++){
    for(column=0; column<9; column++){
      if (board[row][column]=='.'){
        position[0]=(char) row+65;
	position[1]=(char) column+49;
	position[2]='\0';
	return;
      }
    }
  }
}
  
  
 

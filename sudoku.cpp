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
void display_board(char board[9][9]) {
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

/* QUESTION 1: function 'is_complete(board)', which checks if the Sudoku board is complete and returns false if any og the board positions are not occupied by a real number.*/

bool is_complete(char board[9][9]){

  for(int row=0; row<9; row++){
    for(int column=0; column<9; column++){
      if(!isdigit(board[row][column]))
	 return 0;
      }
  }
    return 1;
}

bool make_move(const char position[], char digit, char board[9][9]){
  int row_index=position[0]-65;
  int column_index=position[1]-49;
  
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

/* This boolean function checks whether the 3x3 square contains a certain digit, by setting the starting point of the for loop to the upper left corner of the appropriate square. */
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

bool row_check(const char position[], char digit, char board[9][9]){
  int row_index= position[0]-65;
  for(int i=0; i<9; i++){
    if(board[row_index][i]==digit)
      return 0;
  }
  return 1;
}

bool column_check(const char position[], char digit, char board[9][9]){
  int column_index=position[1]-49;
  for(int i=0; i<9; i++){
    if(board[i][column_index]==digit)
      return 0;
  }
  return 1;
}

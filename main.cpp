#include <iostream>
#include <cstdio>
#include "sudoku.h"

//hello//

using namespace std;

int main() {

  char board[9][9];

  /* This section illustrates the use of the pre-supplied helper functions. */
  // cout << "============= Pre-supplied functions =============\n\n";

  cout << "Calling load_board():\n";
  load_board("easy.dat", board);

  cout << '\n';
	cout << "Displaying Sudoku board with display_board():\n";
  display_board(board);
  cout << "Done!\n\n";

   cout << "=================== Question 1 ===================\n\n";

  load_board("easy.dat", board);
  cout << "Board is ";
  if (!is_complete(board)) {
    cout << "NOT ";
  }
  cout << "complete.\n\n";

  load_board("easy-solution.dat", board);
  cout << "Board is ";
  if (!is_complete(board)) {
    cout << "NOT ";
  }
  cout << "complete.\n\n";

  // Testing a board which includes characters that are neither a digit nor a '.'
  // One position in the solved puzzle 'easy-solution.dat' is changed to an '<'
  // Returns false as the function returns true only if all the positions are occupied by digits
  load_board("easy-solution.dat", board);
  board[5][5]='<';
  cout << "Board which is full but has '<' in one position is ";
  if (!is_complete(board)) {
    cout << "NOT ";
  }
  cout << "complete.\n\n";

  // Testing a board which has a '0' in one position as it otherwise complete
  // Returns false as '0' is not a valid digit 
  load_board("easy-solution.dat", board);
  board[5][5]='0';
  cout << "Board which is full but has a '0' in one position is ";
  if (!is_complete(board)) {
    cout << "NOT ";
  }
  cout << "complete.\n\n";

  // Testing a board which only has 5 rows
  // The columns and rows outside of these dimensions are removed from 'easy-solution.dat'
  // Returns false as the board contains less rows than required
  load_board("easy-solution.dat", board);
  for (int row=5; row<9; row++){
    for(int column=0; column<9; column++)
	board[row][column]='\0';
  }
  cout << "Board that only has 5 rows is ";
  if (!is_complete(board)) {
    cout << "NOT ";
  }
  cout << "complete.\n\n";
  
  
  cout << "=================== Question 2 ===================\n\n";

  load_board("easy.dat", board);

  // Should be OK
  cout << "Putting '1' into I8 is ";
  if (!make_move("I8", '1', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  // Returns true as the arguments passed into the function are valid and there is not already a '2' in either row C, column 2 or the sub-board, and the position is initially empty.
  // Changes board to includ '2' in C7
  cout << "Putting '2' into C7 is ";
  if (!make_move("C7", '2', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  // Testing column_check function
  // Try putting '8' into a row and sub-board that do not contain the digit, but such that column does
  // Returns false as there is already an '8' in column 6, and does not change board
  cout << "Putting '8' into G6 is ";
  if (!make_move("G6", '8', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  // Testing row_check function
  // Try putting '4' into a column and sub-board that do not contain the digit, but such that the row does
  // Returns false as there is already a '4' in row D, and does not change board                 
  cout << "Putting '4' into D7 is ";
  if (!make_move("D7", '4', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  // Testing subboard_check function
  // Try putting '6' into a row and column that do not contain the digit but such that the sub-board does
  // Returns false since there is already a '6' in the 3x3 square from D1 to F3, and does not change board
  cout << "Putting '6' into F3 is ";
  if (!make_move("F3", '6', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  // Testing coodinates_valid function
  // Returns false since J2 is out of range
  cout << "Putting '9' into J2 is ";
  if (!make_move("J2", '9', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  // Testing digit_valid function
  // Returns false since '0' is not a valid digit to be passed as an argument
  cout << "Putting '0' into E5 is ";
  if (!make_move("E5",'0', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  // Testing placing a digit to a non-empty position
  // Returns false as the position A4 is already occupied (it is not '.')
  cout << "Putting '5' into A4 is ";
  if (!make_move("A4",'5', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  
  cout << "=================== Question 3 ===================\n\n";

  load_board("easy.dat", board);
  if (save_board("easy-copy.dat", board)) {
    cout << "Save board to 'easy-copy.dat' successful.\n";
  } else {
    cout << "Save board failed.\n";
  }
  cout << '\n';

  // Testing saving a board that contains an invalid character
  // One position in the easy.dat board is changed to '!'
  // Returns false because board contains an invalid character
  load_board("easy.dat", board);
  board[5][5]='!';
  if (save_board("easy-copy1.dat", board)) {
    cout << "Save board containing '!' to 'easy-copy1.dat' successful.\n";
  } else {
    cout << "Save board containing '!' failed.\n";
  }
  cout << '\n';

  // Testing saving a board that contains an invalid character
  // One position in the easy.dat board is changed to '0'
  // Returns false as '0' is not a valid character the saved board should contain
  load_board("easy.dat", board);
  board[5][5]='0';
  if (save_board("easy-copy2.dat", board)) {
    cout << "Save board containing '0' to 'easy-copy2.dat' successful.\n";
  } else {
    cout << "Save board containing '0' failed.\n";
  }
  cout << '\n';

  // Testing saving a board that is completed (and only contains valid digits)
  // Returns true since all the characters in the board are valid and the dimensions are correct
  load_board("easy-solution.dat", board);
  if (save_board("easy-solution-copy.dat", board)) {
    cout << "Save completed board to 'easy-solution-copy.dat' successful.\n";
  } else {
    cout << "Save complete board failed.\n";
  }
  cout << '\n';

  // Testing saving a board that only contains '.'
  // Created a file 'empty.dat' that consists of 9x9 matrix of '.'
  // Returns true since '.' is a valid character and dimensions are correct
  load_board("empty.dat", board);
  if (save_board("empty-copy.dat", board)) {
    cout << "Save empty board to 'empty-copy' successful.\n";
  } else {
    cout << "Save empty board failed.\n";
  }
  cout << '\n';

  // Testing saving a board that has only 5 rows
  // The columns and rows outside of these dimensions are removed from 'easy-solution.dat'
  // Returns false as the board contains less rows than required
  load_board("easy-solution.dat", board);
  for (int row=5; row<9; row++){
    for(int column=0; column<9; column++){
	board[row][column]='\0';
      }
  }
  if (save_board("short.dat", board)) {
    cout << "Save board that only has 5 rows to 'short.dat' successful.\n";
  } else {
    cout << "Save board that only has 5 rows failed.\n";
  }
  cout << '\n';
  
  //cout << "=================== Question 4 ===================\n\n";

  load_board("easy.dat", board);
  if (solve_board(board)) {
    cout << "The 'easy' board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
    display_board(board);
  }
  cout << '\n';

  load_board("medium.dat", board);
  if (solve_board(board)) {
    cout << "The 'medium' board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
  }
  cout << '\n';

  // Testing an unsolvable board
  // Easy-solution.dat is changed so that position A1 is emptied (assigned to '.') and position A2 is assigned '6' so that '6' can no longer be assigned to A1
  // Returns false as there is no solution
  load_board("easy-solution.dat", board);
  board[0][0]='.';
  board[0][1]='6';
  if (solve_board(board)) {
    cout << "The board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
    display_board(board);
  }
  cout << '\n';

  // Testing an empty board 'empty.dat'
  // This should have a solution that clearly shows the iteration through the digits
  // Returns true as any solution can be input in an empty board
  load_board("empty.dat", board);
  if (solve_board(board)) {
    cout << "The empty board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
    display_board(board);
  }
  cout << '\n';

  // Testing a board which contains a position with an invalid character
  // Easy-solution.dat is changed so that A1 is empty and A2 is assigned '?'
  // Returns false as the 'is_complete' check inside the solve_board function is never true
  load_board("easy-solution.dat", board);
  board[0][0]='.';
  board[0][1]='?';
  if (solve_board(board)) {
    cout << "The board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
    display_board(board);
  }
  cout << '\n';

  cout << "=================== Question 5 ===================\n\n";
  // The difficulty of a board is determined by the number of times
  // the recursive function 'solve_board(board)' is called when solving the board
  // including the number of times the program makes a mistake and has to backtrack
  // These numbers are stored in static integers 'depth' and 'backtrack_count'
  // !!Note: the static variables need to be uncommented in the solve_board function in sudoku.cpp
  // Note#2: these tests have to be run separately to reset the static variables to 0.
  
  //MYSTERY1.DAT: depth = 421547 and backtrack_count=421488.
  // load_board("mystery1.dat", board);
  // if (solve_board(board)) {
  //   cout << "The mystery1 board has a solution:\n";
  //   display_board(board);
  // } else {
  //   cout << "A solution cannot be found.\n";
  //   display_board(board);
  // }
  // cout << '\n';

  // //MYSTERY2.DAT: imossible to solve
  // load_board("mystery2.dat", board);
  // if (solve_board(board)) {
  //   cout << "The mystery2 board has a solution:\n";
  //   display_board(board);
  // } else {
  //   cout << "A solution cannot be found.\n";
  //   display_board(board);
  // }
  // cout << '\n';

  // //MYSTERY3.DAT: depth = 14134 and backtrack_count=14076
  // load_board("mystery3.dat", board);
  // if (solve_board(board)) {
  //   cout << "The mystery3 board has a solution:\n";
  //   display_board(board);
  // } else {
  //   cout << "A solution cannot be found.\n";
  //   display_board(board);
  // }
  // cout << '\n';

  // //TESTING EASY.DAT AND MEDIUM.DAT FOR CONSISTENCY //
  
  //EASY.DAT: depth = 2172 and backtrack_count = 2116
  // load_board("easy.dat", board);
  // if (solve_board(board)) {
  //   cout << "The easy.dat board has a solution:\n";
  //   display_board(board);
  // } else {
  //   cout << "A solution cannot be found.\n";
  //   display_board(board);
  // }
  // cout << '\n';

  // // MEDIUM.DAT: depth = 15662 and backtrack_count = 15605
  //  load_board("medium.dat", board);
  // if (solve_board(board)) {
  //   cout << "The medium.dat board has a solution:\n";
  //   display_board(board);
  // } else {
  //   cout << "A solution cannot be found.\n";
  //   display_board(board);
  // }
  // cout << '\n';


  return 0;
}

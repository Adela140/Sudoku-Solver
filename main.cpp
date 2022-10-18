#include <iostream>
#include <cstdio>
#include "sudoku.h"

//hello//

using namespace std;

int main() {

  char board[9][9];

  /* This section illustrates the use of the pre-supplied helper functions. */
  // cout << "============= Pre-supplied functions =============\n\n";

  // cout << "Calling load_board():\n";
  // load_board("easy.dat", board);

  // cout << '\n';
  // 	cout << "Displaying Sudoku board with display_board():\n";
  // display_board(board);
  // cout << "Done!\n\n";

   // cout << "=================== Question 1 ===================\n\n";

  // load_board("easy.dat", board);
  // cout << "Board is ";
  // if (!is_complete(board)) {
  //   cout << "NOT ";
  // }
  // cout << "complete.\n\n";

  // load_board("easy-solution.dat", board);
  // cout << "Board is ";
  // if (!is_complete(board)) {
  //   cout << "NOT ";
  // }
  // cout << "complete.\n\n";
  
  // cout << "=================== Question 2 ===================\n\n";

  // load_board("easy.dat", board);

  // // Should be OK
  // cout << "Putting '1' into I8 is ";
  // if (!make_move("I8", '1', board)) {
  //   cout << "NOT ";
  // }
  // cout << "a valid move. The board is:\n";
  // display_board(board);

  // // this should also be valid
  // cout << "Putting '2' into C7 is ";
  // if (!make_move("C7", '2', board)) {
  //   cout << "NOT ";
  // }
  // cout << "a valid move. The board is:\n";
  // display_board(board);

  // // this should not be valid - testing column check
  // cout << "Putting '8' into G6 is ";
  // if (!make_move("G6", '8', board)) {
  //   cout << "NOT ";
  // }
  // cout << "a valid move. The board is:\n";
  // display_board(board);

  // // this should not be valid - testing row check                                                                                 
  // cout << "Putting '4' into D7 is ";
  // if (!make_move("D7", '4', board)) {
  //   cout << "NOT ";
  // }
  // cout << "a valid move. The board is:\n";
  // display_board(board);

  // // this should not be valid - testing square check
  // cout << "Putting '6' into F3 is ";
  // if (!make_move("F3", '6', board)) {
  //   cout << "NOT ";
  // }
  // cout << "a valid move. The board is:\n";
  // display_board(board);
  
  // // this shouldn't be valid since input not valid
  // cout << "Putting '9' into J2 is ";
  // if (!make_move("J2", '9', board)) {
  //   cout << "NOT ";
  // }
  // cout << "a valid move. The board is:\n";
  // display_board(board);

  // // this shouldn't be valid since input not valid
  // cout << "Putting '0' into E5 is ";
  // if (!make_move("E5", '0', board)) {
  //   cout << "NOT ";
  // }
  // cout << "a valid move. The board is:\n";
  // display_board(board);

  //  cout << "=================== Question 3 ===================\n\n";

  // load_board("easy.dat", board);
  // if (save_board("easy-copy3.dat", board)) {
  //   cout << "Save board to 'easy-copy.dat' successful.\n";
  // } else {
  //   cout << "Save board failed.\n";
  // }
  // cout << '\n';

  //cout << "=================== Question 4 ===================\n\n";

  // load_board("easy.dat", board);
  // if (solve_board(board)) {
  //   cout << "The 'easy' board has a solution:\n";
  //   display_board(board);
  // } else {
  //   cout << "A solution cannot be found.\n";
  //   display_board(board);
  // }
  // cout << '\n';

  // load_board("medium.dat", board);
  // if (solve_board(board)) {
  //   cout << "The 'medium' board has a solution:\n";
  //   display_board(board);
  // } else {
  //   cout << "A solution cannot be found.\n";
  // }
  // cout << '\n';

  // // // write more tests

  cout << "=================== Question 5 ===================\n\n";
  //The difficulty of a board is determined by the number of times
  // the recursive function 'solve_board(board)' is called when solving the board.
  // This number is stored in a static integer 'depth'.
  
  //MYSTERY1.DAT: the depth is 421547.
  load_board("mystery1.dat", board);
  if (solve_board(board)) {
    cout << "The mystery1 board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
    display_board(board);
  }
  cout << '\n';

  //MYSTERY2.DAT: imossible to solve
  load_board("mystery2.dat", board);
  if (solve_board(board)) {
    cout << "The mystery2 board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
    display_board(board);
  }
  cout << '\n';

  //MYSTERY3.DAT: the depth is 14134
  load_board("mystery3.dat", board);
  if (solve_board(board)) {
    cout << "The mystery3 board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
    display_board(board);
  }
  cout << '\n';

  //TESTING EASY.DAT AND MEDIUM.DAT FOR CONSISTENCY //
  
  //EASY.DAT: the depth is 2172
  load_board("easy.dat", board);
  if (solve_board(board)) {
    cout << "The easy.dat board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
    display_board(board);
  }
  cout << '\n';

  // MEDIUM.DAT: the depth is 15662
   load_board("medium.dat", board);
  if (solve_board(board)) {
    cout << "The medium.dat board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
    display_board(board);
  }
  cout << '\n';

  
  // // write more tests

  return 0;
}

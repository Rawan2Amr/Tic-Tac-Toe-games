// Class definition for X_O_Board class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;

// Set the board
Connect_four_Board::Connect_four_Board() {
   n_rows =6;
   n_cols = 7;
   board = new char*[n_rows];
   for (int i = 0; i < n_rows; i++) {
      board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++)
         board[i][j] = 0;
   }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Connect_four_Board::update_board (int x ,int y, char mark){
   // Only update if move is valid
   for ( x = 5 ; x>=0;x--){
   if (!( y < 0 || y > 7) && (board[x][y] == 0)) {
       board[x][y] = toupper(mark);
       n_moves++;
       return true;
   }
   }
      return false;
}

// Display the board and the pieces on it
void Connect_four_Board::display_board() {
   for (int i: {0,1,2,3,4,5}) {
      cout << "\n| ";
      for (int j: {0,1,2,3,4,5,6}) {
         cout <<  j << setw(2) << board [i][j] << " |";
      }
      cout << "\n-------------------------------------";
   }
   cout << endl;
}

// Returns true if there is any winner
// either X or O

bool Connect_four_Board::is_winner() {
//    char row_win[4], col_win[4], diag_win[4];
    for (int i = 5;i>=0;i--){
        for(int j = 0 ; j<4 ;j++){
            if (board[i][j] == board[i][j+1] && board[i][j]== board[i][j+2] && board[i][j]== board[i][j+3] && (board[i][j]!=0)){
                return true;
            }
        }
    }
    for (int i = 0;i<7;i++){
        for(int j = 5 ; j>=3 ;j--){
            if ((board[j][i] == board[j-1][i] && board[j][i] == board[j-2][i] && board[j][i] == board[j-3][i]) && (board[j][i]!=0)){
                return true;
            }
        }
    }
    for (int i = 0;i<3;i++){
        for(int j = 0 ; j<4 ;j++){
            if (((board[i][j] == board[i+1][j+1] && board[i][j] == board[i+2][j+2] && board[i][j]== board[i+3][j+3] ) && (board[i][j]!=0))
               ||(( board[i][j+3] == board[i+1][j+2] && board[i][j+3] == board[i+2][j+1] && board[i][j+3]== board[i+3][j])
               && board[i][j+3]!=0)){
                return true;
            }
        }
    }

    return false;
}

// Return true if 42 moves are done and no winner
bool Connect_four_Board::is_draw() {
    return (n_moves == 42 && !is_winner());
}

bool Connect_four_Board::game_is_over () {
    return n_moves >= 42;
}


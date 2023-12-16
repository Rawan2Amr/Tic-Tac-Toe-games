//
// Created by PC on 12/15/2023.
//
// Class definition for X_O_pyramic_Board_ class
// Created by _tasneem_ on 12/14/2023.

#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../BoardGame_Classes.hpp"
using namespace std;
// Set the board
X_O_pyramic_Board::X_O_pyramic_Board () {
    n_rows =3;
    n_cols = 5;
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
bool X_O_pyramic_Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 2|| y < 0 || y > 4 ||(x==0&& y !=2)||(x==1&&(y ==0 || y ==4)) ) && (board[x][y] == 0)) {

        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}
void X_O_pyramic_Board::display_board() {
    for(int i:{0}) {
        cout << "\n| ";
        for (int j: {0, 1, 3, 4}) {
            cout << "    ";
        }
        for(int j :{2}) {
            cout << " |(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << "                   |";
        }
    }
    for (int i: {1}) {
        cout << "\n| ";
        //  cout << setw(2);
        cout << "        ";
        for (int j: {1,2,3}) {

            cout << "|(" << i << "," << j << ") ";
            cout << setw(2) << board[i][j] << "";
        }
        cout << "         |";
        for (int i: {2}) {
            cout << "\n| ";
            for (int j: {0, 1, 2, 3, 4}) {
                cout << "(" << i << "," << j << ")";
                cout << setw(2) << board[i][j] << " |";
            }
        }

        cout << "\n-----------------------------";
    }
    cout << endl;
}

bool X_O_pyramic_Board::is_winner() {
    char row_win[5], col_win[3], diag_win[2];
    row_win[1] = board[1][1] & board[1][2] & board[1][3];
    row_win[2] = board[2][0] & board[2][1] & board[2][2];
    row_win[3] =  board[2][2] & board[2][3] & board[2][4];
    row_win[4]= board[2][1] & board[2][2] & board[2][3];

    col_win[2] = board[0][2] & board[1][2] & board[2][2];//for

    diag_win[0] = board[0][2] & board[1][1] & board[2][0];
    diag_win[1] = board[0][2] & board[1][3] & board[2][4];


    if ( (row_win[2] && (row_win[2] == board[2][0])) ||
         (row_win[3] && (row_win[3] == board[2][4])) ||
         (row_win[4] && (row_win[4] == board[2][3])) ||
         (row_win[1] && (row_win[1] == board[1][1]))||
         (col_win[2] && (col_win[2] == board[0][2])) )
    {return true;}

    if ((diag_win[0] && diag_win[0] == board[0][2]) ||
        (diag_win[1] && diag_win[1] == board[0][2]))
    {return true;}
    return false;
}
// Return true if 9 moves are done and no winner
bool X_O_pyramic_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool X_O_pyramic_Board::game_is_over () {
    return n_moves >= 9;
}
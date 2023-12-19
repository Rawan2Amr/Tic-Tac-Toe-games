// File name:Tic_Tac_Toe_Board.cpp
// Purpose: Tic Tac Toe game
// Author(s): Yomna Maged
// ID(s): 20221196
// Section: S19

#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"

using namespace std;

Tic_Tac_Toe::Tic_Tac_Toe(Player *players[2]) {
    player[0] = players[0];
    player[1] = players[1];
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool Tic_Tac_Toe::update_board(int x, int y, char symbol) {

    if (!(x < 0 || x > 5 || y < 0 || y > 5) && (board[x][y] == 0)) {
        board[x][y] = toupper(symbol);
        n_moves++;
        return true;
    }
    else
        return false;
}

void Tic_Tac_Toe::display_board(){
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n------------------------------------------";
    }
    cout << endl;
}
//--------------------------------------------------
bool Tic_Tac_Toe::is_winner(){
    if(n_moves != 24) return false;
// counter for X and O
    int n_of_X = 0;
    int n_of_O = 0;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            char symbol = board[i][j];

            if (symbol == 'X' || symbol == 'O') {
//                check vertical
                if (j + 2 < 5 && symbol == board[i][j + 1] && symbol == board[i][j + 2]) {
                    (symbol == 'X') ? ++n_of_X : ++n_of_O;
                }
//                check horizontal
                if (i + 2 < 5 && symbol == board[i + 1][j] && symbol == board[i + 2][j]) {
                    (symbol == 'X') ? ++n_of_X : ++n_of_O;
                }
//                check right diagonal
                if (i + 2 < 5 && j + 2 < 5 && symbol == board[i + 1][j + 1] && symbol == board[i + 2][j + 2]) {
                    (symbol == 'X') ? ++n_of_X : ++n_of_O;
                }
//                check left diagonal
                if (i + 2 < 5 && j - 2 >= 0 && symbol == board[i + 1][j - 1] && symbol == board[i + 2][j - 2]) {
                    (symbol == 'X') ? ++n_of_X : ++n_of_O;
                }
            }
        }
    }

//    display the winner
    if(n_of_X > n_of_O){
        cout << player[0]->to_string() << " wins" << endl;
    }

    else if(n_of_O > n_of_X){
        cout << player[1]->to_string() << " wins" << endl;
    }

    else{
        cout << "Draw!\n";
    }

    return false;
}
//--------------------------------------------

bool Tic_Tac_Toe::is_draw(){
//    return (n_moves == 24 && is_winner());
    return false;
}
bool Tic_Tac_Toe::game_is_over(){
    return n_moves >= 24;
}

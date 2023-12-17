// File name:A3_Task2_S19_20221062_20221041_20221196.cpp
// Purpose: a menu for all games
// Author(s): Yomna Maged
//            Rawan Amr
//            Tasneem Mamdouh
// ID(s): Yomna Maged     20221196
//        Rawan Amr       20221062
//        Tasneem Mamdouh 20221041
// Section: S19

#include <iostream>
#include"BoardGame_Classes.hpp"
using namespace std;
//--------------------------------
void Game0(){
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 3);

    GameManager x_o_game (new X_O_Board(), players);
    x_o_game.run();
    system ("pause");
}
//--------------------------------
void Game1(){
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X_O pyramic Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 3);

    GameManager x_o_game (new X_O_pyramic_Board(), players);
    x_o_game.run();
    system ("pause");
}
//---------------------------------
void Game2(){
    int choice;
    Player* players[2];
    //Player pointer points to child
    players[0] = new connect_four_player (1, 'x');

    cout << "Press 1 if you want to play with computer and 0 to play with another: ";
    cin >> choice;
    if (choice != 1)
        //Player pointer points to child
        players[1] = new connect_four_player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 7);

    GameManager x_o_game (new Connect_four_Board(), players);
    x_o_game.run();
    system ("pause");
}
//--------------------------------
void Game3(){
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 5);

    GameManager Tic_Tac_Toe_game (new Tic_Tac_Toe(players), players);
    Tic_Tac_Toe_game.run();
    system ("pause");
}
//------------------------------
int main() {
    cout << "Welcome to FCAI Games. :)\n";
    cout << "Enter (0) for X_O game "<<'\n'
         << "Enter (1) for pyramic game "<<'\n'
         << "Enter (2) for four in a row game "<<'\n'
         << "Enter (3) for Tic Tac Toe game" <<'\n';
    char option ;
    cin >> option;
    if (option=='0') {
        Game0();
    }
    if (option=='1'){
         Game1();
    }
    if (option=='2'){
         Game2();
    }
    if (option=='3'){
         Game3();
    }
}

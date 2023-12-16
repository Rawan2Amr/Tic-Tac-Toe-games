// Class definition for XO_App class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include"BoardGame_Classes.hpp"
using namespace std;
//--------------------------------
void Game1(){
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

    GameManager x_o_game (new X_O_pyramic_Board(), players);
    x_o_game.run();
    system ("pause");
}
//---------------------------------
void Game2(){
    int choice;
    Player* players[2];
    players[0] = new conect (1, 'x');

    cout << "Press 1 if you want to play with computer and 0 to play with another: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new conect (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 7);

    GameManager x_o_game (new Conect_four_Board(), players);
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
    cout << "Enter (1) for game1 "<<'\n'
         << "Enter (2) for game2 "<<'\n'
         << "Enter (3) for game3" <<'\n';
    char option ;
    cin >> option;
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

// File name: Connect_four_player.cpp
// Purpose: a class for connect for game
// Author(s): Rawan Amr
// ID(s): Rawan Amr 20221062
// Section: S19

#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"BoardGame_Classes.hpp"
using namespace std;

char connect_four_player::get_symbol() {
    return symbol;
}
//-----------------------------------------
void connect_four_player ::get_move(int& x,int &y) {
    cout << "\nPlease enter your move : ";
    cin>> y;
}
//---------------------------
connect_four_player ::connect_four_player(int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}
//------------------------------------
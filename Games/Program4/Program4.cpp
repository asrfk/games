// Program4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "craps.h"
#include "tictactoe.h"
#include "hangman.h"
#include "blackjack.h"
#include "war.h"



int main(){

    string game;
    while (game != "Q")
    {
        cout << endl << endl;
        cout << "Games List" << endl;
        cout << "B - BlackJack" << endl << "C - Craps" << endl << "H - Hangman" << endl << "T - TicTacToe" << endl<<"W - War"<< endl<< "Q - Quit" << endl;
        cout << "What game would you like to Play" << endl;
        cin >> game;
        if (game == "B") {
            BJ();
        }
        if (game == "C") {
            Craps();
        }
        if (game == "H") {
            Hang();
        }
        if (game == "T") {
            TTT();
        }
        if (game == "W")
        {
            War();
        }
        if (game == "Q") {
            cout << "OK BYE" << endl;
        }
        else {
            cout<<"Enter a Valid Choice" << endl;
        }
    }

}


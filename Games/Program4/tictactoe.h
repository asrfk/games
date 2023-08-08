#pragma once
#include <iostream>
using namespace std;


void TTT() {
	string arr[3][3] = { "1","2","3","4","5","6","7","8","9" };
	int coin;
	srand(time(0));
	cout << "WELCOME TO TIC TAC TOE" << endl << endl;
	coin = rand() % 2;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cout << arr[i][j]<<" ";
		}
		cout << " " << endl;
	}
	if (coin==1){
		cout << "player" << endl;
	}
	if (coin==0){
		cout << "computer" << endl;
	}

}
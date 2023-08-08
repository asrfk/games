#pragma once
#include <iostream>
using namespace std;

int Craps() 
{
	string again;
	int money=50,bet,die1,die2,dice,point,temp=0;
	srand(time(0));

	cout << "Welcome TO CRAPS" << endl;

	while (again !="N") 
	{
		cout << "Your Net worth is: $" << money << endl << " Please enter your bet: " << endl;
		cin >> bet;
		if (bet > money) 
		{
			cout << "Please enter a valid amount that is less than or equal to your Net worth" << endl;
		}

		else 
		{
			//generates dice
			die1 = rand() % 6 + 1;
			die2 = rand() % 6 + 1;
			dice = die1 + die2;
			cout << "You rolled: " << die1 << " + " << die2 << " = " << dice << endl << endl;
			//if 7 or 11 is rolled
			if (dice==7||dice==11)
			{
				cout << "YOU WIN!!!" << endl;
				money += bet;
			}
			//if 2 3 12 are rolled
			else if (dice==2||dice==3||dice==12)
			{
				cout << "YOU LOOSE" << endl;
				money -= bet;
			}
			//if none of the above apply
			else
			{
				point = dice;
				cout << endl << "Point is: " << point << endl;
				
				while (temp != point && temp != 7) 
				{
					//generates dice
					die1 = rand() % 6 + 1;
					die2 = rand() % 6 + 1;
					dice = die1 + die2;
					cout << "You rolled: " << die1 << " + " << die2 << " = " << dice << endl;
					temp = dice;
					
					if (temp==7)
					{
						cout<<"YOU LOOSE" << endl;
						money -= bet;
					}
					
					else if (temp==point)
					{
						cout << "YOU WIN" << endl;
						money += bet;
					}
				}
			}
		}
		
		if (money<=0)
		{
			cout << "You lost all your money" << endl;
			again = "N";
		}
		
		else
		{
			cout << "Your current net worth: " << money << endl;
			cout << "Would you like to go again?" << endl;
			cin >> again;
		}

	}
	return 0;
}
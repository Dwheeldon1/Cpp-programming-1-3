/* 
		Distance Traveled
	The distance a vehicle travels can be calculated as follows:
		distance = speed * time
	write a program that asks theuser for the speed of a vehicle (in MPH) and how many hours it traveled. 
	The program should then use a loop to display the distance the vehicle has traveled for each
	hour of that time period. 
	do not accept a negative number for speed do not accept any value less than 1 for time traveled
*/
/*
		Pseudocode
	inititate a variable for speed, time and distance
	display enter a speed in MPH
	input speed
	display how many hours did it travel
	input time
	validate response with while loop statement for speed and time
	display chart heading
	for loop to display each hour and distance traveled

*/
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
	int speed, time;	//variables
	
	//obtain user input
	cout << "Enter the Vehicles Speed in MPH: ";
	cin >> speed;
	cout << "Enter how many hours were traveled: ";
	cin >> time;

	//validate response with if statements
	while (speed < 0)
	{
		cout << "Speed cannot be a negative number. " << endl;
		cout << "Please enter the Vehicles Speed in MPH: ";
		cin >> speed;
	}
	while (time < 1)
	{
		cout << "Amount of time traveled cannot be less than 1 hour." << endl;
		cout << "Please enter how many hours were traveled: ";
		cin >> time;
	}

	//display chart heading

	cout << "time" << "\t\t" << "distance traveled" << endl;
	cout << "-----------------------------------"<< "\n\n";

	//for loop to display each hour and distance traveled
	for (int count = 1; count <= time; count++)
	{
		
		cout << count << "\t\t\t" << (count * speed) << endl;

	}
	return 0;
}

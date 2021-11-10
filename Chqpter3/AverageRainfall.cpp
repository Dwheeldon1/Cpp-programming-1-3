/*
		Average Rainfall
	Write a program that calculates the average rainfall for three months. The program 
	should ask the user to enter the name of each month, such as june or july, and the 
	amount of rain (in inches) that fell each month. The program should display a message sumilar
	to the following:
	the average rainfall for June, July, and august is 6.72 inches

*/
/*
		pseudocode
	initate a variable for month 1 name
	initate a variable for month 2 name
	initiate a variable for month 3 name
	initaite a variable for month 1 rainfall
	initiate a variable for month 2 rainfall
	inintate a variable for month 3 rainfall
	calculate the total rainfall for the period
	calculate the average rainfall /3
	display "the rainfall for " month 1, month 2, "and " month 3 "is: "
	display average
*/

#include <iostream> //for cout and cin
#include <iomanip> //for fixed, setprecision, and showpoint
#include <string>

using namespace std;

int main()
{
	string month1_name,
		month2_name,
		month3_name;
	double month1_rainfall,
		month2_rainfall,
		month3_rainfall,
		total_rainfall,
		average_rainfall;

	//get month names and rainfall data
	cout << "Enter the month: ";
	cin >> month1_name;
	cout << "Enter the rainfall total for " << month1_name << " in inches: ";
	cin >> month1_rainfall;
	cout << "Enter another month: ";
	cin >> month2_name;
	cout << "Enter the rainfall total for " << month2_name << " in inches: ";
	cin >> month2_rainfall;
	cout << "Enter the final month: ";
	cin >> month3_name;
	cout << "Enter the rainfall total for " << month3_name << " in inches: ";
	cin >> month3_rainfall;

	//calculate the total rainfall for the period
	total_rainfall = month1_rainfall + month2_rainfall + month3_rainfall;
	//calculate the average rainfall for three months
	average_rainfall = total_rainfall / 3;

	//display the average rainfall
	cout << setprecision(2) << fixed << showpoint;

	cout << "The average rainfall for " << month1_name << ", " << month2_name << ", and " << month3_name << " is: " << average_rainfall << " inches." << endl;
	return 0;


}
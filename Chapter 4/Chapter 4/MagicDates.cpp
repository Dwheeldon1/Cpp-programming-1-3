/*
		Magic Dates
	The date June 10, 1960 is special because when we write it in the following format, the month times the day equals the year.
	6/10/60
	Write a program that asks the user to enter a month (in numeric form, a day, and a two digit year. The program should then 
	determine whether the month times the day is equal to the year. If so, it should display a message saying the date is magic. 
	Otherwise, it should display a message saying it is not magic.
*/
/*
		pseudocode
	initiate a variable for user defined month
	initiate a variable for user defined day
	initiate a variable for user defined year
	initate a variable for the sum of the month times the day
	input day
	input month
	input year
	calculate the sum of the month times the day
	if statement to check the validity if the sum equals the year
		if so display the date is magic
	else
		display the date is not magic
*/

#include <iostream>
using namespace std;

int main()
{
	int MONTH,
		DAY,
		YEAR,
		MONTHdAY_SUM;

	//get input from the user
	cout << "Enter the two digit Month (MM): ";
	cin >> MONTH;
	cout << "Enter the two digit Day (DD): ";
	cin >> DAY;
	cout << "Enter the two digit Year (YY): ";
	cin >> YEAR;

	//calculate the month times the day
	MONTHdAY_SUM = MONTH * DAY;

	//if statement to chech the validity, if the sum equals the year
	if (MONTHdAY_SUM == YEAR)
	{
		cout << "The Date " << MONTH << "/" << DAY << "/" << YEAR << " is a Magical Date."; //if the sum equals the year display
	}
	else
	{
		cout << "The Date " << MONTH << "/" << DAY << "/" << YEAR << " is not a Magical Date."; //if the sum does not equal the year display
	}

	return 0; //to end the program
}
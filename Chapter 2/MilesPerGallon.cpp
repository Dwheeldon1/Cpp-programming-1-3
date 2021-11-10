/*
		Miles Per Gallon
	A car holds 16 gallons of gasoline and can travel 460 highway miles before refueling, and 345 mile in town before refueling. Write a program
	that calculates the number of miles per gallon the car gets. Display the result on the screen.
		MPG=Miles Driven/Gallons of gas used
*/

/*
		Doug Wheeldon
		CISS 241 Programming I
		Miles Per Gallon
*/

/* 
		pseudocode

	initate a variable for galls of gas
	initiate a variable for distance traveled in town
	intiate a variabel for distance traveled on the highway
	initiate a variable to hold mpg
	calculate mpg for town driving
	calculate mpg for highway driving
	display the result
*/

#include <iostream> //preprocessor directive to allow for cout
#include <iomanip>  //preprocessor directive to allow formatting
using namespace std;

int main()
{
	double gallons = 16, //initiate variables
		distance_traveled_town = 345,
		distance_traveled_highway = 460,
		miles_per_gallon_town,
		miles_per_gallon_highway;

	miles_per_gallon_town = distance_traveled_town / gallons; //calculate for MPG for in town driving
	miles_per_gallon_highway = distance_traveled_highway / gallons; //calculate MPG for highway driving

	cout << setprecision(1) << showpoint << fixed;	//set decimal place to 1, does not allow for scientific notation, rounds decimal place
	cout << "Your Vehicles Miles per Gallon is " << miles_per_gallon_town << " miles a gallon in town." << endl; //display the result in town driving
	cout << "Your Vehicles Miles per Gallon is " << miles_per_gallon_highway << " miles a gallon on the highway." << endl; //display the result for highway driving
		
}
/*
		Miles Per Gallon
	Write a program that calculates a car's gas mileage. The program should ask the user
	to enter the number of gallons the car can hold, and the numnber of miles it 
	can be driven on a full tank. It should display the number of miles that may be 
	driven per gallon of gas

*/
/*
		PsuedoCode
		intiate a variable for gallons of gas
		initiate a variable for number of miles driven on full tank
		initiate a variable for MPG
		Display "enter fuel tank capacity: "
		input capacity
		Display "enter miles driven: "
		input miles driven
		calculate mpg = capacity / miles driven
		display "Your Vehicles Miles per Gallon is: " 
		display MPG
	
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double tank_capacity,
		miles_driven,
		MPG;
	cout << setprecision(1) << fixed << showpoint;
	cout << "Please enter your fuel tank capacity: ";
	cin >> tank_capacity;
	cout << "Please enter the numer of miles driven: ";
	cin >> miles_driven;
	
	MPG = miles_driven / tank_capacity;
	cout << "The number of miles per gallon for your vehicle is: " << MPG << endl;
}
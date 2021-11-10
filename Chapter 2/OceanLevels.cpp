/*
		Ocean Levels
		Assuming the ocean's leve is currently rising at about 1.5 millimeters per year,
		write a program that display's:
		+ the number of milimeters higher than the current level that the ocean's level will
		  be in 5 years
		+ the number of milimeters higher than the current level that the ocean's level will
		  be in 7 years
		+ the number of milimeters higher than the current level that the ocean's level will 
		  be in 10 years
*/

/*
		pseudocode

	initialize a variable for 5 years
	initialize a variable for 7 years
	initialize a variable for 10 years
	calculate the rise at five years and save it to variable
	calculate the rise at 7 years and save it to variable
	calculate the rise at 10 years and save it to variable
	display the variables on the screen
*/

#include <iostream> //preprocessor directive to use cout
using namespace std;

int main() //main program
{
	double five_year_rise, seven_year_rise, ten_year_rise, annual_rise = 1.5; //initalize variables.
	five_year_rise = annual_rise * 5; //calculate five year rise and save it to variable
	seven_year_rise = annual_rise * 7; //calculate seven year rise and save it to variable
	ten_year_rise = annual_rise * 10; //calculate ten year rise and save it to variable.

	cout << "In five years the ocean will be " << five_year_rise << " milimeters higher than current levels." << endl;
	cout << "In seven years the ocean will be " << seven_year_rise << " milimeters higher than current levels." << endl;
	cout << "In ten years the ocean will be " << ten_year_rise << " milimeters higher than current levels." << endl;
}
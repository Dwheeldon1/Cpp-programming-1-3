/*
		Ocean Levels
	Assuming the oceans's level is currently rising at about 1.5 mm per year, write a 
	program that displays a table showing the number of mm that the ocean will have risen each year for the next 25 years.
*/
/*
		Pseudocode

	inititate a constant variable for the oveans level at 1.5 mm
	initiate a variable for a conter
	initiate a variable for the sea rise
	write a for loop for the sea rise each year capped at 25 
	display the table heading
	display the results per year
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	const double ocean_level = 1.5;	//ocean level increase 1.5 mm
	int count = 1;
	double sea_rise = 0;		//variables for count set to 0, sear_rise, and year

	//display the table heading
	cout << "\t" << "Year" << "\t\t" << "Sea Rise" << endl;
	cout << "\t" << "-----------------------" << "\n\n";

	//while loop for sea rise each year
	for (count; count <= 25; count++)
	{
		
		cout << showpoint << fixed << setprecision(1);
		cout << "\t" << count << "\t\t" << (ocean_level * count) << " MM" << endl;
			
	}

	return 0;
	

}
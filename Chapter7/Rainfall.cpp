/*
DOUG WHEELDON
CISS 241
Programming I
*/

/*
In this assignment, the program will keep track of the amount of rainfall for a 12-month period. The data must be stored in an array of 12 doubles,
each element of the array corresponds to one of the months. The program should make use of a second array of 12 strings, which will have the names of the months. These two arrays will be working in parallel. 
The array holding the month names will be initialized when the array is created using an initialization list (could also be created as an array of constants). 
The second array will hold doubles which will be the total rainfall for each month. Using a function, the program will prompt the user for the rainfall for each month (using both arrays) 
and store the value entered into the array with the rainfall totals; the other is used to display which month the program is asking for the rainfall total.

The output of the program will display the following once the data is all entered:

The total rainfall for the year
The average monthly rainfall
The month with the highest amount of rainfall (must display the month as a string)
The month with the lowest amount of rainfall (must display the month as a string)
The program must have the following functions:

void CollectRainData(double [ ], string [ ], int);
	Gets the user input for the rain totals for each month
	Parameters array for rainfail totals, array of month names and size of arrays
double CalculateTotalRainfall(double [ ], int);
	Calculates the total rainfall from the array parameter.
double CalculateAverage(double, int);
	Calculates the Average rainfall
	First parameter is the total rainfall, second is number of months
double FindLowest(double [ ], int, int&);
	Finds the month with the lowest amount of rainfall, returns this value
	Provides the index of the lowest month in the last parameter.
double FindHighest(double [ ], int, int&);
	Finds the month with the highest amount of rainfall, returns this value
	Provides the index of the highest month in the last parameter.
*/
/*
		pseudocode
	initialize varible for num_months, 
	initialize array for rainfall size num_months
	initialize array for months size num_months
	
	main ()
		call collectraindata function
		call calculate total rainfaill function
		call calculate average function
		call find lowest function
		call find highst funtion
		display total rainfall for the year
		display average monthly rainfall
		display month with highest rainfall
		display month with lowest rainfall
		EOP
	collectraindata()	
		for loop to step through the arrays listing the month and accepting data into the rainfall array
	calculate total rainfall ()
		for loop to cycle through the rainfall array and add it to an accumlator 
	calculate averafe ()
		take input for total rainfall and get the average
	findlowest ()
		for loop to work through the array to find the lowest rainfall amount
	find highest
		for loop to work through the array to find the highest rainfall amount
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int NUM_MONTHS = 12;		//Const variable set to 12
int LOWMONTH, HIGHMONTH;		//for the low and high month
double RAINFALL[NUM_MONTHS];	//rainfall array set to 12
string MONTHS[] = {"January", "Feburary", "March", "April", "May", "June", 
					 "July", "August", "September", "October", "November", "December"};		//months array set to 12 and initialized

void CollectRainData(double[], string[], int);
double CalculateTotalRainfall(double[], int);
double CalculateAverage(double, int);
double FindLowest(double[], int, int&);
double FindHighest(double[], int, int&);



int main()
{
    //double RAINFALL[] = { 2.2, 5.2, 1.1, 4.5, 2.1, 1.2, 0.5, 0.1, 2.2, 3.4, 4.5, 1.2 }; //Test for TotalRainfall
	//double TotalRainfall;

	//call functions to get data and values
	CollectRainData(RAINFALL, MONTHS, NUM_MONTHS);
	double TotalRainfall = CalculateTotalRainfall(RAINFALL, NUM_MONTHS);
	double Average = CalculateAverage(TotalRainfall, NUM_MONTHS);
	double lowest = FindLowest(RAINFALL, NUM_MONTHS, LOWMONTH);
	double highest = FindHighest(RAINFALL, NUM_MONTHS, HIGHMONTH);

	//display results
	cout << fixed << showpoint << setprecision(2);
	cout << "The Total Rainfall for the Year is: " << TotalRainfall << endl;
	cout << "The Average Monthly Rainfall is: " << Average << endl;
	//cout << "High Month is"<<HIGHMONTH<<endl;		//test high month value
	cout << "The Month with the Highest Rainfall is " << MONTHS[HIGHMONTH] << endl;
	//cout << "Low Month is " << LOWMONTH << endl;	//test low month value
	cout << "The Month with the Lowest Rainfall is " << MONTHS[LOWMONTH] << endl;

	//end of program
	return 0;
}

/***************************************************************************
*				CollectRainData()										   *
* Accepts Rainfall and Months Array										   *
*steps through both arrays together displaying contents of month and       *
* saving data inputted by user in rainfall                                 *
****************************************************************************/

void CollectRainData(double RAINFALL[], string MONTHS[], int NUM_MONTHS)
{
	int count; //counter
	//get each data and add it to array, displaying string arear each iteration
	for (count = 0; count < NUM_MONTHS; count++)
	{	
		cout << "Enter the rainfall amount for the month of " << MONTHS[count] << ":";
		cin >> RAINFALL[count];
	}
}

/******************************************************************************
		Calculate Total Rainfall ()                                           *
Accepts rainfall array and its size, totals it using an accumulator and       *
returns it                                                                    *
*******************************************************************************/

double CalculateTotalRainfall(double RAINFALL[], int Months)
{
	double total = 0; //accumulator
	/*Test to see if values are being passed into funciton
	cout << "Number of Months is " << Months << endl;
	for (int count = 0; count < Months; count++)
	{
		cout << "Values passed into function are " << RAINFALL[count] << endl;
	}
	*/

	
	//add each element to total
	for (int count = 0; count < Months; count++)
	{
		 total += RAINFALL[count];
	}
	//return total
	return total;
}

/********************************************************************************
*					Calculate Average()											*
* accepts a double and a int to calculate the average of the rainfall			*
* and returns it																*
*********************************************************************************/

double CalculateAverage(double TotalRainfall, int months)
{
	// average rainfall divided by number of months
	double total = TotalRainfall / months;
	
	//return average
	return total;
}

/********************************************************************************
*							Find Lowest ()								     	*	
*	accepts a double array and an int, steps through the array to find			*
*  the lowest rainfall amount and returns it                                    *
*********************************************************************************/

double FindLowest(double RAINFALL[], int months, int &LOWMONTH)
{
	double lowmonth = RAINFALL[0]; // to hold lowest and set it to the first value
	
	//step through the array and find values that are lower than lowest and assign it
	for (int count = 0; count < months; count++)
	{
		if (lowmonth > RAINFALL[count])
		{
			 lowmonth = RAINFALL[count];
			 LOWMONTH = count;
		}
		
	}
	//cout << "The LowMonth is " << LOWMONTH << endl;
	//return the lowest value
	return lowmonth;
}

/*********************************************************************************
*                    Find Highest                                                *
* accepts a double array and an int, steps through the array to find             *
* the highest rainfall amount and returns it                                     *
**********************************************************************************/

double FindHighest(double RAINFALL[], int months, int &HIGHMONTH)
{
	 double highmonth = RAINFALL[0]; // to hold highest and set it to the first value
	 

	//step through the array and find values that are higher than highest and assign it
	for (int count = 0; count < months; count++)
	{
		if (highmonth < RAINFALL[count])
		{
			highmonth = RAINFALL[count];
			HIGHMONTH = count;
		}
		
	}
	//cout << "The HighMonth is " << HIGHMONTH << endl;
	
	//return the lowest value
	return highmonth;
}

/*
Doug Wheeldon
CISS 241
Programming I
*/

/*
		Numeric Processing
	Write a program that opens the random.txt file, reads all the numbers, and calculates the following
	
	number of number in the file
	sum of all the numbers in the file(a running total)
	the average of all the numbers in the file
	Determine the lowest and highest values in the file
	
	the program should display the numbers of numbers found in the file, the sume of the numbers and the average
	The program must validate that the file was opened before reading from the file. If not then provide a message to the user and then the program should end.
*/
/*
		pseudocode
	variable for input file
	variable for numbers of numbers in file
	variable for sum of all numbers in file
	variable for average of numbers in file
	variable for min value in file
	variable for max number in file
	open the random.txtfile
	if it was opened process it 
		get number of numbers
		get sum of all numbers
		get average of all numbers
		get min value
		get max value
		close file
	else display error
		error opening the file
	display number of numbers in file
	display sum of all the numbers in file
	display the average of all numbers in file
	display the min value in file
	display the max value in file
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream inputfile;
	int numbers_file, sum_number = 0,  min_Value = INT_MAX, Max_value = INT_MIN, count = 0; // variable for input from file
	double average = 0;

	//open the file
	inputfile.open("random.txt");

	// check for error opening the file
	if (inputfile.fail())
	{
		cout << "Error opening file, or file does not exist.\n";
		return 0;
	}
	// process the file
	while (inputfile >> numbers_file)
	{
		if (numbers_file > Max_value)
		{
			Max_value = numbers_file;		//shows largest number
		}
		if (numbers_file < min_Value)
		{
			min_Value = numbers_file;		//shows smallest number
		}

		if (inputfile)
		{
			sum_number += numbers_file;	//sum of numbers
			count++;
			average = sum_number / count;	//average of numbers
		}
	}
	//display results
	cout << "The number of numbers in the file is " << count << "." << endl;
	cout << "The sum of all the numbers in the file is " << sum_number << "." << endl;
	cout << "The average of the numbers in the file is " << average << "." << endl;
	cout << "The minimum value in the file is " << min_Value << "." << endl;
	cout << "The maximum value in the file is " << Max_value << "." << endl;
	
	//close the file
	inputfile.close();
	return 0;
}
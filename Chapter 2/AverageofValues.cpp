/*
		Average of Values
		To get the average of a series of values, you add the values up then divide the sum by
		the number of values. Write a program that stores the following values in five different
		variables: 28, 32, 37, 24, and 33. The program should first calculate the sum of these five variables
		and store the result in a separate variable named sum. Then, the program should divide the sum
		variable by 5 to get the average. Display the average on the screen.
*/

/*
		pseudocode
		initalize five varaibles to hold the values: 28, 32, 37, 24, 33
		initialize variable for the variables total
		initialize variable to hold the sum
		add all five variables and store in variables total
		divide the total by 5 and store in sum
		display the average 
		
*/

#include <iostream>		//preprocessor directive for cout
using namespace std;

int main()				//main program
{
	double a = 28, b = 32, c = 37, d = 24, e = 33, sum, average; //initializing variables

	sum = a + b + c + d + e; //add variables and place in sum variable
	average = sum / 5; // sum divided by 5 and saved in average variable

	cout << "The average is: " << average << endl;

}
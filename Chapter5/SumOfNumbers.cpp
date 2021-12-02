/*
		Sum Of Numbers
	Write a program that asks the user for a positive integer value. The program should use
	a loop to get the sum of all the integers from 1 up to the number entered. 
	Input validation: Do not accept a negative starting number.
*/
/*
		Pseudocode
	initialize a variable for the user defined number
	initialize a variable for the sum of numbers
	initialize a variable for the counter
	Display enter a positive integer value
	input number
	validate number is non negative
		display enter a non negative number
		loop for obtaining integer values
		calculate the sum
	display the sum
*/
#include <iostream>

using namespace std;

int main()
{
	int user_num,			//to hold the user defined number
		sum_numbers,		//to hold the sum of the numbers
		total = 0,			//to hold the total for the numbers initialized to 0
		count = 1;			//the counter variable set to 1

	cout << "Enter a number: ";
	cin >> user_num;
	while (user_num < 0)	//while loop for negative numbers
	{
		cout << "Number must be positive." << endl;
		cout << "Enter a number: ";
		cin >> user_num;
	}
	for (count; count <= user_num; count++) //for loop to allow for the loop to add another integer
	{
		total += count;
		
	}
	sum_numbers = total;	//display the sum
	cout << "The sum of the numbers is: " << sum_numbers;
	return 0;
}


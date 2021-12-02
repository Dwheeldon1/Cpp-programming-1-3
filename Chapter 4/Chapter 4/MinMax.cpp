/* 
		Minimum/Maximum
	Write a program that sks the user to enter two numbers. The program should use the 
	conditional operator to d4etermine which number is the smaller and which is the larger.
*/
/*
		Pseudocode
	initiate a variable for a number 
	inititate another variable for another number
	Display "enter a number"
	input number1
	Display "enter a second number"
	input number2
	if statement to conditionally check for the larger number
		display number1 is greater than number2
	if statement to conditionally check for the smaller number
		display number2 is smaller than number1

*/

#include <iostream> //for cout and cin
using namespace std;

int main()
{
	int number1,
		number2;

	//get the user defined numbers
	cout << "Enter a number: ";
	cin >> number1;
	cout << "Enter a second number: ";
	cin >> number2;

	//statement to conditionally check for the larger number
	cout << "The greater number is " << (number1 > number2 ? number1 : number2) << endl;
	//statement to conditionally check for the smaller number
	cout << "The smaller number is " << (number1 < number2 ? number1 : number2) << endl;
	return 0;
	
}
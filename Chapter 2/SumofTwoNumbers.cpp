/* 
	2.1 Sum of Two Numbers
	Write a Program that stores the integers 50 and 100 in variables, 
	and stores the sum of these two in a variable named total
*/
/*
	psuedocode

		initalize variables to 50 and 100
		create variable for total
		store the sum of the variables that hold 50 + 100 in total
		display total
*/

#include <iostream> //to use cout
using namespace std;

int main() //main program
{
	int a = 50, //initialize integer a for 50
		b = 100, //intialize integer b for 100
		total;   //variable for total
	
	total = a + b; //to get total

	cout << "the total of 50 + 100 is " << total << endl; //to display total
}
/*
	Cyborg Data Type Sizes
	You have been given a job as a programmer on a Cyborg supercomputer. In order to 
	accomplish some calculations, you need to know how many bytes the following data
	types use: char, int, float, and double. You do not have any technical documentation,
	so you can't look this information up. Write a C++ program that will determieng the 
	amount of memory used by these types and display the information on the screen.

*/

/*
		psuedocode
	
	display the size of char
	display the size of int
	display the size of float
	display the size of double
*/

#include <iostream>	//preprocessor directive for using cout
using namespace std;

int main() //main program
{
	cout << "The size of char is " << sizeof(char) << endl;
	cout << "The size of int is " << sizeof(int) << endl;
	cout << "The size of float is " << sizeof(float) << endl;
	cout << "The size of double is " << sizeof(double) << endl;
}
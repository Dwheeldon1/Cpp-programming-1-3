/*
		Roman Numeral Generator
	Write a program that asks the user to enter a number within the range of 1 through 10.
	use a switch statement to display the Roman numeral version of that number.
	input validation: do not accept a number less than 1 or greater than 10.
*/
/*
	initiate a variable for user number
	initiate constant variables for roman numerals I through X
	get user number
	create an if statement to validate selection is from 1 through 10
	create a switch case statement to display the select roman numeral conversion
	
*/

#include <iostream>
using namespace std;

int main()
{
	int NUMBER;					//to hold user defined number 1 through 10
	const int ROMAN_I = 1,		//roman numeral 1
		ROMAN_II = 2,			//roman numeral 2
		ROMAN_III = 3,			//roman numeral 3
		ROMAN_IV = 4,			//roman numeral 4
		ROMAN_V = 5,			//roman numeral 5	
		ROMAN_VI = 6,			//roman numeral 6
		ROMAN_VII = 7,			//roman numeral 7
		ROMAN_VIII = 8,			//roman numeral 8
		ROMAN_IX = 9,			//roman numeral 9
		ROMAN_X = 10;			//roman numeral 10

	//get user number prompt for one between 1 and 10
	cout << "Enter a number between 1 and 10: ";
	cin >> NUMBER;

	//validate user input is between 1 and 10
	if (NUMBER < 1 || NUMBER > 10)
	{
		cout << "Number is not valid, re-run the program and use a number between 1 and 10.";
		return 0;		//to end the program to re-enter a number
	}
	else
	{
		switch (NUMBER)										//switch case statements
		{
			case 1: cout << "1 in Roman Numerals is I";
				break;
			case 2: cout << "2 in Roman Numerals is II";
				break;
			case 3: cout << "3 in Roman Numerals is III";
				break;
			case 4: cout << "4 in Roman Numerals is IV";
				break;
			case 5: cout << "5 in Roman Numerals is V";
				break;
			case 6: cout << "6 in Roman Numerals is VI";
				break;
			case 7: cout << "7 in Roman Numerals is VII";
				break;
			case 8: cout << "8 in Roman Numerals is VIII";
				break;
			case 9: cout << "9 in Roman Numerals is IX";
				break;
			case 10: cout << "10 in Roman Numerals is X";
				break;
		}
	}
	return 0;		//to end the program
}
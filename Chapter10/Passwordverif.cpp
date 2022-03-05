/******************************************

Program Password Verifier

This program verifies a users password length, 
number of uppercase, lowercase, and digits.

Author: Doug Wheeldon

Created : 01/29/2022

Revisions : <date> <what changes were made>

******************************************/
#include <iostream>


using namespace std;

// Global constants
const int SIZE = 80; // The maximum size of the array
const int MIN = 6;   // The minimum number characters

// Function prototypes
void displayRequirements();
void displayResult(char[]);


int main()
{
	char cstring[SIZE];


	displayRequirements();

	cout << "Enter a password: ";
	cin.getline(cstring, SIZE);

	displayResult(cstring);

	return 0;
}

void displayRequirements()
{
	// Display the password requirements.
	cout << "Password Requirments:\n"
		<< "  - The password should be at least "
		<< MIN << " characters long.\n"
		<< "  - The password should contain at least one uppercase\n"
		<< "    and at least one lowercase letter.\n"
		<< "  - The password should have at least one digit.\n\n";
}

void displayResult(char str[])
{
	bool length, upper, lower, digit;
	length = upper = lower = digit = false;
	int lengthCount = 0;

	lengthCount = strlen(str);							//obtains the length of the string
	if (lengthCount >= MIN && lengthCount <= SIZE)		//if statement to determine if the password is in the range for the password
	{
		length = true;									//if it is sets lenght condition to true
	}

	for (int count = 0; count < lengthCount; count++)			//works through the array
	{
		if (isupper(*(str + count)))						//tests for upper case 
		{	
			upper = true;								//if upper case sets condition to true
		}
		else if (islower(*(str + count)))						//tests for lower case
		{
			lower = true;								//if lower case sets condition to true
		}
		else if (isdigit(*(str + count)))						//tests for a digit
		{
			digit = true;								//if a digit sets condition to true
		}
		
	}
	if (upper == false)
	{
		cout << "You must have a upper case letter.\n";
	}
	if (lower == false)
	{
		cout << "You must have a lower case letter. \n";
	}
	if (digit == false)
	{
		cout << "You must have a digit between 0 and 9. \n";
	}
	if (strlen(str) < 6)
	{
		cout << "The length of your password is less than 6 characters. It must be greater than 6 characters.\n";
	}
	if (length == true && upper == true && lower == true && digit == true)
	{
		cout << "Password Successful.\n";
	}
}
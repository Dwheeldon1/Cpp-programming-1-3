/*
Compounded Interest Earned – Assume no additional deposits are made other than the original investment. The balance in an account after one year may be calculated as:

New Balance = Principal * (1 + rate/T)T

Principal is the opening balance in the account. Rate is the interest rate, and T is the number of times the interest is compounded during a year (T is 4 if the interest is compounded quarterly). 
Write a program that prompts the user for the principal, the interest rate, and the number of times the interest is compounded. The output must be formatted in the following format:

Interest Rate:	4.25%
Times Compounded:	12
Principal:	$1000.00
Interest: 	$43.34
Amount in Savings:	$1043.34
*/

/*
PseudoCode
initiate a variable for the principal
initiate a variable for the interest rate
initatie a variable for the times interest is compounded
initiate a variable for the interest earned
initiate a variable for the amount in savings
DISPLAY "Enter the opening balance of the account: "
input principal
DISPLAY "Enter the interest rate: "
input interest rate
DISPLAY "Enter the number of times the interest is compunded: "
input times interest compunded
Convert interest rate to decimal form
CALCULATE amount in savings = principal * (1 + interst rate/times interest compounded)times interest compounded
Calculate interest earned = amount in savings - principal
display "interest rate: " 
display "times compounded"
display "principal"
display "interest"
display "amound in savings"
*/

#include <iostream>					//for cout and cin
#include <iomanip>					//for showpoint, fixed, setprecision formatting
#include <cmath>					//for math functions

using namespace std;

int main()
{
	double principal,				//to hold the opening balance of the account
		interest_rate,				//to hold the interest rate
		times_interest_compounded,	//to hold the amount of times interest is compounded
		interest_earned,			//to hold the amount of interest earned off the principal
		amount_in_savings,			//to hold the amount in savings after the interest is applied
		rate;						//to hold the converted interest rate in decimal form


	//get user input for principal, interest rate, and times compounded
	cout << "Enter the opening balance of the account: ";
	cin >> principal;
	cout << "Enter the interest rate: ";
	cin >> interest_rate;
	cout << "Enter the number of times the interest is compounded: ";
	cin >> times_interest_compounded;

	//convert interest_rate to decimal form
	rate = interest_rate / 100;

	//calculate the amount in savings
	amount_in_savings = principal * pow(1 + rate / times_interest_compounded, times_interest_compounded);

	//calculate the interest earned
	interest_earned = amount_in_savings - principal;
			
	//display the results
	cout << "Interest Rate: " <<setw(17) << interest_rate << "%" << endl;
	cout << "Times Compounded: " <<setw(15) << times_interest_compounded << endl;
	
	//formatting for two decimal places and to show what is after the decimal
	cout << setprecision(2) << showpoint << fixed;

	cout << "Principal:" << setw(16) << "$" << principal << endl;
	cout << "Interest:"  << setw(19) << "$" << interest_earned << endl;
	cout << "Amount in Savings:" << setw(8) << "$" << amount_in_savings << endl;
	return 0; //to end the program

}
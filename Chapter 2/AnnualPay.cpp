/*
		Annual Pay
		Suppose an emplyoee gets paid every two weeks and earns $2200.00 each pay period. 
		In a year, the employee gets paid 26 times. Write a program that defines the following variables
		+ payAmount this variable will hold the amount of pay the employee earns each pay period. 
					initialized at 2200.0.
		+ payPeriods this variable will hold the number of pay periods in a year. 
					 initialize the variable at 26
		+ annualPay  this variable will hold the employee's total annual pay, which will be calculated.
		The program should calculate the employee's total annual pay by multiplying the
		employee's pay amount by the number of pay periods in a year and store the result in the 
		annualPay variable. Display the total on the screen.
*/

/*
		pseudocode
		initalize payAmount variable at 2200.0
		initialize payPeriods variable at 26
		initialize annualPay variable
		calulate total annual pay and save to annualPay variable
		display annualPay variable
*/

#include <iostream>
using namespace std;

int main()
{
	double payAmount = 2200.0, //initializing variables
		payPeriods = 26,
		annualPay;

	annualPay = payAmount * payPeriods; //annual pay calculation

	cout << "Total Annual Pay is $" << annualPay << endl;
}

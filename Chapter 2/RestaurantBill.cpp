/*
	Restaurant Bill
	Write a program that computes the tax and tip on a restaurant bill for a patron
	with a $88.67 meal charge. The tax should be 6.75 percent of the meal cost.
	The tip should be 20 percent of the total after adding the tax. 
	Display the meal cost, tax amount, tip amount, and total bill on the screen.
*/

/*
	pseudocode

	initialize purchase variable set to 88.67
	initalize tax variable at 6.75%
	initialize tip variable at 20%
	initalize variable for tax amount 
	initialize variable for tip amount
	initialize variable for total bill
	display meal cost
	display tax amount
	display tip amount
	display total bill
*/

#include <iostream> //to use cout
using namespace std;

int main() //main program
{
	double purchase = 88.67,
		tax = .0675,
		tip = .2,
		tax_amount,
		tip_amount,
		total_bill;

	tax_amount = purchase * tax; //get the tax amount for the purchase
	tip_amount = purchase * tip; //get the amount of the tip
	total_bill = purchase + tip_amount + tax_amount; //get the amount of the total bill

	cout << "Meal Cost: " << purchase << endl; //display the meal cost
	cout << "Tax Amount: " << tax_amount << endl; //display the tax amount applied to final bill
	cout << "Tip Amount: " << tip_amount << endl; //display the tip amount applied to final bill
	cout << "Total Bill: " << total_bill << endl; //display the final bill
}
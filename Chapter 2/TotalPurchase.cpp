/*
	Total  Purchase

	A Customer in a store is purchasing five items. The prices of the five items are as follows:
	+ item 1 = $15.95
	+ item 2 = $24.95
	+ item 3 = $6.95
	+ item 4 = $12.95
	+ item 5 = $3.95
	Write a program that holds the prices of the five items in five variables. Display each
	item's price, the subtotal of the sale, the amount of sales tax, and the total. Assume the
	sales tax is 7 percent.
*/

/*
	pseudocode

	initialize variables for all 5 items
	initialize variable for subtotal
	initialize variable for the sales tax
	initialize variable for the total
	calculate the subtotal
	calculate the sales tax 
	calculate the total
	display the cost of each item
	display the subtotal
	display the sales tax
	display the total
*/

#include <iostream> //preprocessor directive for cout
using namespace std;

int main()
{
	double item_1 = 15.95, //initializing item variables, subtotal, sales tax, tax_amount, and total
		item_2 = 24.95,
		item_3 = 6.95,
		item_4 = 12.95,
		item_5 = 3.95,
		subTotal,
		tax_amount,
		sales_tax = 0.07,
		total;
	
	subTotal = item_1 + item_2 + item_3 + item_4 + item_5; //calculate the subtotal and save it to variable

	tax_amount = subTotal * sales_tax; //calculate the tax amount of the purchase

	total = tax_amount + subTotal; //calculate the total of the sale

	cout << "Item 1: $" << item_1 << endl << "Item 2: $" << item_2 << endl << "Item 3: $" << item_3 << endl;
	cout << "Item 4: $" << item_4 << endl << "Item 5: $" << item_5 << endl;
	cout << "Subtotal: $" << subTotal << endl << "Sales Tax: $" << tax_amount << endl;
	cout << "Total: $" << total << endl;
}
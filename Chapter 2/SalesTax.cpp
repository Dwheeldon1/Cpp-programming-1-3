/*
	Sales Tax
	Write a program that will compute the total sales tax on a $95 purchase.
	Assume the state sales tax is 4 percent, and the county sales tax is 2 percent.
*/

/*
	pseudocode
	initialize a variable for state sales tax at .04
	initialize a variable for county sales tax at .02
	initalize a variable for purchase at $95
	initialize a variable for total sales tax
	initialize a variable for tax applied to purchase
	initialize a variable for total sale price
	display total sales tax
	dispaly tax applied to purchase
	displat total sale price
*/

#include <iostream> //to use cout
using namespace std;

int main()
{

	double state_sales_tax = .04,	//initialize state sales tax to 4%
		county_sales_tax = .02,		//initialize county sales tax to 2%
		purchase = 95,				//initialzie purchase to $95
		total_sales_tax,			//for total sales tax
		tax_applied_purchase,		//for tax that is applied to purchase
		total_sale_price;			//for total sale price with tax included

	total_sales_tax = state_sales_tax + county_sales_tax; //to set total sales tax to 6%

	tax_applied_purchase = purchase * total_sales_tax; //to get the dollar amount of the tax for the purchase

	total_sale_price = purchase + tax_applied_purchase; //to get the total sale price

	cout << "Total sales tax applied to the purchase is $" << tax_applied_purchase <<endl << "Total sale price is $" << total_sale_price <<endl;
}
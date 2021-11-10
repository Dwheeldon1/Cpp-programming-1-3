/*
		Stock Market Calculations
	Cathy bought 600 shares of a stock at a price of $33.77 per share. For the purchase of stocks,
	she must pay the stockbroker a 2% commision for the transaction. Design and create
	a program that calculates and displays the following:
	+ The amount paid for the stock alone (without the commission)
	+ The amount of the commission
	+ the total amount paid (for the stock plus the commission)
*/

/*
	Doug Wheeldon
	CISS 241 Programming I
	Stock Market Calculations
*/

/*
			pseudocode
		initiate a variable for shares bought
		initiate a variable for the price per share
		initiate a variable for the commision percentage
		initiate a variable for the total purchase price of the stock
		initiate a variable for the commision amount
		initiate a varibale for the total amount paid for the stock
		Calculate the cost of the stock without commission
		calculate the cost of the commission
		calculate the total amount paid
		display the total cost of the stock 
		display the cost of the commission
		display the total price paid
*/

#include <iostream> //preprocessor directive for the use of cout
#include <iomanip>  //preprocess directive for formatting
using namespace std;

int main()
{
	double shares_bought = 600, 
		stock_price = 33.77, 
		commission_percentage = .02, 
		total_price_stock, 
		commission_amount, 
		total_paid; //initiating variables

	total_price_stock = shares_bought * stock_price; //calculate the total price of the stock bought w/o commission
	commission_amount = total_price_stock * commission_percentage; //calculating the amount of the commission
	total_paid = total_price_stock + commission_amount; //calculating the total cost with total stock price and commission amount. 
	
	cout << setprecision(2) << showpoint << fixed;
	cout << "The total price of the stock is $" << total_price_stock << endl;
	cout << "The commission amount to be paid is $" << commission_amount << endl;
	cout << "The total cost to paid is $" << total_paid << endl;
}
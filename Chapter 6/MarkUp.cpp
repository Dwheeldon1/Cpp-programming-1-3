/*
		Markup
	write a program that asks the user to enter an item's wholesale cost and its markup percentage.
	it should then display the item's retail price.The program should have a function named calculateRetail 
	that receives the wholesale cost and the markup percentage as arguments and returns the retail price of the item.
	do not accept negative values for either the wholesale cost of the item or the markup percentage.
*/
/*
	pseudocode
	initiate a variable for cost
	intitate a variable for markup
	declare funtion with variable types
	main()
		get cost
		input cost
		get markup
		input markup
		display retail cost
	calculateRetail()
		accept cost arg
		accept markup arg
		get retail cost (cost * markup)
		return retail cost
*/
#include <iostream> //for cout cin
#include <iomanip>  //for formatting

using namespace std;



//identify the function with return type and type of arg it accepts
double calculateRetail(double, double);

int main()
{
	double retail = 0, wholesale_cost, markup;	//variable to hold the retail cost

	cout << "Enter the Wholesale Cost of the item: ";
	cin >> wholesale_cost;
	cout << "Enter the markup percentage of the item as a decimal: ";
	cin >> markup;
	if (wholesale_cost < 0)
	{
		cout << "Invalid Entry. Must be a positive number." << endl;
		cout << "Enter the Wholesale cost of the item: ";
		cin >> wholesale_cost;
	}
	if (markup < 0)
	{
		cout << "Invalid Entry. Must be a postitive number." << endl;
		cout << "Enter the markup percentage of the item: ";
		cin >> markup;
	}
	retail =  calculateRetail(wholesale_cost, markup);
	
	cout << setprecision(2) << fixed << showpoint;
	cout << "The retail cost is $" << retail << "." << endl;

	return 0;
}


/******************************************************
*					calculateRetail()				  *
	accepts double argument and returns a double      *
	calcualtes the retail cost from the wholesale     *
	cost and markup percentage                        *
*******************************************************/
double calculateRetail(double cost, double percent)
{	
	double markup = cost * percent;
	double total = markup + cost;
	return total;
}


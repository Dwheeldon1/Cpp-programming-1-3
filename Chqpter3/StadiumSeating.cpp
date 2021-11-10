/*
		Stadium Seating
	There are three seating categories at a astadium. For a softball game, Class A seats are $15,
	Class B seats cost $12, and Class C seats cost $9. Write a program that asks how 
	many tickets for each class of seats were sold, then displays the amount of income generated
	from ticket sales. Format your dollar amount in fixed-point notation, with two decimal places
	of precision, and be sure the decimal point is always displayed.
*/
/*
			pseudocode
	initiate a variable for class a seats set to $15
	initiate a variable for class b seats set to $12
	initiate a variable for class c seats set to $9
	Display"How many class A seats were sold: "
	input class a sold
	Display"How many class B seats were sold: "
	input class b sold
	Display"how many class C seats were sold: "
	input class c sold
	calculate the total price for class a seats
	calculate the total price for class b seats
	calculate the total price for class c seats
	calculate total sales
	Display "Total income from timcket sales is: $" total sales

*/

#include <iostream> //for cin and cout
#include <iomanip>  //for fixed, showpoint, and setprecision

using namespace std;

int main() //main program
{

	double const class_A_seats = 15; //constant for the price of class A seats
	double const class_B_seats = 12; //constant for the price of class b seats
	double const class_C_seats = 9;	 //constatn for the price of class c seats
	double class_A_sold,			//class a seats sold    
		class_B_sold,				//class b seats sold
		class_C_sold,				//class c seats sold
		total_sales,				//total sales for tickets
		total_A,					//total price for class a seats
		total_B,					//total price for class b seats
		total_C;					//total price for class c seats

//get the number of seats sold
		cout << "Enter the number of class A seats sold: ";
		cin >> class_A_sold;
		cout << "Enter the number of class B seats sold: ";
		cin >> class_B_sold;
		cout << "Enter the number of class C seats sold: ";
		cin >> class_C_sold;

//calculate costs of seats sold
		total_A = class_A_sold * class_A_seats;
		total_B = class_B_sold * class_B_seats;
		total_C = class_C_sold * class_C_seats;

//calculate total cost of seat sales
		total_sales = total_A + total_B + total_C;

//display total sales
		cout << setprecision(2) << fixed << showpoint;
		cout << "Total income from ticket sales is: $" << total_sales;
		return 0;
}
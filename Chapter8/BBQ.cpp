/*
		Create a program that keeps track of BBQ sauce sales for a company
		Program will utilize 3 arrays; one for the sauces(from text file), one for the price(from text file), and one for the amount sold of each
		Arrays will run in parallel. 
		Program will ask how many of each has been sold. Once data is entered it will display the sauces and total price sold to a precision of 2.
		Will determine what the highest selling item is and what the lowest selling item is.

		Method to display the table of output.
		Method to calculate the total of overall sales, returns the amount.
		Method to get the inputs from the user for the amount sold of each sauce.
		Method to determine which is the highest and lowest product sold.
*/
/*
		Pseudocode

		string array sauce
		double array sauce price
		int array sauce sold
		double sauce total

		int numsauce = 6;      //variable set the number of products to 6 
		

		Function prototypes
		void getdata function (string [], double [], int [])
		double calc sales(double [], int [])
		string highest lowest sold (string [], double [],String&, String&)
		void display table (string[], double [], double[], int[])

		int main ()
		
			string highest,lowest; //variables for highst and lowest sauce
			double sales;		   //total sales of sauce sales
			populate sauce array from file
			populate price array from file
			call getdata function(string sauce [], double sauce price[], int[])
			call calc sales (double sauce price[], int saucesold [], double &sales)
			call display table (string sauce[], double sauce price [], int sauce sold[], double saucetotal, double)
		void getdata () /*accepts 3 arrays 
			display sauce and price from arrays
				prompt user for item # sold
				place # sold into sauce sold array
		double calc () /* accepts 2 arrays and a double 
			works through each array adding the total of each sauce * number sold to the total value 
			each sauce total added to saucetotal array
		void display table /* accepts data from 3 arrays
			displays table of items for sauce, sauce price, items sold, and cost of each item
			calls highest/lowest sold function
			displays the highest item sold and the lowest item sold
			displays the total costs sold of all products
		string highest
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int numsauce = 6;			//global const variable to establish number of products

string sauce[numsauce];				//string array for names of sauces populated from file
double sauceprice[numsauce];		//double array for price of sauces populated from file
int saucesold[numsauce];			//int array for number of sauces sold
double saucetotal[numsauce];		//double array to hold the sales total of each individual sauce

//function prototypes
void getdata(string[], double[], int[]);	//get user data function no return type references arrays 
double calcsales(double[], int[], double[]);  //calc sales function accepts double array, int array, and returns double
double highest(double[], double&);	//highest function accepts double array and double ref finds higest sale of product
double lowest(double[], double&);  //lowest function accepts double array and double reference finds lowest sales of product
void displaytable(string[], double[], double[], int[], double); //display table accepts string, double, double, and int arrays

int main()
{
	
	double sales;				//variable to hold the total sales 

	//populate sauce name array from text file
	fstream inputfile;
	inputfile.open("D:/BBQSAUCES.txt");	//open file
	if (inputfile.fail())				//check for openining error
	{
		cout << "Error opening file. \n";
	}
	else
	{
		int count = 0;	//count variable set to 0
		while (count < numsauce && inputfile >> sauce[count])		//while loop to work through the array assiging values from the file to the elements
			count++;
		
		inputfile.close();		//close the file
		
	}
	//populate sauce price array from text file
	fstream file;
	file.open("D:/BBQPRICE.txt");		//open file
	if (file.fail())				//check for opening error
	{
		cout << "Error Opening file. \n";
	}
	else
	{
		int count = 0;	//count variable set to 0
		while (count < numsauce && file >> sauceprice[count])		//while loop to work through the array assigning values from the file to the elements
			count++;

		file.close();		//close the file
	}
	 getdata(sauce, sauceprice, saucesold);
	 sales = calcsales(sauceprice, saucesold, saucetotal);
	 displaytable(sauce, sauceprice, saucetotal, saucesold, sales);

	 return 0;		//end program
}

/*****************************************************************
	Void getdata function ()
	accepts string, double, int array does not return anything
	gets user data and stores number sauces sold in saucesold array
******************************************************************/
void getdata(string SAUCE[numsauce], double PRICE[numsauce], int SOLD[numsauce])
{
	for (int count = 0; count < numsauce; count++)
	{
		cout << showpoint << fixed << setprecision(2); 
		cout << "Sauce Name: " << SAUCE[count] << "\tPrice: $" << PRICE[count] << ". \n";
		cout << "Enter Number of Product Sold: ";
		cin >> SOLD[count];
		if (SOLD[count] < 1)
		{
			cout << "The Amount cannot be less than 0.";
			cout << "Enter Number of Product Sold: ";
			cin >> SOLD[count];
		}
	}
}

/******************************************************************
	double calcsales ()
	accepts double and an int array, returns a double 
	calculates the total sales and the sales for each item and stores 
	in an array
********************************************************************/
double calcsales(double PRICE[numsauce], int SOLD[numsauce], double SAUCETOTAL[numsauce])
{
	double total = 0;		//set accumulator to 0

	for (int count = 0; count < numsauce; count++)
	{
		double sauce = PRICE[count] * SOLD[count];
		SAUCETOTAL[count] = sauce;
		total += sauce;
	}
	return total;
}

/*************************************************************************
	Display Table Function
	Accpets arrays, string, double, double, and int returns nothing
	calls highestlowest function to find the highest and lowest product sold
	displays information and total sales
****************************************************************************/
void displaytable(string SAUCE[numsauce], double PRICE[numsauce], double SAUCETOTAL[numsauce], int SOLD[numsauce], double total)
{
	
	
	cout << "\t\t\tBBQ Sauce Company\t\t\t\n";						//table header
	cout << "_________________________________________\n";			//table header
	cout << "Sauce\t\tPrice\t\tQTY\t\tTotal Sales\n";				//table header

	for (int count = 0; count < numsauce; count++)					//for loop to work through the arrays in parallel and display data from arrays
	{
		cout << SAUCE[count] << "\t\t" << "$" << PRICE[count] << "\t\t" << SOLD[count] << "\t\t" << "$" << SAUCETOTAL[count] << "\n";
	}
	cout << "Total Sales from Products Sold is: $" << total << "\n";
	
	
	

}

/******************************************************************************
	highest lowest functions
	identifies the highest or lowest item based on price
*******************************************************************************/
double lowest(double TOTAL[numsauce], double& low)
{
	
	//get lowest value first
	low = TOTAL[0];		//sets low to first element of array

	for (int count = 1; count < numsauce; count++)		//to work through array to get lowest 
	{
		if (TOTAL[count] < low)
		{
			low = count;
		}
		return low;
	}
}

double highest(double TOTAL[numsauce], double& high)
{
		
	//get highest value next
	high = TOTAL[0];		//sets the high to the first element of array

	for (int count = 1; count > numsauce; count++)		//to work through array to get highest 
	{
		if (TOTAL[count] > high)
		{
			high = count;
		}
		high = count;		//high value location passed back to displaytable function by reference
	}
	return high;
}

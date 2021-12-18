/*
	Doug Wheeldon
	CISS 241
	Programming I
*/
/*
You have been tasked by the IT department of Acme Electronics to write a program to generate a report about last year’s sales. The report created by the program will be the table shown below. 
It will also display the division and quarter with the highest sales and the division and quarter with the lowest sales for the year.

The program will need to use a 2-Dimensional array. This array that will hold the sales totals for 4 divisions and for 4 quarters. 
The array must be created to also hold the total for each division and for each quarter (in other words the total for each column and each row, when thinking about the 
array as a table or spreadsheet). 
These totals will be calculated by the program once the values have been inputted by the user. This array will have the quarters as the columns and the divisions as the rows. 
The last column will hold the totals for the rows (division totals) and the last row will hold the totals for the columns (quarter totals). Note: the very last element in the
array will not be used.

Another array should be used to store the division names of North, South, East, and West. This array will be used when getting the inputs from the user and for the outputs.

The program should use two global constants called ROWS and COLS.

The program must provide the following functions:

double CalculateTotal(double [][COLS]);
	Calculates the total of the complete array except for the totals in the last column and last row.
	Returns the total.
double CalculateAverage(double [][COLS]);
	Calculates the average of all the values in the array except for the column and row with the totals in them.
	Returns the average.
double CalculateRowTotal(double [][COLS], int);
	Calculates the total for row that is specified by the second parameter.
	Returns the total for the specified row.
double CalculateColumnTotal(double [][COLS], int);
	Calculates the total for a column that is specified by the second parameter.
	Returns the total for the specified column.
double FindHighest(double [][COLS], int&, int&);
	Finds the highest sales in the array.
	Provides the index values (row, column) of where the highest value is located in the array.
	Returns the highest amount.
double FindLowest(double [][COLS], int&, int&);
	Finds the lowest sales in the array.
	Provides the index values of where the lowest value is located in the array.
	Returns the lowest amount.
*/
/*
		pseudocode
	inititate global constants rows and cols
	intitiate function prototypes
	create 2d array to hold the 4 divisions and total as rows and 4 quarters and total as col
	create an array for division names
	main()
		inititate variables for total, average row, highest, lowest
		get user inputs
		call calculateTotal
		call Calculate Average
		call CalculateRow total
		call calculate column total
		call findhighest
		call findlowest
		display results
		EOP
	CalculateTotal
		initiate total value set to 0
		calculate total of all vaules in array adds to accumulator
		return total
	CalculateAverage
		inititae total set to 0
		calculate total of all values in array adds to accumulator
		averages the total
		retunrs average

	CalculateRowTotal
		initiate a accumulator for each division
		for loop to change rows
			nested for loop to add add contents of cols to accumulator
			loop to save result in last col in row
		returns values of the four rows

	CalculatecolumnTotal
	initiate a accumulator for each quarter
	for loop to change col
		for loop to add contents of rows to accumulator
		loop to save result in last row for each quarter
	returns value of the four quaters

	Findhighest
	initiate highest variable set to first column / row in array
	for loop to work though array for col
		for loop to work through array for rows
			if loop to find highest value
				replace highest value
	return highest value

	Findlowest
	initiate lowest variable set to first column/row in array
	for loop to work through array for col
		for loop to work through array for rows
			if loop to find lowest value
				replace lowest value
	return lowest
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//global constants for ROWS and COLS total elements
const int ROWS = 5, COLS = 5;

//arrays to hold the values
double  DIVQUART[ROWS][COLS];
string  NAMES[] = { "North", "South", "East", "West", "Quarter Total", "Quarter 1", "Quarter 2", "Quarter 3", "Quarter 4", "Division Total" };

//function prototypes
double CalculateTotal(double[][COLS]);
double CalculateAverage(double[][COLS]);
double CalculateRowTotal(double[][COLS], int);
double CalculateColumnTotal(double[][COLS], int);
double FindHighest(double[][COLS], int&, int&);
double FindLowest(double[][COLS], int&, int&);

int main()
{
	int hrow;	//high row
	int lrow;	//low row
	int hcol;	//high column
	int lcol;	//low column

	//get user input and store it in DIVQUART array, 
	//using NAMES array to get values for each area
	cout << "\t\t\t\t Company Division Quarterly Sales\n";
	cout << "\t\t\t\t__________________________________\n\n";
	
		for (int row = 0; row < 4; row++) //using row as count to keep track of the divisions
		{
			for (int col = 0; col < 4; col++) //using col as count to keep track of the quarter
			{
				cout << "\t\t Enter the Sales for the " << NAMES[row] << " Division for " << NAMES[col + 5] << ":";
				cin >> DIVQUART[row][col];
			}
			cout << endl;
		}
		/*Test input
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				cout << "Input for the " << NAMES[row] << " Division, for" << NAMES[col + 5] << " is " << DIVQUART[row][col] << "." << endl;
			}
		}
		*/

		//call functions
		double total = CalculateTotal(DIVQUART);
		double average = CalculateAverage(DIVQUART);
		CalculateRowTotal(DIVQUART, 0);
		CalculateRowTotal(DIVQUART, 1);
		CalculateRowTotal(DIVQUART, 2); 
		CalculateRowTotal(DIVQUART, 3);
		//CalculateRowTotal(DIVQUART, 4);
		CalculateColumnTotal(DIVQUART, 0);
		CalculateColumnTotal(DIVQUART, 1);
		CalculateColumnTotal(DIVQUART, 2);
		CalculateColumnTotal(DIVQUART, 3);
		//CalculateColumnTotal(DIVQUART, 4);
		double highest = FindHighest(DIVQUART, hrow, hcol);
		double lowest = FindLowest(DIVQUART, lrow, lcol);

		//display the spreadsheet
	cout << "\t\t\t      Company Division Quarterly Sales Chart\n";
	cout << "\t-------------------------------------------------------------------------------\n";
	cout << "\t|_____________|" << "_" << NAMES[5] << "_|" << "_" << NAMES[6] << "_|" << "_" << NAMES[7] << "_|" << "_" << NAMES[8] << "_|" << "_" << NAMES[9] << "|" << endl;
	cout << "\t-------------------------------------------------------------------------------\n";
	cout << "\t|___" << setw(8) << NAMES[0] << "__|" << "___" << setw(6) << fixed << showpoint << setprecision(2) << DIVQUART[0][0] << "__|" << "__" << setw(7) << DIVQUART[0][1] << "__|" << "__" << setw(7) << DIVQUART[0][2] << "__| " << "__" << setw(6) << DIVQUART[0][3] << "__| " << "__" << setw(10) << DIVQUART[0][4] << "__| " << endl;
	cout << "\t-------------------------------------------------------------------------------\n";
	cout << "\t|___" << setw(8) << NAMES[1] << "__|" << "___" << setw(6) << fixed << showpoint << setprecision(2) << DIVQUART[1][0] << "__|" << "__" << setw(7) << DIVQUART[1][1] << "__|" << "__" << setw(7) << DIVQUART[1][2] << "__| " << "__" << setw(6) << DIVQUART[1][3] << "__| " << "__" << setw(10) << DIVQUART[1][4] << "__| " << endl;
	cout << "\t-------------------------------------------------------------------------------\n";
	cout << "\t|___" << setw(8) << NAMES[2] << "__|" << "___" << setw(6) << fixed << showpoint << setprecision(2) << DIVQUART[2][0] << "__|" << "__" << setw(7) << DIVQUART[2][1] << "__|" << "__" << setw(7) << DIVQUART[2][2] << "__| " << "__" << setw(6) << DIVQUART[2][3] << "__| " << "__" << setw(10) << DIVQUART[2][4] << "__| " << endl;
	cout << "\t-------------------------------------------------------------------------------\n";
	cout << "\t|___" << setw(8) << NAMES[3] << "__|" << "___" << setw(6) << fixed << showpoint << setprecision(2) << DIVQUART[3][0] << "__|" << "__" << setw(7) <<DIVQUART[3][1] << "__|" << "__" << setw(7) << DIVQUART[3][2] << "__| " << "__" << setw(6) << DIVQUART[3][3] << "__| " << "__" << setw(10) << DIVQUART[3][4] << "__| " << endl;
	cout << "\t-------------------------------------------------------------------------------\n";
	cout << "\t|" << setw(8) << NAMES[4] << "|" << "___" << setw(6) << fixed << showpoint << setprecision(2) << DIVQUART[4][0] << "__|" << "__" << setw(7) << DIVQUART[4][1] << "__|" << "__" << setw(7) << DIVQUART[4][2] << "__| " << "__" << setw(6) << DIVQUART[4][3] << "__| " << "__" << setw(10) << "___________|" << endl;
	cout << "\t-------------------------------------------------------------------------------\n";
	
	//Test for the average
	//cout << "The Average is $" << average << endl;
	//test for calculate total
	cout << "Total Company Sales is $" << total << "\n";
	//display division and quarter with highest sales
	cout << "The " << NAMES[hrow] << " Division had the highest sales for " << NAMES[(hcol + 5)] << " With a total of $" << highest << "." << endl;
	//display division and quarter with lowest sales
	cout << "The " << NAMES[lrow] << "Division had the lowest sales for " << NAMES[(lcol + 5)] << " with a total of $" << lowest << ".\n";
	//display company average sales
	cout << "The Company Sales Average is $" << average << "." << endl;
	return 0;
}

/******************************************************************
*			Calculate Total () accepts double array               *
*		totals contents of the array and returns it				  *
*******************************************************************/

double CalculateTotal(double Data[][COLS])
{
	double total = 0;  //total 
	
	//sum the array elements
	for (int row = 0; row < COLS - 1; row++)
	{
		for (int col = 0; col < ROWS - 1; col++)
			total += Data[row][col];
	}
	//test for calculate total
	//cout << "Total Company Sales is $" << total << endl;
	//return result 
	return total;
}

/****************************************************************
*				Calculate Average ()                            *				
*	totals contents of the array, averages total, returns it    *
*																*				
*****************************************************************/

double CalculateAverage(double Data[][COLS])
{
	double total = 0;  //total 
	double average;

	//sum the array elements
	for (int row = 0; row < COLS - 1; row++)
	{
		for (int col = 0; col < ROWS - 1; col++)
			total += Data[row][col];
	}
	average = total / 16;
	//Test for the average
	//cout << "The Average is $" << average << endl;
	//return result 
	return average;
}

/*****************************************************************
*			Calculate row total ()								 *
*	totals each row in the array and returns it					 *
*																 *	
*****************************************************************/

double CalculateRowTotal(double data[][COLS], int b)
{
	int rowtotal = 0; //initialize accumulator
	int count;		//counter
	//sum row data
	for (count = 0; count < COLS - 1; count++)
	{
		rowtotal += data[b][count];
	}
	data[b][count] = rowtotal;
	// test row data
	//cout << "Row " << count << " total is $" << endl;
	//return total
	return rowtotal;
}

/******************************************************************
*			Calcuate column total ()						      *
*      Totals each column and returns it						  *
******************************************************************/

double CalculateColumnTotal(double data[][COLS], int b)
{
	int columntotal = 0; //initialize accumulator
	int count;		//counter
	//sum row data
	for (count = 0; count < ROWS - 1; count++)
	{
		columntotal += data[count][b];
	}
	data[count][b] = columntotal;
	// test row data
	//cout << "Column" << count << " total is $" << columntotal << endl;
	//return total
	return columntotal;
}

/*********************************************************************
*						Find Highest ()								 *	
*	finds the highest sales in array, returns location and value     *
*                                                                    *
**********************************************************************/

double FindHighest(double data[][COLS], int &hrow, int &hcol)
{
	double highest = data[0][0];
	hrow = 0; // setting hrow to 0
	hcol = 0; // setting hcol to 0

	for (int row = 0; row < ROWS - 1; row++)  //row steps through the rows
	{
		for (int col = 0; col < COLS - 1; col++)	// col steps through the columns
		{
			if (data[row][col] > highest)			//if loop to find the highest and replaces it with the higher value
			{
				highest = data[row][col];			//assigns values for the highest at the target location
				hrow = row;							//assigns row location for highest value
				hcol = col;							//assigns column location for highest value
			}
		}
	}
	return highest;									//returns colum location
}

/*******************************************************************
*						Find Lowest ()							   *
* finds the lowest sales in array, returns location and value      *
*																   *
*********************************************************************/

double FindLowest(double data[][COLS], int& lrow, int& lcol)
{
	double lowest = data[0][0];
	lrow = 0; // setting hrow to 0
	lcol = 0; // setting hcol to 0

	for (int row = 0; row < ROWS - 1; row++)  //row steps through the rows
	{
		for (int col = 0; col < COLS - 1; col++)	// col steps through the columns
		{
			if (data[row][col] < lowest)			//if loop to find the highest and replaces it with the higher value
			{
				lowest = data[row][col];			//assigns values for the highest at the target location
				lrow = row;							//assigns row location for highest value
				lcol = col;							//assigns column location for highest value
			}
		}
	}
	return lowest;									//returns colum location
}
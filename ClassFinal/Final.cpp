/*
* Doug Wheeldon
* CIS 241
* Programming I
*/
/*
* Airline Reservation Program
* Allows the user to reserve airline seats from a menu. The menu also provides accesss to a seating chart 
* where # is available seats and * is seats that are taken. Additiona menu options are for the total sales 
* of the plane, and the number of seats available by section. 
* The seat reservation system checks to see if the seat is available, and how many open seats is available in the section.
* When the row is selected it displays the number of open seats in the row.
*/
/*
*	pseudocode
* initialize global constants
* initial ints for row totals
* intialize arrays for seats
* function prototypes for display menu and seatchart
* main ()
*	display welcome
*	displayment()
*	eop
* displaymenu()
*	variables for menu items, ticket sales, ticket prices, choice, seat sold, user row and user col selections
* display menu
* switch case for menu items
*	case items for seat selection and row validation. 
*	case item for dispalying the seating chart
*	case item for displaying empty seats on flight
*	case item for displaying total sales on the flight
*	case item for ending program
* seatchart()
*	display seat chart from arrays
*	display row and seat number for first class and coach
* 
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//Global constants
const int FCROW = 5;	//number rows in first class
const int FCCOL = 4;	//number seats in first class per row
const int CROW = 5;	//number rows in coach price cat 1
const int CCOL = 6;	// number seats in each row price cat 1 coach

int fcrow, c1row, c2row, fccol, c1col, c2col;

//arrays for seats
char FIRSTSEATS[FCROW][FCCOL];	// array for first class seats
char C1SEATS[CROW][CCOL];		// array for coach price cat 1 seats
char C2SEATS[CROW][CCOL];		//array for coach price cat 2 seats

//function prototypes
void DISPLAYMENU(char [FCROW][FCCOL], char [CROW][CCOL], char [CROW][CCOL]);
void SEATCHART(char[FCROW][FCCOL], char[CCOL][CCOL], char[CCOL][CCOL]);


int main()
{
	//Welcome to program header
	cout << "\t\t\t\t\t Welcome to the Airline Reservation System" << endl;
	cout << "\t\t\t\t\t-------------------------------------------\n\n";
	DISPLAYMENU(FIRSTSEATS, C1SEATS, C2SEATS);
	//end program
	return 0;
}

/**************************************************************
*		Displays the Main Menu                                *  
* Gives options and calls functions or performs appropriate   *
* statements                                                  *
***************************************************************/

void DISPLAYMENU(char FIRSTSEATS[FCROW][FCCOL], char C1SEATS[CROW][CCOL], char C2SEATS[CROW][CCOL])

{
	const int Firstclass = 1, Coachplus = 2, Coacheconomy = 3, Seatchart = 4, Sales = 5, Emptyseats = 6, Exit = 7; //menu options
	double firstseatt = 0, c1seatt = 0, c2seatt = 0, totalsales = 0; // variable for ticket sales totals
	double firstprice = 0, coach1price = 0, coach2price = 0; //ticket price variables 
	int choice = 0; //hold menu choice
	int  fcsold = 0, c1sold = 0, c2sold = 0, Ufcseat, Uc1seat, Uc2seat, fcrow, c1row, c2row, fccol, c1col, c2col, fcavail=0;

	do
	{
		cout << "\t\t\t\t\t\t\tMain Menu\n\n";
		cout << "\t\t\t\t\t\t   1. First Class Seat Reservation\n";
		cout << "\t\t\t\t\t\t   2. Coach Plus Seat Reservation\n";
		cout << "\t\t\t\t\t\t   3. Coach Economy Seat Reservation\n";
		cout << "\t\t\t\t\t\t   4. Seating Chart\n";
		cout << "\t\t\t\t\t\t   5. Flight Sales\n";
		cout << "\t\t\t\t\t\t   6. Empty Seats on plane\n";
		cout << "\t\t\t\t\t\t   7. Exit Program\n\n";
		cout << "\t\t\t\t\t\t   Make a Selection: ";
		cin >> choice;
		if (choice < 1 || choice >7)
		{
			cout << "\n\n\t\t\t\t   Invalid Choice. Select an option between 1 and 7.\n";
			cout << "\t\t\t\t\t\t   Make a Selection: ";
			cin >> choice;
		}

		//open file
		fstream prices;
		prices.open("d:/SeatPrices.txt");

		//failure check
		if (!prices.is_open())
		{
			cout << "File not found.";
			exit(1);
		}

		//read file
		prices >> firstprice;
		prices >> coach1price;
		prices >> coach2price;

		//close the file
		prices.close();


		//switch case for menu selections
		switch (choice)
		{
		case 1:
		{
			//cout << "Test choice 1 seat reserve system call";
			cout << "\n\t\t\t\t\t\tFirst Class Seat Reservation" << endl;
			cout << "\t\t\t\t\t\tThe Number of Open Seats is " << (20 - fcsold) << endl;
			cout << "\t\t\t\t\t\tThe Cost is $" << firstprice << ".\n";
			cout << "\t\t\t\t\t        How Many Seats would you like: ";
			cin >> Ufcseat;
			for (int seat = 0; seat <= Ufcseat; seat++)  //for loop to get the desired number of seats reserved
			{
				cout << "\t\t\t\t\tWhich row would you like. First Class is rows 1 - 5: ";
				cin >> fcrow;
				if (fcrow < 1 || fcrow >5)	//validate range for row choice
				{
					cout << "\t\t\t\t\tYou have entered and invalid row. Which row would you like: ";
					cin >> fcrow;
				}
				
				
				cout << "\t\t\tWhich seat would you like. First Class seats are 1 - 4, seat 1 and 4 are window seats.";
				cin >> fccol;
				if (fccol < 1 || fccol > 4)	//validate range for seat choice
				{
					cout << "\t\t\tYou have entered and invalid seat. Which seat would you like: ";
					cin >> fccol;
				}
				if (FIRSTSEATS[fcrow - 1][fccol - 1] != '*') //verify seat is not taken
				{
					FIRSTSEATS[fcrow - 1][fccol - 1] = '*';
					cout << endl << "\t\t\t\t\t\tYour Seat has been reserved.\n";
				}
				else
				{
					cout << "\t\t\t\t\t\tThat Seat is unavailable." << endl;
					
				}
			}
			fcsold = Ufcseat;
			firstseatt = Ufcseat * firstprice;
			break;

		}


		case 2: //coach 1 seat 1st 5 rows of coach
		{

			//cout << "Test choice 1 seat reserve system call";
			cout << "\n\t\t\t\t\t\tCoach Plus Seat Reservation" << endl;
			cout << "\t\t\t\t\t\tThe Number of Open Seats is " << (30 - c1sold) << endl;
			cout << "\t\t\t\t\t\tThe Cost is $" << coach1price << ".\n";
			cout << "\t\t\t\t\t        How Many Seats would you like: ";
			cin >> Uc1seat;
			for (int seat = 0; seat <= Uc1seat; seat++)  //for loop to get the desired number of seats reserved
			{
				cout << "\t\t\t\t\tWhich row would you like. Coach Plus is rows 6 - 10: ";
				cin >> c1row;
				if (c1row < 6 || c1row >10)	//validate range for row choice
				{
					cout << "\t\t\t\t\tYou have entered and invalid row. Which row would you like: ";
					cin >> c1row;
				}
				
				cout << "\t\t\tWhich seat would you like. Coach Plus seats are 1 - 6, seat 1 and 6 are window seats.";
				cin >> c1col;
				if (c1col < 1 || c1col > 6)	//validate range for seat choice
				{
					cout << "\t\t\tYou have entered and invalid seat. Which seat would you like: ";
					cin >> c1col;
				}
				if (FIRSTSEATS[c1row - 1][c1col - 1] != '*') //validate seat is not taken
				{
					FIRSTSEATS[c1row - 1][c1col - 1] = '*';
					cout << endl << "\t\t\t\t\t\tYour Seat has been reserved.";
				}
				else
				{
					cout << "\t\t\t\t\t\tThat Seat is unavailable." << endl;
					
				}
			}
			c1sold = Uc1seat;
			c1seatt = Uc1seat * coach1price; //calcualt total price for seats sold
			break;
		}
		case 3: //coach 2 seat last 5 rows of coach
		{

			//cout << "Test choice 1 seat reserve system call";
			cout << "\n\t\t\t\t\t\tCoach Economy Seat Reservation" << endl;
			cout << "\t\t\t\t\t\tThe Number of Open Seats is " << (30 - c2sold) << endl;
			cout << "\t\t\t\t\t\tThe Cost is $" << coach2price << ".\n1";
			cout << "\t\t\t\t\t        How Many Seats would you like: ";
			cin >> Uc2seat;
			for (int seat = 0; seat <= Uc2seat; seat++)  //for loop to get the desired number of seats reserved
			{
				cout << "\t\t\t\t\tWhich row would you like. Coach Economy is rows 11 - 15: ";
				cin >> c2row;
				if (c2row < 11 || c2row > 15)	//validate range for row choice
				{
					cout << "\t\t\t\t\tYou have entered and invalid row. Which row would you like: ";
					cin >> c2row;
				}
				
				cout << "\t\t\tWhich seat would you like. Coach Economy seats are 1 - 6, seat 1 and 6 are window seats.";
				cin >> c2col;
				if (c2col < 1 || c2col > 6)	//validate range for seat choice
				{
					cout << "\t\t\tYou have entered and invalid seat. Which seat would you like: ";
					cin >> c2col;
				}
				if (FIRSTSEATS[c2row - 1][c2col - 1] != '*')	//validate seat is not taken
				{
					FIRSTSEATS[c2row - 1][c2col - 1] = '*';
					cout << endl << "\t\t\t\t\t\tYour Seat has been reserved.";
				}
				else
				{
					cout << "\t\t\t\t\t\tThat Seat is unavailable." << endl;
					
				}

			}
			c2sold = Uc2seat;
			c2seatt = Uc2seat * coach2price; // calculate total price for seats sold
			break;
		}
		case 4:
		{
			SEATCHART(FIRSTSEATS, C1SEATS, C2SEATS); //call seat chart function
			break;
		}
		case 5:
		{
			//cout << "test choice 3 total flight sales call";
			totalsales = firstseatt + c1seatt + c2seatt;
			cout << "\t\t\t\t\t\tThe total cost for the tickets is: $" << totalsales  <<"\n\n";
			break;
		}
		case 6:
		{
			cout << "\t\t\t\t\t\tFirst Class has " << (20 - fcsold) << " available seats.\n";
			cout << "\t\t\t\t\t\tCoach Plus has " << (30 - c1sold) << " available seats.\n";
			cout << "\t\t\t\t\t\tCoach Economy has " << (30 - c2sold) << " available seats.\n\n";
			break;
		}
		default:
		{
			cout << "\t\t\t\t  Thank you for using the Airline Reservation System." << endl;
			cout << "\t\t\t\t\t\t\t Goodbye." << endl;

		}
		}
	} while (choice != 7);
}
	


/************************************************************************************
					Seat Chart ()                                                   *
 Displays a seat chart with row numbers and seat numbers	                        *
 # = available * = taken                                                            *
**************************************************************************************/
void SEATCHART(char firstseat[FCROW][FCCOL], char c1seats[CROW][CCOL], char c2seats[CROW][CCOL])
{
		
	cout << right << setw(2) << "\t\t\t\t" << "\t  1" << "\t  2" << "\t  3" << "\t  4\n\n";
	//first class seat 
	for (int row = 0; row < FCROW; row++)
	{
		cout << right << setw(2) << "\t\tROW" << row + 1 << "\t\t\t";

		for (int col = 0; col < FCCOL; col++)
		{
			FIRSTSEATS[row][col] = '#';
			cout << setw(2) << FIRSTSEATS;
		}
		cout << endl;
	}

	cout << right << setw(2) << "\n\t\t\t" << "\t  1" << "\t  2" << "\t  3" << "\t  4" << "\t 5" << "\t 6\n\n";
	//1st coach seats
	for (int row = 0; row < CROW; row++)
	{
		cout << right << setw(2) << "\t\tROW" << row + 6 << "\t\t";

		for (int col = 0; col < CCOL; col++)
		{
			C1SEATS[row][col] = '#';
			cout << setw(2) << C1SEATS;
		}
		cout << endl;
	}
	//2nd coach seats
	for (int row = 0; row < CROW; row++)
	{
		cout << right << setw(2) << "\t\tROW" << row + 11 << "\t\t";

		for (int col = 0; col < CCOL; col++)
		{
			C2SEATS[row][col] = '#';
			cout << setw(2) << C2SEATS;
		}
		cout << endl;
	}
}
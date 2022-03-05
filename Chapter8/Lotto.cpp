#include <iostream>
using namespace std;

// Function prototype
bool searchList(const long[], int, long);

// Constant for array size
const int SIZE = 10;

int main()
{
	// Array of numbers that are always played
	long ticket[SIZE] = { 13579,  26791,
		26792,  33445,
		55555,  62483,
		77777,  79422,
		85647,  93121 };

	// This variable will hold the winning number.
	long winningNum;

	// Get this week's winning number.
	cout << "\nPlease enter this week's 5-digit "
		<< "winning lottery number: ";
	cin >> winningNum;

	// Search for the winning number.
	if (searchList(ticket, SIZE, winningNum))
	{
		// If searchList returned true, then
		// the player has a winning ticket.
		cout << "You have a winning ticket.\n";
	}
	else
	{
		cout << "You did not win this week." << endl;
	}

	return 0;
}

/********************************************************
 The searchList function accepts as arguments, an array
 of numbers, the size of the array, and the number to
 search for. It determines if the number to search for
 is in the set of stored numbers using a linear search.
 It returns true if the number is found, otherwise it
 returns false.

 Pseudo Code
 Declare found as boolean default to false - return value

 For count = 0 to size of array and not found increment by 1
	If element at count equals search value
		Set found to true
	End If
 End For

 Return found
********************************************************/
bool searchList(const long list[], int numElems, long value)
{
	
	int position = -1;	//to record the position of search value
	bool found = false; //flag to indicate if record was found
	
	for (int index = 0; index < numElems; index++)
	{
		if (list[index] == value)	//if value is found
		{
			found = true;			//set the flag
			position = index;		//record the next element
		}
		
	}
	return found;		//return the position or -1
}




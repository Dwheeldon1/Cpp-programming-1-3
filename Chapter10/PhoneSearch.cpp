/******************************************

Program Phone Search

This program allows the user to enter 
a part of a name to search for then displays the
full name and phone numer

Author: Doug Wheeldon

Created : 01/30/2022

Revisions : 

******************************************/
/*****************************************
function prototypes for getdata, search string and display
main ()
	populates phone array
	calls search string
	gets user input and returns data
	displays data
search string
	takes user data and searchs the array and gets the information
	returns found data 
	if data not found displays not found message
******************************************/
#include <iostream>
#include <string>
using namespace std;

void searchArray(string, string[], int);

int main()
{
	const int SIZE = 11;
	string names[SIZE] = { "Renee Javens, 678-1223", "Joe Looney, 586-0097", "Geri Palmer, 223-8787",
		"Lynn Presnell, 887-1212", "Bill Wolfe, 223-8878", "Sam Wiggins, 486-0998", "Bob Kain, 586-8712",
		"Tim Haynes, 586-7676","John Johnson, 223-9037", "Jean James, 678-4939", "Ron Palmer, 486-2783" };

	string userSearch;
	char again = 'Y';
	short counter = 0;

	// while loop is to repeat the search upon the user's discretion 
	while (toupper(again) == 'Y')
	{
		cout << "Type in a name to search: ";
		if (counter != 0)  // needed because on first pass (before first iteration) the getline function below
							 // would skip the first letter of userSearch. couldn't figure out why, but figured 
							 // out how to bypass it.
			cin.ignore();  // needed to ignore while loop entry upon repeat

		getline(cin, userSearch);
		cout << endl;

		searchArray(userSearch, names, SIZE);

		cin >> again; // input from searchArray function
		cout << endl;
		counter = 1;
	}

	system("pause");
	return 0;
}

// this function accepts a string and searches the array find_in for the string
// if the string is found, it will display the full string in the array 
void searchArray(string findStr, string arrayAt[], int size)
{
	bool match = false;
	for (int index = 0; index < size; index++)
	{
		if (arrayAt[index].find(findStr) != -1)
		{
			cout << arrayAt[index] << endl;
			match = true;
		}
	}
	if (!match)
		cout << "No matches found." << endl;

	cout << "Would you like to search again? (Y/N): ";
}
/*******************************************

Program TestScores

This program will keep track of 4 test scores
obtained from the user. The program will make use of 
2 arrays that are dynamically allocated using a pointer.

Author: Doug Wheeldon

Created : 01/23/2022

Revisions : 

******************************************/
/*****************************************
		Pseudocode
initiate a global const set to 4
initate a array of string for student names
initate a array of doubles for student scores
inititate function prototypes for getgrades, displaygrades, sort, average
main ()
	call getgrade
	call sort
	call average
	call displaygrade
getgrade ()
	prompt user in a loop to get the student name and test score
	will return via a pointer to arrays
sort ()
	will sort the test scores in ascending order
	will sort the student names keeping them with the test scores
average()
	calculate the average of the test scores
	return the average
displaygrade()
	will display the scores in a 2 column grid
	will display the average of the class scores

******************************************/

#include <iostream>
#include <iomanip>

using namespace std;

//global const for number of students
const int Size = 4;

//initate arrays 
//string students[Size];
//double scores[Size];

//function prototypes
void GetGrades(double* scores, string* students, int Size);
void DisplayGrades(double* scores, string* students, int Size, double avg);
void Sort(double* scores, string* students, int Size);
double Average(double* scores, int Size);

int main()
{
	double avg;			//variable to hold the average
	//initiate pointer arrays
	string* students = new string[Size];
	double* scores = new double[Size];

	//call functions
	GetGrades(scores, students, Size);
	Sort(scores, students, Size); 
	avg = Average(scores, Size);
	DisplayGrades(scores, students, Size, avg);

	//delete pointers from memory
	delete[] students;
	delete[] scores;

	//End program
	return 0;
}

/**********************************************************************
					GetGrades()
	accepts scores and students pointer arrays along with size variable
	accepts user input for student name and places it in appropriate array
	accepts user input for score and places it in appropriate array
	does not accept negative students or negative numbers
*************************************************************************/
void GetGrades(double* scores, string* students, int size)
{
	//for loop to work through arrays starting with student names 
	for (int count = 0; count < size; count++)
	{
		cout << "Enter Student Name: "; //obtain student name
		cin >> *(students + count);
		cout << "Enter Student Score: "; //Obtain student score
		cin >> *(scores + count);			 //work in parallel with student array
		while (*(scores+count) < 0)		// while loop to check for negative scores entry
		{
			cout << "Value cannot be a negative value." << endl;
			cout << "Enter Student Score: ";
			cin >> *(scores + count);
		}
	}
}

/***************************************************************************
							sort ()
 accepts scores, students array and size variable 
 sorts through the scores array and lists them in ascending order, students
 array sorted in parallel. 

****************************************************************************/
void Sort(double* scores, string* students, int Size)
{
	int startScan, minIndex;
	double minValue;

	for (startScan = 0; startScan < (Size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = scores[startScan];
		for (int index = startScan + 1; index < Size; index++)
		{
			if (*(scores + index) < minValue)
			{
				minValue = *(scores + index);
				minIndex = index;
			}
		}
		scores[minIndex] = scores[startScan];
		students[minIndex] = students[startScan];
		scores[startScan] = minValue;
	}
}

/****************************************************************************
					avg()
accepts scores array and size variable
works through the scores array and calculates the average returns a double
*****************************************************************************/
double Average(double* scores, int Size)
{
	double avg = 0, average = 0; //accumulator set to 0
	for (int count = 0; count < Size; count++)	//for loop to work through array
	{
		avg += *(scores + count);
		average = avg / Size;
	}
	return average;
}

/******************************************************************************
						displaygrades()
accepts scores and students array, size and avg variable. displays student names
and scores in a 2 column chart. displays avg
*******************************************************************************/
void DisplayGrades(double* scores, string* students, int Size, double avg)
{
	cout << fixed << setprecision(2) << showpoint;	// display two decimal places
	cout << "\t\t\tStudent Grades\t\t\t\n";
	cout << "_______________________________________________" << endl;
	cout << "\tStudent\t\t\t\t\tGrade" << endl;
	for (int count = 0; count < Size; count++)				//work through arrays to display data
	{
		cout << "\t" << *(students + count) << "\t\t\t\t" << *(scores + count) << endl;
	}
	cout << "The Average of Tests Scores is: " << avg << endl;
}

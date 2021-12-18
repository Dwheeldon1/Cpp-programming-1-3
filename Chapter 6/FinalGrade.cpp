/*
Doug Wheeldon
CISS 241
Programming I
*/

/*
		Final Grade
In this assignment, you will be writing a program to help a teacher calculate the final grade for all the exams a student has taken. The student’s lowest grade must be dropped from the average.

The program is required to have the following functions:

void GetScore(double & score)
	This function should prompt the user for a test score, the test scored entered should be stored in the reference parameter.
	The function should validate the user input before ending the function. The grade entered must be greater than or equal to 0 and less than or equal to 100.
	The program will get 6 grades from the user, so this method must be called 6 times.
void CalcAverage(double score1, double score2, double score3, double score4, double score5, double score6)
	This function will calculate the average of the five highest test scores.
	The function will be called by main only one time, the six test scores must be passed all at once via the parameters.
	Average must be displayed with a precision of 2 decimal places.
	This function will use the FindLowest function to know which test score to drop.
double FindLowest(double score1, double score2, double score3, double score4, double score5, double score6)
	This function will find and return the lowest score of the scores passed to it.
	This method must be called by CalcAverage, which uses the function to determine which of the six scores to drop.
*/
/*
	pseudocode
	function prototypes
	main function
	call get score
		get 6 scores from user 
		validate score is between 0 and 100
	call clac average
		accepts the 6 scores 
		calls findlowest function
		averages top 5 scores
		display averages with precision of 2
	findlowest function
		find and return the lowest score


*/

#include <iostream>
#include <iomanip>

using namespace std;

//function prototypes
void GetScore(double &);
void CalcAverage(double, double, double, double, double, double);
double FindLowest(double, double, double, double, double, double);

int main()
{
	double score1, score2, score3, score4, score5, score6;	//variables for scores

	
	//calling getscore for the 6 variables
		GetScore(score1);
		GetScore(score2);
		GetScore(score3);
		GetScore(score4);
		GetScore(score5);
		GetScore(score6);
	//calling calc average	
		CalcAverage(score1, score2, score3, score4, score5, score6);
	// testing GetScore ()
	//	cout << "In Main Score 1 is " << score1 << " Score 2 is " << score2 << " Score 3 is " << score3 << " Score 4 is " << score4 << " Score 5 is " << score5 << " Score 6 is " << score6 << endl;
		return 0;
}

/*****************************************************************************************
*		GetScore ()                                                                      *
*  gets scores from user and validates they are between 0 and 100                        *
******************************************************************************************/

void GetScore(double& score)
{
	cout << "Enter a Test Score: ";
	cin >> score; 
	if (score < 0 || score > 100)
	{
		cout << "Test Score is out of range." << endl;
		cout << "Enter a Test Score: ";
		cin >> score;
	}
}

/*******************************************************************************************
*		CalcAverage()                                                                      *
* calculates the average of the five highest test scores                                   *
* calls the FindLowest () to get the lowest score and remove it                            *
* Average is displayed with a precision of 2 decimals                                      *
********************************************************************************************/

void CalcAverage(double score1, double score2, double score3, double score4, double score5, double score6)
{
	double scoreTotal, Average;	//variables for total score and average score

	//totalling the score
	scoreTotal = score1 + score2 + score3 + score4 + score5 + score6;

	//calling the FindLowest () and saving lowest score to Lowest variable
	double Lowest = FindLowest(score1, score2, score3, score4, score5, score6);

	//removing the lowest and assigning new total 
	double Total = scoreTotal - Lowest;

	//calculating the average
	Average = Total / 5;

	//display average
	cout << fixed << showpoint << setprecision(2);
	cout << "The Average of the five highest scores is: " << Average << endl;
}

/*********************************************************************************************
*		FindLowest ()                                                                        *
* finds the lowest score and sends it back as Lowest variable to be removed                  *
**********************************************************************************************/

double FindLowest(double score1, double score2, double score3, double score4, double score5, double score6)
{
	double lowest = score1;
	if (score2 < lowest)
	{
		lowest = score2;
	}
	else if (score3 < lowest)
	{
		lowest = score3;
	}
	else if (score4 < lowest)
	{
		lowest = score4;
	}
	else if (score5 < lowest)
	{
		lowest = score5;
	}
	else if (score6 < lowest)
	{
		lowest = score6;
	}
	//cout << "the lowest is " << lowest;
	return lowest;
}
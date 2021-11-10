/*
		Test Average
	Write a program that asks for five test scores. The program should calculate the average
	test score and display it. The number displayed should be formatted in fixed-point notation,
	with one decimal point of precision.
*/
/*
		psuedocode
	initate a variable for test score 1
	initiate a variable for test score 2
	initaite a variable tor test score 3
	initiate a variable for test score 4
	initiate a variable for test score 5
	initate a variable for the average score
	Display enter test score 1
	input score 1
	Display enter test score 2
	input score 2
	Display enter test score 3
	input score 3
	Display enter test score 4
	input score 4
	Display enter test score 5
	input score 5
	calculate total score
	calculate average of 5 scores
	display average
*/

#include <iostream> //for cout and cin
#include <iomanip> //for fixed, setprecision, showpoint

using namespace std;

int main()
{
	double test_score1,
		test_score2,
		test_score3,
		test_score4,
		test_score5,
		total_score,
		average;

	//get the test scores
	cout << "Enter the first test score: ";
	cin >> test_score1;
	cout << "Enter the second test score: ";
	cin >> test_score2;
	cout << "Enter the third test score: ";
	cin >> test_score3;
	cout << "Enter the fourth test score: ";
	cin >> test_score4;
	cout << "Enter the fifth test score: ";
	cin >> test_score5;

	//calculate the total test scores
	total_score = test_score1 + test_score2 + test_score3 + test_score4 + test_score5;

	//calculate the average
	average = total_score / 5;

	//display the average
	cout << setprecision(1) << fixed << showpoint;
	cout << "The average fo the test scores is: " << average;
		return 0;
}
/*
		Body Mass Index
	Write a program that calculates and displays a person's body mass index (BMI). The
	BMI is often used to determine wheter a person is overwight or underweight for his or her
	height. A person's BMI is calculated with the following formula:

	BMI = weight x703/height^2

	where weight is measured in pounds and height is measured in inches. the program should display
	a message indicating wheter the person has optimal weight, is underweight, or is overweight.
	A persons weight is considered to be optimal if his or her BMI is between 18.5 and 25. 
	If the BMI is less than 18.5, the person is considered to be underweight. If the BMI value is 
	greater than 25, the person is considered to be overweight.
*/
/*
	pseudocode
initiate a variable for weight
initiate a variable for height 
initiate a variable for BMI
display enter a weight in lbs
input weight
display enter a height in inches
input height
calculate BMI=weight * (703 / pow(height, 2.0))
if statement to determine if bmi is optimal between 18.5 and 25
else if statement to determine if bmi is underweight less than 18.5 
else statemen to determine if bmi is greater than 25 overweight
display bmi and if it is optimal underweight or overweight
EOP

*/

#include <iostream>		//for cout and cin
#include <cmath>		//for pow
using namespace std;

int main()
{
	double weight,
		height,
		BMI;

	//get weight and height from user
	cout << "Enter a weight in pounds: ";
	cin >> weight;
	cout << "Enter a height in inches: ";
	cin >> height;

	//calculate BMI
	BMI = weight * (703 / pow(height, 2.0));

	//if statement to determine if the BMI is optimal between 18.5 and 25
	if (BMI > 18.5 && BMI < 25)
	{
		cout << "Your BMI is " << BMI << " and is considered optimal." << endl;
	}
	else if (BMI < 18.5)
	{
		cout << "Your BMI is: " << BMI << " and is considered underweight." << endl;
	}
	else if (BMI > 25)
		{
		cout << "your BMI is: " << BMI << " and is considered overweight." << endl;
		}
	else
	return 0;	//to end the program
}
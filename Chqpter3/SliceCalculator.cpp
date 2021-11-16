/*
A restaurant called Tony’s Pizza Palace needs a program to help calculate the number of slices a pizza of any size can be divided into, and how many pizzas should be ordered for a party.
The program will assume each person at the party will eat 3 slices of pizza each.

The program should prompt the user for the diameter of the pizzas they wish to order. It will also ask the user for the number of people who will be at the party. 
The program will then calculate and display the number of slices per pizza and the number of pizzas needed for the party (must be full pizzas). Facts you need to know:

A slice must have an area of 14.125 inches
Number of slices per pizza is the area of the pizza divided by the area of a slice
Area of a pizza is calculated with Area = PI * r2
PI = 3.14159
r is the radius of the pizza
The number of slices should be a fixed point and rounded to one decimal place
PI must be a named constant
*/

/*
Psuedocode

Initiate a constant variable for PI at 3.14159
Initiate a variable for the number or people
Initiate a variable for the diameter of the pizza
Initiate a variable for the radius of the pizza
Initiate a variable for the area of the pizza
Intitante a constant variable for the area of a slice at 14.125
Intitate a variable for the total number of slices
Initiate a variable for the total number of people fed from each pizza
Initiate a variable for the number of slices needed
Initate a variable for the number of pizzas needed
DISPLAY"Enter the number of people attending: "
input number of people
DISPLAY"Enter the diameter of the pizza: "
input diameter of pizza
Calculate the radius of pizza
Calculate area of pizza (area=PI*r2)
Calculate number of slices (slices=area of pizza/14.125)
Calculate number of slices needed (slices needed=number of people * 3)
Calculate the number of pizzas needed (slices needed/slices)
Display number of slices per  pizza
Display number of pizzas needed
*/

#include<iostream>			//for cout and cin
#include<cmath>				//for math functions
#include<iomanip>			//for formatting
using namespace std;

int main()
{
	const double PI = 3.14159,
		area_slice = 14.125;		//constant for area size of a slice
	double number_people,			//number of people in attendance
		diameter_pizza,				//diameter of the pizza
		radius_pizza,				//for radius of the pizza
		area_pizza,					//area of the pizza
		total_slices,				//Total numer of slices of the pizza
		total_people_fed,			//Total people the pizza will feed
		slices_needed,				//how many slices are needed for the number of people
		pizzas_needed;				//how many pizza are needed in total

	//get user input for the numeber of people and diameter of the pizza
	cout << "Enter the number of people attending: ";
	cin >> number_people;
	cout << "Enter the diameter of the pizza: ";
	cin >> diameter_pizza;

	//calculae the radius of the pizza
	radius_pizza = diameter_pizza / 2;
	//calculate area of the pizza
	area_pizza = PI * pow(radius_pizza, 2);
	//calculate number of slices
	total_slices = area_pizza / area_slice;
	//calculate number of slices needed
	total_people_fed = number_people * 3;
	//calculate number of pizzas needed
	pizzas_needed = total_people_fed / total_slices;

	//Display number of slices per pizza and number of pizzas needed
	cout << setprecision(1) << fixed << showpoint;
	cout << "Number of slices per pizza is " << total_slices << " slices."<< endl;
	cout << "Total number of pizzas needed is " << ceil(pizzas_needed) << "." << endl; //ceil to make pizzas_needed a whole number
	return 0;

}
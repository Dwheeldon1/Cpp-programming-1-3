/******************************************
Program Division sales
This program allows user to input data from 4 divisions
for 4 quarters, then displays and totals data. does not
allow for less than 0 data entries. 
Author: Doug Wheeldon
Created : 2/2/2022
Revisions : <date> <what changes were made>
******************************************/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Division
{
	string name;
	double quarter1, quarter2, quarter3, quarter4;
};

void GetDivisionSales(Division& div);
void DisplayDivision(Division div);

int main()
{
	Division east, west, north, south;

	east.name = "East";
	west.name = "West";
	north.name = "North";
	south.name = "South";

	GetDivisionSales(east);
	GetDivisionSales(west);
	GetDivisionSales(north);
	GetDivisionSales(south);

	DisplayDivision(east);
	DisplayDivision(west);
	DisplayDivision(north);
	DisplayDivision(south);

	return 0;
}

void GetDivisionSales(Division& div)
{
	cout << "Please enter the sales for " << div.name << " Division:" << endl;		//first quarter sales data
	cout << "First Quarter: ";
	cin >> div.quarter1;				//saved to quarter 1
	while (div.quarter1 < 0)					//while loop for less than 0 error
	{
		cout << "Cannot have a quarter sales report of less than 0." << endl;
		cout << "Enter First Quarter Sales: ";
		cin >> div.quarter1;
	}
	cout << "Second quarter: ";		//second quarter data
	cin >> div.quarter2;			//saved to quarter 2
	while (div.quarter2 < 0)		//while loop for less than 0 error
	{
		cout << "Cannot have a quarter sales report of less than 0." << endl;
		cout << "Enter Second Quarter Sales: ";
		cin >> div.quarter2;
	}
	cout << "Third quarter: ";		//third quarter
	cin >> div.quarter3;			//saved to quarter 3
	while (div.quarter3 < 0)		//while loop for less than 0 error
	{
		cout << "Cannot have a quarter sales report of less than 0." << endl;
		cout << "Enter Third Quarter Sales: ";
		cin >> div.quarter3;
	}
	cout << "Fourth Quarter: ";		//fourth quarter 
	cin >> div.quarter4;			//saved to quarter 4
	while (div.quarter4 < 0)		//while loop for less than 0 error
	{
		cout << "Cannot have a quarter sales report of less than 0." << endl;
		cout << "Enter Fourth Quarter Sales: ";
		cin >> div.quarter4;
	}
}

void DisplayDivision(Division div)
{
	cout << "Sales amount for " << div.name << "Division" << endl;
	cout << setw(20) << div.quarter1 << endl;
	cout << setw(20) << div.quarter2 << endl;
	cout << setw(20) << div.quarter3 << endl;
	cout << setw(20) << div.quarter4 << endl;
	cout << "Total Sales " << div.quarter1 + div.quarter2
		+ div.quarter3 + div.quarter4 << endl;
}
/*
		Hotel Occupancy
	Write a program that calculates the occupancy rate for a hotel. The program should
	start by asking the user how many floors the hotel has. A  loop should then iterate once
	for each floor. In each iteration, the loop should ask the user for the number of rooms on the floor
	and how many are occupied. After all the iterations, the program should display how many rooms the hotel has, 
	how many are occupied, how many are unoccupied, and the percentage of rooms taht are occupied. The percentage may
	be claculated by dividing hte number of rooms by the occupied number of rooms.
	Do not accet a value less than 1 for number of floors. Do not accept a number less than 10 for number of rooms on a floor.
	Traditional that most hotels do not have a 13th floor. the loop should skip the entire thirtheenth iteration.
*/
/*
		pseudocode
	initiate a variable for the user defined number of floors
	initiate a variable for the user defined number of rooms
	initiate a variable for the occupied rooms
	display enter number of floors
	input number of floors
	validate the number of floors is not less than 1
	do loop to get the number or rooms and number of occupied rooms for each floor
		display enter number of rooms on floor
		if loop to validate number of rooms is not less than 10
		display enter number of occupied rooms on floor
		if loop to validate number of occupied rooms is not less than 1 and not greater than the number of rooms on the floor
		if loop to skip the 13th floor
	display how many rooms the hotel has
	display how many rooms are occupied
	display how many rooms are unoccupied
	display percentage of occupied rooms
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double number_floors, number_rooms, occ_rooms, count = 1, num = 0, rooms = 0, occ = 0;		//variables to hold data

	//get user input for number of floors
	cout << "Enter the Number of floors: ";
	cin >> number_floors;
	num += number_floors;

	//validate number of floors is not less than 1
	while (number_floors < 1)
	{
		cout << "Number if floors can not be less than 1." << endl;
		cout << "Enter the number of floors:";
		cin >> number_floors;
		num += number_floors;
	}
	//do loop to get the number of rooms and number of occupied rooms for each floor

	for (count; count <= number_floors; count++)
	{
		cout << "Enter the number of rooms for floor " << count << ":";
		cin >> number_rooms;
		rooms += number_rooms;
		// validate floor number is not 13
		if (count == 12)
		{
			count++;
		}
		//validat the number of rooms is greater than 10
		if (number_rooms < 10)
		{
			cout << "The number of rooms must be greater than 10." << endl;
			cout << "Enter the number of rooms for the " << count << " floor:";
			cin >> number_rooms;
			rooms += number_rooms;
		}
		cout << "Enter the number of occupied rooms: ";
		cin >> occ_rooms;
		occ += occ_rooms;
		//validate that the number of occupied rooms is not less than 1, and not greater than the numer of rooms on the floor
		if (occ_rooms < 1 || occ_rooms > number_rooms)
		{
			cout << "The occupied number of rooms is invalid." << endl;
			cout << "Enter the number of occupied rooms: ";
			cin >> occ_rooms;
			occ += number_rooms;
		}
	}
	//display data	
	
	cout << "The hotel has " << rooms << " rooms." << endl;
	cout << "The hotel has " << occ << " occupied rooms." << endl;
	cout << "The hotel has " << rooms - occ << " un-occupied rooms." << endl;
	cout << "The hotel is " << (occ / rooms) * 100 << "% full." << endl;
}
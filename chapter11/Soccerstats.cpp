/******************************************
Program Soccer Statistics
This program allows user to input data a 12 person
kids soccer team. A structure will be used to keep
track of the player name, jersey number, and points scored.
Author: Doug Wheeldon
Created : 2/5/2022
Revisions : <date> <what changes were made>
******************************************/
/*****************************************
		Pseudocode
structure player
	string name, double jersey number, double points scored
const int number players
array for players
function prototypes for GetPlayerInfo, ShowPlayerInfo, GetTotalPoints, ShowHighest
main ()
	call getplayerinfor
	call showplayerinfor
	call gettotalpoints
	callshowhighest
getplayer info ()
	get player infor for each element of the array
	using the structure
showplayer info () 
	step through the const array to display the player information
	and display it
gettotalpoints ()
	step throught the const array to get the total points for the team
	and return int to main
showhighest
	step through the array and locate the player with the most points scored
	show the player with the highest points
******************************************/
#include <iostream>
#include <string>

using namespace std;

struct Player		//structure for player information
{
	string name;		//player name
	double number;		//player jersey number
	double points;		//player points scored
};

const int num_players = 12; //global constant for number of players on team


//function prototypes
void GetPlayerInfo(Player& p);		
void ShowPlayerInfo(Player  p);
int GetTotalPoints(Player p[], int size);
void ShowHighest(Player p[], int size);

int main()
{
	Player player[num_players];		//array for the Player structure

	Player p;  //define a structure variable.
	for (int c = 0; c < num_players; c++)		//cycles through the array
	{
		GetPlayerInfo(player[c]);		//allows the player array to store player data
	}
	for (int a = 0; a < num_players; a++)		//cycles throug the array
	{
		ShowPlayerInfo(player[a]);	//allows each element of the array to be displayed
	}
	int total = GetTotalPoints(player, num_players);	//display total points
	ShowHighest(player, num_players);
	cout << "Total team points scored is: " << total << "." << endl;

	return 0;	//EOP
}

/*****************************************************
GetPlayerInfo accepts Player structure as an argument
Uses a reference variable to store information for the 
players. 
*******************************************************/
void GetPlayerInfo(Player& p)
{
		cout << "Enter the Player name: ";
		getline(cin, p.name);			//to allow for full name entry
		cout << "Enter " << p.name << " Jersey Numer: ";
		cin.ignore();		//ignore the remaining /n character
		cin >> p.number;
		while (p.number < 0)			//verifying jersey number is not less than 0
		{
			cout << "Cannot have a number less than 0." << endl;
			cout << "Enter " << p.name << " Jersey Number: ";
			cin >> p.number;
		}
		cout << "Enter " << p.name << " Points Scored: ";
		cin >> p.points;
		while (p.points < 0)		//verifying points is not negative
		{
			cout << "Cannot have a negative number." << endl;
			cout << "Enter " << p.name << " Points Scored:";
			cin >> p.points;
		}
		cin.ignore();
}

/********************************************************
Display Player info function. Displays the information that 
for each player that was inputted.
*********************************************************/
void ShowPlayerInfo(Player p)
{
		cout << "Player: " << p.name << endl;
		cout << "Number: " << p.number << endl;
		cout << "Points Scored: " << p.points << endl;
}

/********************************************************
Get Total Points Function. Totals the points from all team members
and returns and integer
********************************************************/
int GetTotalPoints(Player p[], int size)
{
	int total = 0;			//accumulator
	for (int count = 0; count < size; count++)
	{
		total += p[count].points;		//totals the array based on count from the points structure element
	}
	return total;
}

/**********************************************************
show highest function. Determines the highest scoring player.
displays the name of the highest scoring patient.
**********************************************************/
void ShowHighest(Player p[], int size)
{
	int highest = p[0].points;		//sets the highest variable to the first element in the array
	int index = 0;
	for (int count = 1; count < size; count++)		//for loop starting at 1 to work through the array elements
	{
		if (p[count].points > highest)	//determines who is the highest scoring
		{
			highest = p[count].points;	//changing the highest scoring player
			index = count;
		}
	}
	cout << "The most points was scored by " << p[index].name << "." << endl;		//displays name 
}
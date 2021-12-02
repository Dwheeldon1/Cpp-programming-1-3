/*
Doug Wheeldon
CISS 241
Programming I
*/
/*
This assignment will have you creating a program to play an old game, the guessing game. The program will need to generate a random number between 1 and 100 and 
asks the user to guess what the number is. The program will determine if the user’s guess is higher than the random number, notifying them with “Too high, try again.” 
If the user’s guess is lower than the random number, the program should display “Too low, try again.”

The user will have only 10 guesses to get the random number, it will use a loop that repeats until the user correctly guesses the random number or has made 10 guesses. 
The program needs to keep track of the number of guesses the user makes.

When the game ends, it will display one of the messages in the table below based on the number of guesses the user took.

The user’s guesses must be validated by making sure the value entered is between 1 and 100. If the value is not between 1 and 100, 
the user should be told to make another guess. The invalid input should not count as one of the 10 guesses the user is allowed. 
Pseudocode must be provided in the comment block at the top of the file.
*/
/*
		pseudocode
	initiate a variable for players guess
	initiate a variable for random number
	initiate a constant variable for min_number set to 1
	initiate a constant variable for max_number set to 100
	inititate a count variable for the number of guesses the player has taken
	get system time
	get user number
	validate user number is between 1 and 100
	for loop to allow for 10 guesses
	display "Either you know the secret or you got lucky!" for less than 5 guesses
	display "You're pretty good at this!" for 5 to 7 guesses
	display "You'll do better next time." for 8 to 10 guesses
	display "Sorry - You have taken too many guesses." for the 10th guess
*/
#include <iostream>	//for cout and cin
#include <cstdlib>	//for rand and srand
#include <ctime>	//for time functiion

using namespace std;

int main()
{
	int guess, ran_numb, count = 1;	//create variables and set count to 1
	const int min_number = 1, max_number = 100;	//min max value

	//get system time
	unsigned seed = time(0);

	//seed random number generator
	srand(seed);

	//generate random number
	ran_numb = (rand() % (max_number - min_number + 1)) + min_number;

	//to see the generated number for testing...comment out after testing
	//cout << "The Generated number is " << ran_numb << endl;


	for (count; count <= 10; count++)
	{
		cout << "Enter a number between 1 and 100: ";
		cin >> guess;
		cout << "Guesses Remaining: " << 10 - count << endl;
		
		//validate entry
		if (guess < 1 || guess > 100)
		{
			cout << "Entry is out of the range." << endl;
			cout << "Enter a number between 1 and 100: ";
			cin >> guess;
			cout << "Guesses Remaining: " << 10 - count << endl;
		}
	
		//if guess is lower than the generated number
		if (guess < ran_numb)
		{
			cout << " Your guess is to low. Try again.";
		}
		else if (guess > ran_numb)
		{
			cout << "Your guess is to high. Try again.";
		}

		//display based on attempts to guess or guesses equal 10
		if (ran_numb == guess || count == 10) 
		{
			if (count < 5)
			{
				cout << "Either you know the secret or you got lucky" << endl;
				break;
			}
			else if (count >= 5 && count <= 7)
			{
				cout << "You're pretty good at this!" << endl;
				break;
			}
			else if (count >= 8 && count < 10)
			{
				cout << "You'll do better next time. " << endl;
				break;
			}
			else
			{
				cout << "Sorry - You have taken too many guesses. " << endl;
				break;
			}
		
		}
		
	}
	return 0;
}
/*
		Coin toss
	Write a funciton named coinToss that simulates the tossing of a coin.
	When you call the function, it should generate a random number in the range of 1 through 2
	if the random number is 1, the function should display "heads" if the random number is 2,
	it should display tails. Demonstrate the function in a program that asks the user how many times the coin
	should be tossed, then simulates the tossing of the coin that number of times.
*/
/*
	pseudocode
	main()
		intiate a variable for the number of tosses
		get the number of tosses
		input tosses
		for statement to run the generator the number of user defined tosses
			if statements to determine heads or tails
			display toss results
	coinToss()
		initiate variables for min and max number
		initate variables for heads and tails
		get system time and seed the random generator
		generate the random number
		return the number to main
*/
#include <iostream> //for cin and cout
#include <cstdlib> //rand and srand
#include <ctime>   //to get system time

using namespace std;

//function prototype
string coinToss();

int main()
{
	int NUMB_TOSS;

	cout << "Enter the number of times to toss a coin: ";
	cin >> NUMB_TOSS;

	for (int count = 1; count <= NUMB_TOSS; count++)
	{
		string result = coinToss();
		cout << "The Result of toss " << count << " is:" << result<< endl;
	}

	return 0;

}
/************************************************************
*			coinToss()                                      * 
	function to generate the coin toss using random number  *
	bewteen 1 and 2 identifying 1 as heads and 2 as tails   *
	sending it back to the main function                    *
*************************************************************/

string coinToss()
{
	int MIN = 1, MAX = 2, ran_numb;	//local variables for the two values
	string Heads_Tails;

	//get system time
	unsigned seed = time(0);

	//seed random number generator
	srand(seed);

	//generate random number
	ran_numb = (rand() % (MAX - MIN + 1)) + MIN;

	//get heads or tails identifer
	if (ran_numb == 1)
	{
		Heads_Tails = "Heads";
	}
	else
	{
		Heads_Tails = "Tails";
	}
	return Heads_Tails;
}

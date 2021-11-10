/*
		Male and Female Percentages
	Write a program that asks the user for the number of males and the number of females
	registered in a class. The program should display the percentage fo males and females 
	in the class.
*/
/*
		pseudocode
	initate a variable for number of male
	intitate a variable for number of females
	initate a variable for total students
	initate a variable for the percentage of males
	initate a variable for the percentage of females
	calculate the number of students
	calculate the percentage of male students
	calculate the percentage of female students
	Display the percentage of male students
	displat the percentage of female students
*/

#include <iostream> //for cout and cin
#include <iomanip>  //to format numbers showpoint, fixed, setprecision

using namespace std;

int main()
{
	double number_males, //variables
		number_females,
		total_students,
		percent_males,
		percent_female;

	//get number of male and female students
	cout << "Enter the number of male students: ";
	cin >> number_males;
	cout << "Enter the number of female students: ";
	cin >> number_females;

	//calculate the total number of students
	total_students = number_females + number_males;

	//calculate the percentages
	percent_males = number_males / total_students;
	percent_female = number_females / total_students;

	//display the result
	cout << "The total number of students is " << total_students << " of which " << percent_males << "%." << endl;
	cout << "The total number of students is " << total_students << " of which " << percent_female << "%." << endl;
	return 0;

}
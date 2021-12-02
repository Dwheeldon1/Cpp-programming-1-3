/*
*			Areas of Rectangles
* The area of a rectangle is the rectangle's length x its width. Write a program that asks for the length and width of two rectangles.
* The program should tell the user which rectangle has the greater area, or if the areas are the same.
*/
/*
*	Pseudocode
* initate a variable for rectangle 1 length
* initiate a variable for rectangel 1 width
* initiate a variable for rectanle 1 area
* initiate a variable for rectangle 2 length
* initiate a variable for rectangle 2 width
* initate a variable for rectangle 2 area
* get the length and width for rectangle 1
* get the length and width for rectangle 2
* calculate the area of rectangle 1
* calculate the area of rectangle 2
* if statment to compare the area of rectangle 1 and rectangle 2
*	display rectangle 1 has the greater area
* else if statment
*	display rectangle 2 has the greater area
* else 
*	display the area is the same
* EOP
*  
*/
#include <iostream>

using namespace std;

int main()
{
	double rect1_len,
		rect1_wid,
		rect1_area,
		rect2_len,
		rect2_wid,
		rect2_area,
		rec1_sum,
		rec2_sum;

	//get rectangle dimensions
	cout << "Enter the width of rectangle 1: ";
	cin >> rect1_wid;
	cout << "Enter the length of rectangle 1: ";
	cin >> rect1_len;
	cout << "Enter the width of rectangle 2: ";
	cin >> rect2_wid;
	cout << "Enter the length of rectangle 2: ";
	cin >> rect2_len;

	//calculate the area of the rectangles
	rect1_area = rect1_wid * rect1_len;
	rect2_area = rect2_wid * rect2_len;

	// determine which is larger with an if statement
	if (rect1_area > rect2_area)
		{
			cout << "Rectangle 1 is larger than rectangle 2.";
		}
	else if (rect1_area < rect2_area)
		{
			cout << "Rectangle 2 is larger than rectangle 1.";
		}
	else if (rect1_area == rect2_area)
		{
			cout << "The area of Rectangle 1 is equal to the area of Rectangle 2.";
		}
}
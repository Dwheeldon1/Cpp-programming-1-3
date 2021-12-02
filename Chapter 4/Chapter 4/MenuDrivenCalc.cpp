/*
Doug Wheeldon
CISS 241
Programming I
*/
/*
Menu-driven programs will display the menu options to the user and then prompt them for a menu choice. This program will display the following menu in the following format:

Calculator Options:

Calculate the area of a circle
Calculate the area of a rectangle
Calculate the area of a triangle
Calculate the area of a trapezoid
Calculate the area of a sphere
Exit
Enter your choice (1-6)
Once the user enters a choice for the menu, the program should use a switch statement to determine the user choice and calculate the area of the shape selected.

If the shape selected is a circle, the program must prompt the user for the radius of the circle. The area will be calculated and then displays the area indicating it is a circle.

For a menu choice for the rectangle, the program must prompt the user for the length and width of the rectangle. 
The program will then calculate the area of the rectangle and display the area indicating it is the area of a rectangle.

If the menu choice is a triangle, the program must prompt the user for the length of the triangle’s base and its height. The area is then calculated for the triangle and displays the area.

If the choice is a trapezoid, the program must prompt the user for the height and the two base lengths. The area is calculated and displayed indicating it is a trapezoid.

If a sphere is selected, the program must prompt the user for the radius. Calculate the area and then display the area of the sphere indicating it is a sphere.

Other requirements and formulas:

Make PI a named constant
Circle area = PI * r2
Rectangle area = length * width
Triangle area = base * height * 0.5
Trapezoid area = height/2 * (b1 +b2)
Sphere area = 4 * PI *r2
The program should validate the user menu choice. If an invalid menu option, it should display a message telling the user what the valid choices are and exit the program.

The program should also not allow the user to enter a negative number for any of the values used to calculate the areas.
If they do the program must indicate which value entered was invalid, being specific. For example, for a rectangle, 
if the length is invalid there should be a message like “Value entered for the length is invalid”
*/
/*
		pseudocode
	initiate a const variable for menu_circle set to 1
	initatie a const variable for menu_rect set to 2
	initate a const variable for menu_tri set to 3
	initate a const variable for menu_trap set to 4
	initiate a const variable for menu_sphe set to 5
	initate a const variable for menu_exit set to 6
	initate a const variable for PI set to 3.1415926
	initate a variable for circ_area
	initiate a varaible for rect_area
	initiate a variable for trap_area
	initiate a variable for sphe_area
	initiate a variable for tri_area
	initate a variable for menu_select
	Display centered "shape area calculator"
	Display Menu items
	Display "make a selection (1 - 6)
	validate selection is in range 1 - 6 with if statement
		switch (menu_select) statement
			case 1 circle area
				initate a variable for radius
				validate number is non-negative
					display" invalid number"
				calculate circle area = PI * pow(r, 2)
			case 2 area of rectangle
				initiate a variable for lenght
				initiate a varibale for width
				validate length is non negative
					display length cannot be negative
					EOP
				validate width is non negative
					display width cannot be negative
					EOP
				calculate area of rectangle length * width
			case 3 area of triangle
				initate a variable for base
				initate a variable for height
				validate base is non negative
					display base cannot be negative
					EOP
				validate height is non negative
					display height cannot be negative
					EOP
				calculate area of triangle base * height * 0.5
			case 4 area of trapezoid
				initiate a variable for height
				initiate a variable for base1
				initiate a variable for base2
				validate height is non negative
					display height cannot be non negative
					EOP
				validate base1 is non negative
					display base 1 cannot be non negative
					EOP
				validate base 2 is non negative
					display base 2 cannot be non negative
					EOP
				calculate area of trapezoid height/2 * (b1 +b2)
			case 5 area of sphere
				initate a variable for radius
				validate radius is non negative
					display radius cannot be non negative
					EOP
				calculate area of sphere 4 * PI *r2
				display area of sphere
			case 6 exit
				Display thank you
				EOP
	else statement for wrong selection out of range
		display selection out of range must be between 1 - 6
		EOP
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int const menu_circ = 1,	//menu item 1 area of circle
		menu_rect = 2,			//menu item 2 area of rectangle
		menu_tri = 3,			//menu item 3 area of triangle
		menu_trap = 4,			//menu item 4 area of trapezoid
		menu_sphe = 5,			//menu item 5 area of sphere
		menu_exit = 6;			//menu item 7 exit
	double const PI = 3.1415926;			//PI
	double circ_area,			//to hold area of circle
		tri_area,				//to hold area of triangle
		trap_area,				//to hold area of trapezoid
		sphe_area,				//to hold area of sphere
		rect_area;				//to hold area of rectangle
	int menu_select;			//to hold menu choice

	//shape calculator menu
	cout << "\t\t\tShape Calculator Menu\n\n";
	cout << "\t1. Area of a Circle\n";
	cout << "\t2. Area of a Rectangle\n";
	cout << "\t3. Area of a Triangle\n";
	cout << "\t4. Area of a Trapezoid\n";
	cout << "\t5. Area of a Sphere\n";
	cout << "\t6. Exit\n\n";
	cout << "\tMake a Selection (1 - 6): ";
	cin >> menu_select;
	if (menu_select < 1 || menu_select > 6)		//validates the user selection		
	{
		cout << "Selection is Invalid. Must Select a number between 1 and 6.";
		return 0;	//terminates the program
	}
	else
	{
		switch (menu_select)
		{
		case 1: cout << "\t Area of a Circle\n"; // area of a circle
			double radius;						 //local variable for radius
			cout << " \tEnter the radius of the Circle: "; //get the radius
			cin >> radius;
			if (radius < 0)
			{
				cout << "The Radius must be a non-negative value.";
				return 0;
			}
			else
			{
				circ_area = PI * pow(radius, 2);	//calculaate the area of the circle
			}
			cout << "\tThe Area of the Circle is: " << circ_area << "\n";	//display the area of a the circle
			break;
		case 2: cout << "\tArea of a Rectangle\n";	//area of Rectangle
			double length,	//local variable for length and width
				width;
			cout << "\tEnter the Length of the Rectangle: ";	//get values for length and width
			cin >> length;
			cout << "\tEnter the Width of the Rectangle: ";
			cin >> width;
			if (length < 0)
			{
				cout << "\tThe Length must be a non-negative value.";
				return 0;
			}
			else if (width < 0)
			{
				cout << "\tThe Lenght must be a non-negative value.";
				return 0;
			}
			else
			{
				rect_area = length * width;		//calculate the area of the rectangle 
			}
			cout << "\tThe area of the Rectangle is: " << rect_area;
			break;
		case 3: cout << "\tArea of a Triangle\n"; 
			double base_tri,	//initiate variables for base and height
				height_tri;
			//get input for base and height
			cout << "\tEnter a Value for the base: ";
			cin >> base_tri;
			cout << "\tEnter a Value for the height: ";
			cin >> height_tri;
			if (base_tri < 0)	//validate  input for non negative numbers
			{
				cout << "\tThe Base must be a non-negative value.";
				return 0;
			}
			else if (height_tri < 0)
			{
				cout << "\t The Height must be a non-negative value.";
				return 0;
			}
			else
			{
				tri_area = base_tri * height_tri * 0.5;		//calculate the area of the rectangle
			}
			cout << "\tThe area of the Triange is: " << tri_area;
			break;
		case 4: cout << "\tArea of a Trapezoid\n";
			double height_trap,	//initiate variables for height, base1 and base2
				base1_trap,
				base2_trap;
			//get input for height, base1, base2
			cout << "\tEnter the Trapezoids height: ";
			cin >> height_trap;
			cout << "\tEnter the Trapezoids 1st base: ";
			cin >> base1_trap;
			cout << "\tEnter the Trapezoids 2nd base: ";
			cin >> base2_trap;
			if (height_trap < 0) //validate user input is a non-negative number
			{
				cout << "\tThe Height must be a non-negative value.";
				return 0;
			}
			else if (base1_trap < 0)
			{
				cout << "\tThe 1st Base Value must be a non-negative value.";
				return 0;
			}
			else if (base2_trap < 0)
			{
				cout << "\tThe 2nd Base Value must be a non-negative value.";
				return 0;
			}
			default
			{
				trap_area = height_trap / 2 * (base1_trap + base2_trap); //calculate area of trapezoid
			}
			cout << "\tThe area of the Trapezoid is: " << trap_area;
			break;
		case 5: cout << "\tArea of a Sphere\n";
			double radius_sphe;	//variable for radius of sphere
			cout << "\tEnter the Radius of the sphere: ";
			cin >> radius_sphe;
			if (radius_sphe < 0) //validate user entry is non-negative
			{
				cout << "\tThe Radius Must be a non-negative value.";
				return 0;
			}
			else
			{
				sphe_area = 4 * PI * pow(radius_sphe, 2.0); //calculate area of sphere
			}
			cout << "\tThe area of the sphere is: " << sphe_area;
			break;
		case 6: cout << "\tThank You. Goodbye.";
			return 0;
		}
	}
}
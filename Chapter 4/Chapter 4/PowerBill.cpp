/*
doug wheeldon
ciss 241
programming I
*/
/*
The commission has ruled that the company you work for, Municipal Power and Light, overcharged customers for two months during the previous year. To compensate the customers, 
the commission has ordered the company to decrease each customer's bill next month by 12%.

The state levies a 3.5% utility tax and the city levies a 1.5% utility tax, both of which must be applied to the customer's bill before it is discounted. 
(The state and city want their taxes on the full, undiscounted amount, and the 12% discount does not apply to the utility taxes). Municipal Power and Light charges are as follows:

kWh used										Cost Scale

less than 1000									$0.052 per kWh used

at least 1000 but less than 1300				$0.052 per kWh for first 1000 kWh used
												$0.041 per kWh over 1000 kWh used

at least 1300 but less than 2000				$0.052 per kWh for first 1000 kWh used
												$0.041 per kWh for the next 300 kWh used
												$0.035 per kWh over 1300 kWh used

at least 2000									$0.052 per kWh for first 1000 kWh used
												$0.041 per kWh for the next 300 kWh used
												$0.035 per kWh for the next 700 kWh used
												$0.03 per kWh over 2000 kWh used

Inputs for your program should include the customer name and number of kWh used during the current month. Remember that the state and city taxes are computed on the first amount in the above list.

Output should include in a formatted message:

customer name
base, undiscounted, untaxed bill amount
discount amount
state utility tax amount
city utility tax amount
total amount due
*/
/*
		pseudocode
initiate a const variable for state util tax set to 3.5%
initate a const variable for city util tax set to 1.4%
initate a variable for customer name
initiate a variable for KWH used
initate avariable for base amount 
initiate a varriable for the discount amount of bill (12%)
initate a variable for state tax amount of bill
initiate a variable for city tax amount of bill
initiate a variable for total amount due
display enter customer name
input customer name
display enter KWH used
input KWH used
Validate kwh entry
if statement to determine kwh less than 1000
	calculate under 1000 rate at .052
else if statement to determin kwh greater than or equal to 1000 but less than 1300
	calculate kwh2 = kwh - 1000
	calculate kwh2 total = kwh2*.041
	calculate total amount due = (1000*.052)+kwh2 total
else if statement to determine if kwh greater than or equal to 1300 but less than 2000	
	calculate kwh1 = 1000 * 0.052
	calculate kwh2 = 300 * 0.041 
	calculate kwh4 = (kwh used - 1300) * .035
	calculate base bill
else if statement to determine if kwh is at least 2000
	calculae kwh1 = 1000 * .052
	calculate kwh2 = 300 * .041
	calculate kwh3 = 700 * .035
	calculate kwh4 = (2000 - kwh used) * .03
	calculate base bill
calculate state tax amount
calculate city tax amount
calculate discount total
display customer name
display base untaxed undiscounted amount
display discount amount
display state util tax amount
display city util tax amount
display total bill
*/
#include <iostream>	//for cout cin
#include <iomanip>	//for formatting
#include <string>	//for getline

using namespace std;

int main()
{
	const double state_util_tax = .035,	//state tax rate 3.5%
		city_util_tax = 0.015,			//city tax rate 1.4%
		discount_amount = .12;			//discount amount 12%
	string customer_name;
	double kwh_used,					//KWH used
		base_bill,						//untaxed base bill amount
		state_tax_amount,				//amount of state tax
		city_tax_amount,				//amount of city tax
		discount_total,					//total discount
		total_amount_due;				//total bill
	//get customer name and kwh used from user
	cout << "Enter Customer Name: ";
	getline(cin, customer_name);
	cout << "Enter KWH used: ";
	cin >> kwh_used;
	//Validate user entry is non negative
	if (kwh_used < 0)
	{
		cout << "Invalid Entry. KWH can not be a negative amount.";
			return 0;
	}
	//determine if kwh is less than 1000 and calculate cost
	if (kwh_used < 1000)
	{
		base_bill = kwh_used * .052;
	}
	//determine if kwh is at least 1000 but less than 1300
	else if (kwh_used >= 1000 && kwh_used < 1300)
	{
		double kwh1 = kwh_used - 1000;
		double kwh1_total = kwh1 * .041;
		base_bill = (1000 * 0.052) + kwh1_total;
	}
	//determine if kwh is greater than 1300 but less than 2000
	else if (kwh_used >= 1300 && kwh_used < 2000)
	{
		double kwh1 = 1000 * 0.052;
		double kwh2 = 300 * 0.041;
		double kwh3 = (kwh_used - 1300) * .035;
		base_bill = kwh1 + kwh2 + kwh3;
	}
	//determine if kwh is at least 2000
	else if (kwh_used >= 2000)
	{
		double kwh1 = 1000 * 0.052;
		double kwh2 = 300 * 0.041;
		double kwh3 = 700 * 0.035;
		double kwh4 = (kwh_used - 2000) * .03;
		base_bill = kwh1 + kwh2 + kwh3 + kwh4;
	}
	//calculate state tax, city tax, and discount amounts
	state_tax_amount = base_bill * state_util_tax;
	city_tax_amount = base_bill * city_util_tax;
	discount_total = base_bill * discount_amount;
	//calculate total bill
	total_amount_due = (base_bill - discount_total) + city_tax_amount + state_tax_amount;
	//display Customer Name, base bill amount, state tax, city tax, discount total, total amount due
	cout << "Customer Name: " << setw(31) << customer_name << endl;
	cout << setprecision(2) << fixed << showpoint;
	cout << "Base Bill Amount: " << setw(25) << "$" << base_bill << endl;
	cout << "Discount Amount: " << setw(25) << "$" << discount_total << endl;
	cout << "State Tax Amount: " << setw(24) << "$" << state_tax_amount << endl;
	cout << "City Tax Amount: " << setw(25) << "$" << city_tax_amount << endl;
	cout << "Total Amount due: " << setw(24) << "$" << total_amount_due << endl;
	return 0;
}
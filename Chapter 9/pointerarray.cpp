#include <iostream>
using namespace std;

int* ExpandArray(int data[], int size)
{
	int* newarray = nullptr;
	newarray = new int[(size * 2)];

	//fill first half of newarray with contents of passed array
	for (int count = 0; count < (size); count++)
	{
		newarray[count] = data[count];
	}
	//fill rest of array with 0
	for (int count = size; count < (size * 2); count++)
	{
		newarray[count] = 0;
	}
	
	return newarray;

}

int main()
{
	int size = 2;
	int* values = new int[size];
	values[0] = 55;
	values[1] = 77;

	for (int index = 0; index < size; index++)
	{
		cout << values[index] << endl;
	}

	values = ExpandArray(values, size);

	for (int index = 0; index < size * 2; index++)
	{
		cout << values[index] << endl;
	}

	delete[] values;

	return 0;
}
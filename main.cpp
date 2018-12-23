#include "function.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	while (1)
	{
		size_t size1, size2; int number;

		cout << "Size: ";
		cin >> size1; cin >> size2;
		cout << "First number: ";
		cin >> number;

		int **array = new int*[size1*size2];
		for (int i = 0; i < size1*size2; i++)
			array[i] = new int[size1*size2];


		fill_array(array, size1, size2, number);
		print_array(array, size1, size2);

		cout << endl << endl << endl;

		for (int i = 0; i < size1*size2; i++)
				delete[] array[i];
		delete[] array;
		array = nullptr;
	}

	system("pause");
	return 0;
}
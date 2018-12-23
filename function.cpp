#include "function.h"
#include <iostream>
#include <iomanip>
using namespace std;

void fill_array(int**array, const size_t size1, const size_t size2, int number) //заполнение массива
{
	size_t sizeX = size2, sizeY = size1; // X - по горизонтали, Y - по вертикали
	int Summ = sizeX * sizeY; // количество элементов
	int newX = 0, newY = 0; // сдвиг координаты
	int Count = number; // значение элемента
	int Beg = number; // для сдвига, если number != 0


	while ((sizeY > 0) && (sizeX > 0))
	{
		for (int y = 0; y < 4; y++) // проходим по четырем сторонам матрицы
		{
			for (int x = 0; x < ((sizeX < sizeY) ? sizeY : sizeX); x++)
			{
				if ((y == 0) && (x < sizeX - newX) && (Count <= Summ + (Beg - 1)))
					array[y + newY][x + newX] = Count++;
				if ((y == 1) && (x < sizeY - newY) && (x != 0) && (Count <= Summ + (Beg - 1)))
					array[x + newY][sizeX - 1] = Count++;
				if ((y == 2) && (x < sizeX - newX) && (x != 0) && (Count <= Summ + (Beg - 1)))
					array[sizeY - 1][sizeX - (x + 1)] = Count++;
				if ((y == 3) && (x < sizeY - (newY + 1)) && (x != 0) && (Count <= Summ + (Beg - 1)))
					array[sizeY - (x + 1)][newY] = Count++;

// если это текущая сторона и пока значение элемента не достигло конца, идем по рамке, заполняя значениями

			}
		}
		sizeY--;
		sizeX--;
		newY += 1;
		newX += 1; // двигаемся к центру матрицы, на единицу сужая стороны рамки
	}


}

void print_array(int** array, const size_t size1, const size_t size2) //вывод
{
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
			cout << setw(7) << array[i][j];
		cout << endl;
	}

}

bool equal_array(int** array1, const size_t str1, const size_t column1, int** array2, const size_t str2, const size_t column2) //сравнение массивов 
{
	if ((str1 != str2) || (column1 != column2)) return false;
	for (size_t i = 0; i < str1; i++)
		for (size_t j = 0; j < column1; j++)
			if (array1[i][j] != array2[i][j]) return false;
	return true;
}

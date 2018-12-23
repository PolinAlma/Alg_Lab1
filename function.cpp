#include "function.h"
#include <iostream>
#include <iomanip>
using namespace std;

void fill_array(int**array, const size_t size1, const size_t size2, int number) //апрол
{
	size_t sizeX = size2, sizeY = size1; // X - ïî ãîðèçîíòàëè, Y - ïî âåðòèêàëè
	int Summ = sizeX * sizeY; // êîëè÷åñòâî ýëåìåíòîâ
	int newX = 0, newY = 0; // ñäâèã êîîðäèíàòû
	int Count = number; // çíà÷åíèå ýëåìåíòà
	int Beg = number; // äëÿ ñäâèãà, åñëè number != 0


	while ((sizeY > 0) && (sizeX > 0))
	{
		for (int y = 0; y < 4; y++) // ïðîõîäèì ïî ÷åòûðåì ñòîðîíàì ìàòðèöû
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

// åñëè ýòî òåêóùàÿ ñòîðîíà è ïîêà çíà÷åíèå ýëåìåíòà íå äîñòèãëî êîíöà, èäåì ïî ðàìêå, çàïîëíÿÿ çíà÷åíèÿìè

			}
		}
		sizeY--;
		sizeX--;
		newY += 1;
		newX += 1; // äâèãàåìñÿ ê öåíòðó ìàòðèöû, íà åäèíèöó ñóæàÿ ñòîðîíû ðàìêè
	}


}

void print_array(int** array, const size_t size1, const size_t size2) //âûâîä
{
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
			cout << setw(7) << array[i][j];
		cout << endl;
	}

}

bool equal_array(int** array1, const size_t str1, const size_t column1, int** array2, const size_t str2, const size_t column2) //ñðàâíåíèå ìàññèâîâ 
{
	if ((str1 != str2) || (column1 != column2)) return false;
	for (size_t i = 0; i < str1; i++)
		for (size_t j = 0; j < column1; j++)
			if (array1[i][j] != array2[i][j]) return false;
	return true;
}

#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Alg_Lab1/function.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests_lab1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(arr_eq)
		{
			int **array1 = new int*[5];
			int **array2 = new int*[5];

			for (int i = 0; i < 5; i++)
			{
				array1[i] = new int[5];
				array2[i] = new int[5];
			}

			int number = 0;

			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
				{
					array1[i][j] = number;
					array2[i][j] = number;
					number++;
				}

			Assert::IsTrue(equal_array(array1, 5, 5, array2, 5, 5));

			for (size_t i = 0; i < 5; i++)
			{
				delete[] array1[i]; delete[] array2[i];
			}
			delete[] array1; delete[] array2;
			array1 = nullptr; array2 = nullptr;
		}

		TEST_METHOD(arr_dif)
		{
			int **array1 = new int*[5];
			int **array2 = new int*[5];

			for (int i = 0; i < 5; i++)
			{
				array1[i] = new int[5];
				array2[i] = new int[5];
			}

			int number = 0;

			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
				{
					array1[i][j] = number;
					if ((i == 3) && (j == 2))
						array2[i][j] = 0;
					else
						array2[i][j] = number;
					number++;
				}

			Assert::IsFalse(equal_array(array1, 5, 5, array2, 5, 5));

			for (size_t i = 0; i < 5; i++)
			{
				delete[] array1[i]; delete[] array2[i];
			}
			delete[] array1; delete[] array2;
			array1 = nullptr; array2 = nullptr;
		}

		TEST_METHOD(dif_size)
		{
			int **array1 = new int*[5];
			int **array2 = new int*[3];

			for (int i = 0; i < 5; i++)
				array1[i] = new int[5];
			for (int i = 0; i<3; i++)
				array2[i] = new int[3];

			int number = 0;

			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
				{
					array1[i][j] = number;
					number++;
				}

			number = 0;

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
				{
					array2[i][j] = number;
					number++;
				}

			Assert::IsFalse(equal_array(array1, 5, 5, array2, 3, 3));

			for (size_t i = 0; i < 5; i++)
			{
				delete[] array1[i]; if (i<3) delete[] array2[i];
			}
			delete[] array1; delete[] array2;
			array1 = nullptr; array2 = nullptr;
		}

		TEST_METHOD(fill_arr_test_3_4)
		{
			int **array1 = new int*[12];
			int **array2 = new int*[12];

			for (int i = 0; i < 12; i++)
			{
				array1[i] = new int[12];
				array2[i] = new int[12];
			}

			array1[0][0] = 1; array1[0][1] = 2; array1[0][2] = 3; array1[0][3] = 4;
			array1[1][0] = 10; array1[1][1] = 11; array1[1][2] = 12; array1[1][3] = 5;
			array1[2][0] = 9; array1[2][1] = 8; array1[2][2] = 7; array1[2][3] = 6;

			fill_array(array2, 3, 4, 1);

			Assert::IsTrue(equal_array(array1, 3, 4, array2, 3, 4));

			for (size_t i = 0; i < 12; i++)
			{
				delete[] array1[i]; delete[] array2[i];
			}
			delete[] array1; delete[] array2;
			array1 = nullptr; array2 = nullptr;

		}
		TEST_METHOD(fill_arr_test_2_2)
		{
			int **array1 = new int*[2];
			int **array2 = new int*[2];

			for (int i = 0; i < 2; i++)
			{
				array1[i] = new int[2];
				array2[i] = new int[2];
			}

			array1[0][0] = 1; array1[0][1] = 2;
			array1[1][0] = 4; array1[1][1] = 3;

			fill_array(array2, 2, 2, 1);

			Assert::IsTrue(equal_array(array1, 2, 2, array2, 2, 2));

			for (size_t i = 0; i < 2; i++)
			{
				delete[] array1[i]; delete[] array2[i];
			}
			delete[] array1; delete[] array2;
			array1 = nullptr; array2 = nullptr;
		}

		TEST_METHOD(fill_arr_test_1_1)
		{
			int **array2 = new int*[1];
			int **array1 = new int*[1];

			for (int i = 0; i < 1; i++)
			{
				array1[i] = new int[1];
				array2[i] = new int[1];
			}

			array1[0][0] = 1;

			fill_array(array2, 1, 1, 1);

			Assert::IsTrue(equal_array(array1, 1, 1, array2, 1, 1));

			for (size_t i = 0; i < 1; i++)
			{
				delete[] array1[i]; delete[] array2[i];
			}
			delete[] array1; delete[] array2;
			array1 = nullptr; array2 = nullptr;
		}

		TEST_METHOD(fill_arr_test_1_5)
		{
			int **array2 = new int*[5];
			int **array1 = new int*[5];

			for (int i = 0; i < 5; i++)
			{
				array1[i] = new int[5];
				array2[i] = new int[5];
			}

			array1[0][0] = 1; array1[0][1] = 2; array1[0][2] = 3; array1[0][3] = 4; array1[0][4] = 5;

			fill_array(array2, 1, 5, 1);

			Assert::IsTrue(equal_array(array1, 1, 5, array2, 1, 5));

			for (size_t i = 0; i < 5; i++)
			{
				delete[] array1[i]; delete[] array2[i];
			}
			delete[] array1; delete[] array2;
			array1 = nullptr; array2 = nullptr;
		}

		TEST_METHOD(fill_arr_test_5_1)
		{
			int **array2 = new int*[5];
			int **array1 = new int*[5];

			for (int i = 0; i < 5; i++)
			{
				array1[i] = new int[5];
				array2[i] = new int[5];
			}

			array1[0][0] = 1;
			array1[1][0] = 2;
			array1[2][0] = 3;
			array1[3][0] = 4;
			array1[4][0] = 5;

			fill_array(array2, 5, 1, 1);

			Assert::IsTrue(equal_array(array1, 5, 1, array2, 5, 1));

			for (size_t i = 0; i < 5; i++)
			{
				delete[] array1[i]; delete[] array2[i];
			}
			delete[] array1; delete[] array2;
			array1 = nullptr; array2 = nullptr;
		}

	};
}
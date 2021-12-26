#include "pch.h"
#include "CppUnitTest.h"
#include "..\ALGSD_lab_2\ALGSD_lab_2.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ALGSDlab2test
{
	TEST_CLASS(ALGSDlab2test)
	{
	public:
		
		TEST_METHOD(Test_Binary_search)
		{
			int size = 10;
			int *arr = new int[size];
			for (int i = 0; i < size; i++) { // 1,2,3,4,5,6,7,8,9,10
				arr[i] = i + 1; 
			}
			Assert::IsTrue(BinarySearch(arr, 0, 9, 4) == 3);
			Assert::IsTrue(BinarySearch(arr, 0, 9, 1) == 0);
			Assert::IsTrue(BinarySearch(arr, 0, 9, 10) == 9);
			Assert::IsTrue(BinarySearch(arr, 0, 9, 17) == -1);
			delete arr;

		}
		TEST_METHOD(Test_Quick_sort)
		{
			int size = 10;
			int* arr = new int[size];
			for (int i = 0; i < size; i++) { //10-9-8-7-6-5-4-3-2-1
				arr[i] = 10 - i; 
			}
			QuickSort(arr, 0, 9);
			Assert::IsTrue(arr[0] == 1);
			Assert::IsTrue(arr[1] == 2);
			Assert::IsTrue(arr[2] == 3);
			Assert::IsTrue(arr[3] == 4);
			Assert::IsTrue(arr[4] == 5);
			Assert::IsTrue(arr[5] == 6);
			Assert::IsTrue(arr[6] == 7);
			Assert::IsTrue(arr[7] == 8);
			Assert::IsTrue(arr[8] == 9);
			Assert::IsTrue(arr[9] == 10);
			delete arr;
		}
		TEST_METHOD(Test_Bubble_sort)
		{
			int size = 10;
			int* arr = new int[size];
			for (int i = 0; i < size; i++) { //10-9-8-7-6-5-4-3-2-1
				arr[i] = 10 - i;
			}
			BubbleSort(arr, size);
			Assert::IsTrue(arr[0] == 1);
			Assert::IsTrue(arr[1] == 2);
			Assert::IsTrue(arr[2] == 3);
			Assert::IsTrue(arr[3] == 4);
			Assert::IsTrue(arr[4] == 5);
			Assert::IsTrue(arr[5] == 6);
			Assert::IsTrue(arr[6] == 7);
			Assert::IsTrue(arr[7] == 8);
			Assert::IsTrue(arr[8] == 9);
			Assert::IsTrue(arr[9] == 10);
			delete arr;
		}
		TEST_METHOD(Test_Bogo_sort)
		{
			int size = 10;
			int* arr = new int[size];
			for (int i = 0; i < size; i++) { //10-9-8-7-6-5-4-3-2-1
				arr[i] = 10 - i;
			}
			BogoSort(arr,size);
			Assert::IsTrue(arr[0] == 1);
			Assert::IsTrue(arr[1] == 2);
			Assert::IsTrue(arr[2] == 3);
			Assert::IsTrue(arr[3] == 4);
			Assert::IsTrue(arr[4] == 5);
			Assert::IsTrue(arr[5] == 6);
			Assert::IsTrue(arr[6] == 7);
			Assert::IsTrue(arr[7] == 8);
			Assert::IsTrue(arr[8] == 9);
			Assert::IsTrue(arr[9] == 10);
			delete arr;
		}
		TEST_METHOD(Test_Counting_sort)
		{
			int size = 10;
			char* arr = new char[size];
			for (int i = 0; i < size; i++) { arr[i] = 67 - i; }// CBA@?>=<;:
			CountingSort(arr, size);
			Assert::AreEqual(arr[0], ':');
			Assert::AreEqual(arr[1], ';');
			Assert::AreEqual(arr[2], '<');
			Assert::AreEqual(arr[3], '=');
			Assert::AreEqual(arr[4], '>');
			Assert::AreEqual(arr[5], '?');
			Assert::AreEqual(arr[6], '@');
			Assert::AreEqual(arr[7], 'A');
			Assert::AreEqual(arr[8], 'B');
			Assert::AreEqual(arr[9], 'C');
			delete arr;
		}
	};
}

#include <iostream>

// Slow sorting algorithms
// 
// O(N^2)
// Bubble, Selection, Insertion
// They all have the same idea
// -> Iterate over the collection
// -> On each iteration move exactly one more number in it's correct place
// They ony differ in the method they choose to move a number into it's correct place

void bubbleSort(int *arr, int size) {
	for (size_t i = 0; i < size - 1; i++)
	{
		int p1 = 0;
		for (size_t p2 = 1; p2 < size - i; p2++)
		{
			if (arr[p1] > arr[p2])
			{
				std::swap(arr[p1], arr[p2]);
			}

			p1 = p2;
		}
	}
}

void selectionSort(int* arr, int size) {

}

void insertionSort(int* arr, int size) {

}

void printArr(int* arr, int size) {
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	int arr1[] = { 1, 0, -12, 4, 2134, 3, 12, 2, 3, -123 };
	int arr2[] = { 1, 0, -12, 4, 2134, 3, 12, 2, 3, -123 };
	int arr3[] = { 1, 0, -12, 4, 2134, 3, 12, 2, 3, -123 };
	
	printArr(arr1, 10);

	bubbleSort(arr1, 10);
	selectionSort(arr1, 10);
	insertionSort(arr1, 10);

	printArr(arr1, 10);
	printArr(arr2, 10);
	printArr(arr3, 10);
}
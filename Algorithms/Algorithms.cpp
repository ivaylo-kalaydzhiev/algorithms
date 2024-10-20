#include <iostream>

int pairs(int* arr, int size, int target) {
    int count = 0;
    int p1 = 0; int p2 = size - 1;

    while (p1 != p2) {
        if (arr[p1] + arr[p2] == target) {
            count++; p1++;
        }
        else if (arr[p1] + arr[p2] < target) {
            p1++;
        }
        else if (arr[p1] + arr[p2] > target) {
            p2--;
        }
    }

    return count;
}

int countPairsOfSocks(int* arr, int size) {
    int count = 0;
    int buckets[10] = { 0 };

    for (int i = 0; i < size; i++) {
        int curr = arr[i];
        buckets[curr] += 1;
    }

    for (int i = 0; i < 10; i++) {
        count += buckets[i] / 2;
    }

    return count;
}

void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            int p1 = j; int p2 = j + 1;
            if (arr[p1] > arr[p2]) {
                std::swap(arr[p1], arr[p2]);
            }
        }
    }
}

void selectionSort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        int maxInd = 0;
        for (int j = 1; j < size - i; j++) {
            if (arr[maxInd] < arr[j]) {
                maxInd = j;
            }
        }
        std::swap(arr[maxInd], arr[size - i - 1]);
    }
}

void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int curr = arr[i];
        
        int j = i - 1;
        while (arr[j] > curr && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
    }
}

void printArr(int* arr, int size) {
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

int main()
{
    int arr[] = {2, 2, 3, 1, 4, 2, 4, 2, 4, 4, 5, 2, 1, 9, 3, 6, 0, 0};
    insertionSort(arr, 18);
    printArr(arr, 18);
}
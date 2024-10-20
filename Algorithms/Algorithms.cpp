#include <iostream>
#include <vector>

// Utilities

void printArr(int* arr, int size) {
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

void printArr(std::vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

// Technique-ilustrative excercises

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

// Slow sorting algorithms all go O(N^2)
// -> That is because on each iteration they put exactly one more element
// it it's correct, sorted place.
// -> The only way they differ is in the way they choose to accomplish
// the task of moving one element to the correct position.

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

// Fast sorting algorithms

void merge(int* arr, int begin, int mid, int end) {
    // 0 4 9

    // Create a copy of the left part
    int leftSize = mid - begin + 1;
    int* leftArr = new int[leftSize];
    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[begin + i];
    }

    // Craete a copy of the right part
    int rightSize = end - mid;
    int* rightArr = new int[rightSize];
    for (int i = 0; i < rightSize; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    // Insert as many items as you can from left or right
    int li = 0; int ri = 0; int ai = begin;
    while (li < leftSize && ri < rightSize) {
        if (leftArr[li] <= rightArr[ri]) {
            arr[ai] = leftArr[li];
            ai++; li++;
        }
        else {
            arr[ai] = rightArr[ri];
            ai++; ri++;
        }
    }

    // Insert rest of left if any
    while (li < leftSize) {
        arr[ai] = leftArr[li];
        ai++; li++;
    }

    // Insert rest of right if any
    while (ri < rightSize) {
        arr[ai] = rightArr[ri];
        ai++; ri++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int* arr, int begin, int end) {
    if (end > begin) {
        int mid = begin + (end - begin) / 2;
        mergeSort(arr, begin, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, begin, mid, end);
    }
}

int main()
{
    int arr[] = {2, 2, 3, 1, 4, 2, 4, 2, 4, 4, 5, 2, 1, 9, 3, 6, 0, 0};
    mergeSort(arr, 0, 17);
    printArr(arr, 18);
}
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

void printArr(unsigned char* arr, int size) {
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

int partition(int* arr, int begin, int end) {
    // Pick a pivot element (I'll choose the last one as is customary)
    int pivotValue = arr[end];

    // Init pointer which is going to represent the end of the smaller-than-pivot numbers
    int smallerValuesEnd = begin - 1;

    // Go trough the arr with another pointer
    for (int i = begin; i < end; i++)
    {
        // Whenever you find an element that is smaller than the pivot
        // - increment the pointer to the smaller part and swap the numbers
        // This way we move all numbers that are supposed to be on the smaller side to it
        if (arr[i] < pivotValue) {
            smallerValuesEnd++;
            std::swap(arr[i], arr[smallerValuesEnd]);
        }
    }

    // After we are done, we just swap the pivot and the end of the 'smaller' part
    std::swap(arr[smallerValuesEnd + 1], arr[end]);
    return smallerValuesEnd + 1;
}

void quickSort(int* arr, int begin, int end) {
    if (end > begin) {
        int pivotIndex = partition(arr, begin, end);

        quickSort(arr, begin, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}

// Specical case sorting algorithms
// Counting Sort

void countingSort(unsigned char* arr, int size) {
    // Count occurances of each element
    int count[256] = { 0 };
    for (int i = 0; i < size; i++) {
        unsigned char el = arr[i];
        count[el]++;
    }

    // Remake the count array, so it actually tells you
    // the last index (+1) at which the element is going to 
    // be seen in the sorted array
    for (int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }

    // Create the Sorted array
    unsigned char* outputArr = new unsigned char[size];
    for (int i = size - 1; i >= 0; i--) {
        unsigned char el = arr[i];
        int putIndex = count[el] - 1;
        outputArr[putIndex] = el;
        count[el]--;
    }

    // Copy output into arr, since, we could not have done this in-place
    for (int i = 0; i < size; i++) {
        arr[i] = outputArr[i];
    }

    delete[] outputArr;
}

int main() {
    //int arr[] = {2, 2, 3, 1, 4, 2, 4, 2, 4, 4, 5, 2, 1, 9, 3, 6, 0, 0};
    unsigned char arr[] = { 'b', 'd', 'a', 'c', 'L', 'E', 'e', 'a', 'K', 'b', 'd', 'c', 'A', 'F', 'M'};
    countingSort(arr, 15);
    printArr(arr, 15);
}
#include <iostream>
#include <vector>
#include <algorithm>

void bounds(std::vector<int>& arr, int target) {
    // Find Lower bound
    auto lower = lower_bound(arr.begin(), arr.end(), target);
    int lIndex = lower - arr.begin();
    int lBound = arr[lIndex] == target ? lIndex : -1;

    // Find uppper bound
    auto upper = upper_bound(arr.begin(), arr.end(), target);
    int uIndex = upper - arr.begin() - 1;
    int uBound = arr[uIndex] == target ? uIndex : -1;

    // Result
    std::cout << "[" << lBound << ", " << uBound << "]" << std::endl;
}
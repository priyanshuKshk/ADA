#include <iostream>
using namespace std;

int findPeak(int arr[], int low, int high, int n) {
    int mid = low + (high - low) / 2;

    if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid])) {
        return mid;
    }
    else if (mid > 0 && arr[mid - 1] > arr[mid]) {
        return findPeak(arr, low, mid - 1, n);
    }
    else {
        return findPeak(arr, mid + 1, high, n);
    }
}

int main() {
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int peakIndex = findPeak(arr, 0, n - 1, n);
    cout << "Peak found at index: " << peakIndex << ", value: " << arr[peakIndex] << endl;
    return 0;
}
 
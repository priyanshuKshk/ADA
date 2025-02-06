#include <iostream>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <random>

using namespace std;

// Merge function to merge two halves
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    int i = 0; // Initial index of the first subarray
    int j = 0; // Initial index of the second subarray
    int k = l; // Initial index of the merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free dynamically allocated memory
    delete[] L;
    delete[] R;
}

// Merge Sort function
void mergeSort(int arr[], int l, int r) {
    if (l >= r) {
        return; // Base case: arrays of size 1 are already sorted
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// Function to generate a random array of given size
int* generateArray(int size) {
    int* arr = new int[size];
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 10000);
    for (int i = 0; i < size; ++i) {
        arr[i] = dis(gen);
    }
    return arr;
}

int main() {
    // Sizes of arrays to test
    int sizes[] = {100, 500, 1000, 5000, 10000, 20000, 50000, 100000};
    ofstream dataFile("merge_sort_data.csv");

    if (dataFile.is_open()) {
        dataFile << "Array Size,Execution Time (ms)\n";
        for (int size : sizes) {
            int* arr = generateArray(size);

            auto start = chrono::high_resolution_clock::now();
            mergeSort(arr, 0, size - 1);
            auto end = chrono::high_resolution_clock::now();

            chrono::duration<double, milli> duration = end - start;
            dataFile << size << "," << duration.count() << "\n";

            cout << "Sorted array of size " << size << " in " << duration.count() << " ms.\n";

            delete[] arr; // Free dynamically allocated memory
        }
        dataFile.close();
    } else {
        cerr << "Unable to open file for writing\n";
    }

    return 0;
}

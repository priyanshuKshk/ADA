#include <iostream>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <random>
#include <iomanip> // For setprecision

using namespace std;

// Selection Sort function
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[minIdx], arr[i]);
    }
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
    int sizes[] = {5000, 10000, 20000, 50000, 100000, 150000, 200000, 250000, 300000};
    ofstream dataFile("selection_sort_data.csv");

    if (!dataFile.is_open()) {
        cerr << "Unable to open file for writing\n";
        return 1;
    }

    dataFile << "Array Size,Execution Time (ms)\n";

    // Generate the largest array once
    int* largeArray = generateArray(300000);

    for (int size : sizes) {
        int* arr = new int[size];
        copy(largeArray, largeArray + size, arr); // Copy subset for testing

        auto start = chrono::high_resolution_clock::now();
        selectionSort(arr, size);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> duration = end - start;
        dataFile << size << "," << fixed << setprecision(2) << duration.count() << "\n";

        cout << "Sorted array of size " << size << " in " << duration.count() << " ms.\n";

        delete[] arr; // Free dynamically allocated memory
    }

    delete[] largeArray; // Free the largest array
    dataFile.close();

    return 0;
}
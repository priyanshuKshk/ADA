#include <iostream>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <random>

using namespace std;

// Bubble Sort function
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
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
    int sizes[] = {100, 500, 1000, 5000, 10000, 20000, 50000, 100000};
    ofstream dataFile("bubble_sort_data.csv");

    if (dataFile.is_open()) {
        dataFile << "Array Size,Execution Time (ms)\n";
        for (int size : sizes) {
            int* arr = generateArray(size);

            auto start = chrono::high_resolution_clock::now();
            bubbleSort(arr, size);
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

#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std; // Place it here if needed

// Function to perform insertion sort
void insertionSort(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Function to generate random data
vector<int> generateData(size_t size) {
    vector<int> data(size);
    for (size_t i = 0; i < size; ++i) {
        data[i] = rand() % 10000; // Random numbers between 0 and 9999
    }
    return data;
}

int main() {
    ofstream file("insertion_sort_times.csv");
    file << "Size,Time\n";

    for (size_t size = 1000; size <= 10000; size += 1000) {
        vector<int> data = generateData(size);

        auto start = chrono::high_resolution_clock::now();
        insertionSort(data);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = end - start;
        file << size << "," << duration.count() << "\n";

        cout << "Sorted " << size << " elements in " << duration.count() << " seconds.\n";
    }

    file.close();
    return 0;
}

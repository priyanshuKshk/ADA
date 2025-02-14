#include<iostream>
#include<stack>

using namespace std;
int maxStackDepth =0;
int partition(int arr[], int low, int high) {
    int pivot =arr[0]; 
    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (arr[j] >= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}


int quickSort(int arr[], int low, int high , int Depth) {
    if (low < high) {
      maxStackDepth =max( maxStackDepth,Depth);
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1, Depth+1);
        quickSort(arr, pi + 1, high,Depth+1);
     
    }
    return Depth;
}

    void printArray(int arr[], int size) {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    
    int main() {
        int arr[] = { 7, 12, 14,89,67,33,8, };
        int n = sizeof(arr) / sizeof(arr[0]);
        quickSort(arr, 0, n - 1, 1); 
        cout << "Sorted array: \n";
       
        printArray(arr, n);
        cout << "Maximum stack depth: " << maxStackDepth << endl;
        
        return 0;
    }


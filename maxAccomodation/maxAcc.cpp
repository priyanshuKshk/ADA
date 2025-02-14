#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Function to swap two elements
void swap(float& a, float& b) {
    float t = a;
    a = b;
    b = t;
}




int sjf(float finish[], float arrival[], int n) {
    // Bubble sort for sorting
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) { // O(n^2)
            if (finish[j] > finish[j + 1]) {
                swap(finish[j], finish[j + 1]);
                swap(arrival[j], arrival[j + 1]);
            }
        }
    }
    cout << "Arrival Time\tFinish Time\n";
    for (int i = 0; i < n; i++) {
        cout << arrival[i] << "\t\t" << finish[i] << "\n";
    }

    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (finish[i] < arrival[i + 1]) {
            cnt++;
        }
    }
    return cnt;
}
int fcfs(float finish[], float arrival[], int n) {
    // Bubble sort for sorting
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) { // O(n^2)
            if (arrival[j] > arrival[j + 1]) {
                swap(finish[j], finish[j + 1]);
                swap(arrival[j], arrival[j + 1]);
            }
        }
    }
    cout << "Arrival Time\tFinish Time\n";
    for (int i = 0; i < n; i++) {
        cout << arrival[i] << "\t\t" << finish[i] << "\n";
    }
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (finish[i] < arrival[i + 1]) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n;
    cout << "input size = ";
    cin >> n;
    float* arrival = new float[n];
    float* finish = new float[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time for index " << i << " = ";
        cin >> arrival[i];
        cout << "Enter finish time for index " << i << " = ";
        cin >> finish[i];
    }
    cout << "Number of process work: " << sjf(finish, arrival, n) << "\n";
    

    cout<<"<-----------------------------------------------";
    cout<<endl;
    cout << "Number of process work: " << fcfs(finish, arrival, n) << "\n";
  
    return 0;

}

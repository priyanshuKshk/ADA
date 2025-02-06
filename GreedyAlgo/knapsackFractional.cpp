#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define the Item struct
struct Item {
    int weight;
    int value;
    double ratio;
};

// Function to calculate the ratio of value to weight
void calculateRatio(vector<Item>& items) {
    for (auto& item : items) {
        item.ratio = (double)item.value / item.weight;
    }
}

// Function to sort items by ratio in descending order
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

// Function to solve the knapsack problem
double knapsack(vector<Item>& items, int W) {
    // Calculate the ratio of value to weight for each item
    calculateRatio(items);

    // Sort items by ratio in descending order
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0; // Total value of items taken in the knapsack
    int remainingCapacity = W; // Remaining capacity of the knapsack

    // Iterate through the sorted items
    for (const auto& item : items) {
        if (remainingCapacity >= item.weight) {
            // Take the whole item
            totalValue += item.value;
            remainingCapacity -= item.weight;
        } else {
            // Take a fraction of the item
            totalValue += item.ratio * remainingCapacity;
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};
    int W = 50; // Capacity of the knapsack

    double maxValue = knapsack(items, W);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}
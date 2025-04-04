#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minOperationsToSort(vector<int>& weight, vector<int>& dist) {
    int n = weight.size();
    
    // Create a vector of pairs: (weight, dist)
    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        points[i][0] = weight[i];
        points[i][1] = dist[i];
    }
    
    // Sort by weight in ascending order
    sort(points.begin(), points.end());
    
    int moves = 0;
    int current_pos = 0;  // Tracks the current position on the x-axis

    for (int i = 0; i < n; ++i) {
        int target_pos = current_pos + 1;  // The position this weight should go to
        while (current_pos < target_pos) {
            current_pos += points[i][1];  // Add dist to the current position
            ++moves;  // Increment the move counter
        }
        // Update current position for the next weight
        current_pos = target_pos;
    }

    return moves;
}

int main() {
    vector<int> weight = {3, 6, 5, 2};
    vector<int> dist = {4, 3, 2, 1};
    cout << "Minimum operations: " << minOperationsToSort(weight, dist) << endl;

    vector<int> weight2 = {2, 4, 3, 1};
    vector<int> dist2 = {2, 6, 3, 5};
    cout << "Minimum operations: " << minOperationsToSort(weight2, dist2) << endl;

    return 0;
}
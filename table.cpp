#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// Global variables to generate table coordinates in the proper order
int genS = 0; // Sum of i+j
int genI = 0; // Current i value for a given sum

// Structure to represent a table's position and occupancy
struct Table {
    int i, j; // Table coordinates (in the problem's transformed coordinate system)
    int occ;  // Current occupancy (0-4)
    
    Table(int _i, int _j, int _occ) : i(_i), j(_j), occ(_occ) {}
    
    // Function to get cell coordinates for a specific seat at this table
    pair<int, int> getSeatCoordinates() const {
        // Convert table coordinates to actual seat coordinates
        // Tables are at positions (3i+1, 3j+1), (3i+1, 3j+2), (3i+2, 3j+1), (3i+2, 3j+2)
        switch (occ) {
            case 0: return {3*i+1, 3*j+1}; // First seat
            case 1: return {3*i+1, 3*j+2}; // Second seat
            case 2: return {3*i+2, 3*j+1}; // Third seat
            case 3: return {3*i+2, 3*j+2}; // Fourth seat
            default: return {-1, -1};      // Should never happen
        }
    }
};

// Function to compute the key for sorting tables in the priority queue
// The key includes distance and tie-breakers
tuple<int, int, int, int> getKey(const Table& table) {
    int baseDistance = 3 * (table.i + table.j);
    int offset = 0;
    
    // Adjust offset based on the occupied seats
    switch (table.occ) {
        case 0: offset = 0; break;
        case 1: offset = 1; break;
        case 2: offset = 1; break;
        case 3: offset = 2; break;
    }
    
    return make_tuple(baseDistance + offset, table.i, table.j, table.occ);
}

// Comparator for the priority queue
struct TableComparator {
    bool operator()(const Table& a, const Table& b) const {
        return getKey(a) > getKey(b); // Min-heap based on the key
    }
};

// Generate the next empty table in the correct order
Table nextEmptyTable() {
    int i = genI;
    int j = genS - genI;
    
    // Update generators for the next call
    genI++;
    if (genI > genS) {
        genS++;
        genI = 0;
    }
    
    return Table(i, j, 0);
}

// Process each test case
void solve() {
    int n;
    cin >> n;
    
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    
    // Reset table generators for each test case
    genS = 0;
    genI = 0;
    
    // Priority queues for different types of tables
    priority_queue<Table, vector<Table>, TableComparator> pqPrivate; // Empty tables
    priority_queue<Table, vector<Table>, TableComparator> pqShared;  // Partially occupied tables
    
    for (int i = 0; i < n; i++) {
        if (t[i] == 0) {
            // Guest wants an unoccupied table
            while (pqPrivate.empty() || pqPrivate.top().occ > 0) {
                pqPrivate.push(nextEmptyTable());
            }
            
            Table bestTable = pqPrivate.top();
            pqPrivate.pop();
            
            // Get the coordinates of the seat
            pair<int, int> seat = bestTable.getSeatCoordinates();
            cout << seat.first << " " << seat.second << endl;
            
            // Update and reinsert the table
            bestTable.occ++;
            if (bestTable.occ < 4) {
                pqShared.push(bestTable);
            }
        } else {
            // Guest is willing to share a table
            // Add empty tables until we have at least one candidate
            while (pqPrivate.empty() && pqShared.empty()) {
                pqPrivate.push(nextEmptyTable());
            }
            
            // Keep adding tables until we're sure we have the best one
            while (!pqPrivate.empty() && !pqShared.empty() && 
                   getKey(pqPrivate.top()) > getKey(pqShared.top())) {
                pqPrivate.push(nextEmptyTable());
            }
            
            Table bestTable;
            if (pqShared.empty() || 
                (!pqPrivate.empty() && getKey(pqPrivate.top()) < getKey(pqShared.top()))) {
                bestTable = pqPrivate.top();
                pqPrivate.pop();
            } else {
                bestTable = pqShared.top();
                pqShared.pop();
            }
            
            // Get the coordinates of the seat
            pair<int, int> seat = bestTable.getSeatCoordinates();
            cout << seat.first << " " << seat.second << endl;
            
            // Update and reinsert the table
            bestTable.occ++;
            if (bestTable.occ < 4) {
                pqShared.push(bestTable);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q;
    cin >> q;
    
    while (q--) {
        solve();
    }
    
    return 0;
}
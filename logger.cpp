#include <bits/stdc++.h>
using namespace std;

class Logger {
private:
    // Define any data members here, like a map to track message timestamps
    unordered_map<string, int> mp;
public:
    // Constructor to initialize the logger object
    Logger() {
        // Initialize the necessary data members
    }

    /**
     * Returns true if the message should be printed in the given timestamp, otherwise returns false.
     * The timestamp is in seconds granularity.
     */
    bool shouldPrintMessage(int timestamp, string message) {
        // Implement the logic to check if the message should be printed

        if(mp.find(message) != mp.end()){
          if(mp[message] > timestamp){
            return false; 
          }
        }
        
        mp[message] = timestamp + 10;
        return true;
    }
};

int main() {
    Logger logger;

    // Example operations
    cout << logger.shouldPrintMessage(1, "foo") << endl;  // Expected output: 1 (true)
    cout << logger.shouldPrintMessage(2, "bar") << endl;  // Expected output: 1 (true)
    cout << logger.shouldPrintMessage(3, "foo") << endl;  // Expected output: 0 (false)
    cout << logger.shouldPrintMessage(8, "bar") << endl;  // Expected output: 0 (false)
    cout << logger.shouldPrintMessage(10, "foo") << endl; // Expected output: 0 (false)
    cout << logger.shouldPrintMessage(11, "foo") << endl; // Expected output: 1 (true)

    return 0;
}

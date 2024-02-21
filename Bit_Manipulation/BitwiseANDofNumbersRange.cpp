#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // If both left and right are 0, return 0
        if (left == 0 && right == 0) {
            return 0;
        }
        // If left is 1 and right is the maximum value of 32-bit integer, return 0
        if (left == 1 && right == 2147483647) {
            return 0;
        }
        
        int count = 0; // Initialize a counter to count the number of shifts needed
        
        // Keep right-shifting both left and right until they become equal
        while (left != right) {
            left >>= 1; // Right-shift left by 1 (equivalent to division by 2)
            right >>= 1; // Right-shift right by 1 (equivalent to division by 2)
            count++; // Increment the count for each shift
        }

        // Left-shift left by count to get the result
        return (left << count);
    }
};

int main() {
    Solution obj;
    int left, right;
    
    // Input left and right values from the user
    cout << "Enter the value of left: ";
    cin >> left;
    cout << "Enter the value of right: ";
    cin >> right;
    
    // Call the rangeBitwiseAnd method and print the result
    cout << "Result: " << obj.rangeBitwiseAnd(left, right) << endl;
    
    return 0;
}

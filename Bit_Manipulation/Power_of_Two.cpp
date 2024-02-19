#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // #########  linear solution ###########
        // long long ans = 1 ; 
        // for(int i = 0 ; i <=30 ; i++)
        // {   
        //     if(ans == n)
        //         return true ;
        //     ans = ans * 2 ;
        // }
        // return false ;

        // ############ Binary search #########

        // if (n <= 0) // Check if n is non-positive, as power of two numbers are always positive
        //     return false;

        // int start = 0;
        // int end = 30;

        // while (start <= end) {
        //     int mid = start + (end - start) / 2; // Calculate mid correctly
        //     int power = 1 << mid; // Calculate the power of 2
        //     cout<<power<<endl;

        //     if (power == n) { // Compare n with the calculated power
        //         return true;
        //     } else if (power < n) { // Adjust comparison logic
        //         start = mid + 1;
        //     } else {
        //         end = mid - 1;
        //     }
        // }

        // return false;

        // ############ Bit wise solution ############

        return n > 0 && not (n & n - 1);
    }
};

int main() {
    Solution solution;
    int n;

    // Input n from the user
    cout << "Enter a number: ";
    cin >> n;

    // Check if the number is a power of two
    bool result = solution.isPowerOfTwo(n);
    if (result) {
        cout << n << " is a power of two." << endl;
    } else {
        cout << n << " is not a power of two." << endl;
    }

    return 0;
}

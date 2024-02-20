#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0; 

        for(int i = 0; i <= nums.size(); i++) {
            sum += i;
        }

        for(int i = 0; i < nums.size(); i++) {
            sum -= nums[i];
        }
        return sum;
    }
};

int main() {
    Solution sol;
    
    // Taking input for vector size
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;
    
    // Taking input for vector elements
    vector<int> nums(n);
    cout << "Enter the elements of the vector:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Calling the missingNumber function
    int missing = sol.missingNumber(nums);
    cout << "The missing number is: " << missing << endl;

    return 0;
}

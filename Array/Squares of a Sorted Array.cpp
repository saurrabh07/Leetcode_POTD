#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i] * nums[i]]++;
        }
        for (auto i : m) {
            while (i.second--) {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> result = sol.sortedSquares(nums);
    cout << "Sorted squares of the elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> um;
        for (int i = 0; i < arr.size(); i++) {
            um[arr[i]]++;
        }
        
        vector<pair<int, int>> freqVec(um.begin(), um.end());
        sort(freqVec.begin(), freqVec.end(), cmp);
        
        int removed = 0;
        for (const auto& p : freqVec) {
            if (k >= p.second) {
                k -= p.second;
                removed++;
            } else {
                break;
            }
        }
        
        return um.size() - removed;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    Solution solution;
    int result = solution.findLeastNumOfUniqueInts(arr, k);
    cout << "Minimum number of unique integers after removing " << k << " elements: " << result << endl;

    return 0;
}

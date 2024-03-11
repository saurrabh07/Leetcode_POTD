#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Brute Force Solution
    string customSortStringBruteForce(string order, string s) {
        unordered_map<char, int> um;
        for (auto i : s) {
            um[i]++;
        }
        s.erase();
        for (auto i : order) {
            if (um.find(i) != um.end()) {
                int t = um[i];
                while (t--) {
                    s += i;
                    um[i]--;
                }
            }
        }
        for (auto i : um) {
            if (i.second != 0) {
                int x = i.second;
                while (x--) {
                    s += i.first;
                }
            }
        }
        return s;
    }

    // Optimal Solution
    string customSortStringOptimal(string order, string s) {
        unordered_map<char, int> um;
        for (auto i : s) {
            um[i]++;
        }
        s.erase();
        for (auto i : order) {
            if (um.find(i) != um.end()) {
                s.append(um[i], i);
                um.erase(i);
            }
        }
        for (auto i : um) {
            s.append(i.second, i.first);
        }
        return s;
    }

    // User input function
    void userInput() {
        string order, s;
        cout << "Enter the custom order string: ";
        cin >> order;
        cout << "Enter the string to be sorted: ";
        cin >> s;

        cout << "Using Brute Force: " << customSortStringBruteForce(order, s) << endl;
        cout << "Using Optimal Solution: " << customSortStringOptimal(order, s) << endl;
    }
};

int main() {
    Solution solution;
    solution.userInput();
    return 0;
}

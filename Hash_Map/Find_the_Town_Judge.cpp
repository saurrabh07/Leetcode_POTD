#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
         vector<int> trusting(n + 1, 0);   
        vector<int> trusted(n + 1, 0);     
        for (auto i : trust) {                    // Count trust relationships
            trusting[i[0]]++;                    // Increment trust given
            trusted[i[1]]++;                    // Increment trust received
        }
        int ans = -1;                            // Initialize result
                       
        for (int i = 1; i <= n; i++)           // Find the person trusted by everyone else
            if (trusting[i] == 0 && trusted[i] == n - 1){ 
                ans = i;             // Update result
            }
        return ans;  
    }
};

int main() {
    int n, m;
    cout << "Enter the number of people: ";
    cin >> n;
    cout << "Enter the number of trust relationships: ";
    cin >> m;

    vector<vector<int>> trust(m, vector<int>(2));
    cout << "Enter trust relationships (trustor trustee):" << endl;
    for (int i = 0; i < m; ++i) {
        cin >> trust[i][0] >> trust[i][1];
    }

    Solution sol;
    int judge = sol.findJudge(n, trust);
    if (judge != -1)
        cout << "The judge is person " << judge << endl;
    else
        cout << "There is no judge in the town" << endl;

    return 0;
}

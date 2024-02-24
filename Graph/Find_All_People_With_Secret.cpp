#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int , int>>> g(n);
        
        // Building graph
        for(auto &meeting : meetings) {
            g[meeting[0]].push_back({meeting[1], meeting[2]});
            g[meeting[1]].push_back({meeting[0], meeting[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        vector<int> vis(n);
        
        // Dijkstra's algorithm
        pq.push({0, firstPerson});
        while(!pq.empty()) {
            auto [t , x] = pq.top(); pq.pop();
            if(vis[x]) continue ;
            vis[x] = 1 ;
            for(auto &it : g[x]) {
                if(vis[it.first]) continue;
                if(it.second >= t) pq.push({it.second , it.first});
            }
        }
        
        // Retrieve result
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(vis[i]) ans.push_back(i);
        }

        return ans;
    }
};

int main() {
    int n, firstPerson;
    cout << "Enter the number of people: ";
    cin >> n;
    
    int meetingsCount;
    cout << "Enter the number of meetings: ";
    cin >> meetingsCount;

    vector<vector<int>> meetings(meetingsCount, vector<int>(3));
    cout << "Enter meeting details (start end time):" << endl;
    for (int i = 0; i < meetingsCount; ++i) {
        cin >> meetings[i][0] >> meetings[i][1] >> meetings[i][2];
    }

    cout << "Enter the starting person: ";
    cin >> firstPerson;

    Solution solution;
    vector<int> result = solution.findAllPeople(n, meetings, firstPerson);

    cout << "People who can attend meetings without overlapping: ";
    for (int person : result) {
        cout << person << " ";
    }
    cout << endl;

    return 0;
}

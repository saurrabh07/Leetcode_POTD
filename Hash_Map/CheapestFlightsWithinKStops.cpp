#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    unordered_map<int, vector<pair<int, int>>> adj;
    vector<int> visited(n, INT_MAX);
    visited[src] = 0;
    
    for (const auto& x : flights) {
        adj[x[0]].push_back({x[1], x[2]});
    }
    
    int count = 0;
    queue<pair<int, int>> qu;
    qu.push({src, 0});
    k++;
    
    while (k--) {
        int size = qu.size();
        while (size--) {
            int curr_price = qu.front().second;
            for (auto& x : adj[qu.front().first]) {
                int new_price = x.second + curr_price;
                if (new_price < visited[x.first]) {
                    visited[x.first] = new_price;
                    qu.push({x.first, new_price});
                }
            }
            qu.pop();
        }
        count++;
    }
    return (visited[dst] == INT_MAX) ? -1 : visited[dst];
}

int main() {
    int n, src, dst, k;
    cout << "Enter the number of nodes: ";
    cin >> n;
    
    vector<vector<int>> flights;
    int m;
    cout << "Enter the number of flights: ";
    cin >> m;

    cout << "Enter the flights in format (source destination price):" << endl;
    for (int i = 0; i < m; ++i) {
        int source, destination, price;
        cin >> source >> destination >> price;
        flights.push_back({source, destination, price});
    }

    cout << "Enter source, destination, and max stops: ";
    cin >> src >> dst >> k;

    int cheapestPrice = findCheapestPrice(n, flights, src, dst, k);

    if (cheapestPrice == -1)
        cout << "There is no path from source to destination within " << k << " stops." << endl;
    else
        cout << "The cheapest price from source to destination within " << k << " stops is: " << cheapestPrice << endl;

    return 0;
}

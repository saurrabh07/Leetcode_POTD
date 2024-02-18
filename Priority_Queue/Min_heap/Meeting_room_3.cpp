#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

#define ll long long int

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
         
        // Map to store the number of meetings booked in each room
        map<int, int> booked;
        
        // Comparator for priority queue to sort meetings by smallest end time
        auto compare = [](const pair<ll, int>& a, const pair<ll, int>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            } else {
                return a.first > b.first;
            }
        };

        // Priority queue to store meetings based on end time
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, decltype(compare)> pq;

        // Priority queue to store available rooms
        priority_queue<int, vector<int>, greater<int>> freeRooms;

        // Initialize available rooms
        for (int i = 0; i < n; i++) {
            freeRooms.push(i);
        }

        // Sort meetings based on start time
        sort(meetings.begin(), meetings.end());

        // Process each meeting
        for (auto& v : meetings) {
            ll start = v[0], end = v[1];
            
            // Remove meetings from the priority queue that have ended before the current meeting starts
            while (!pq.empty() && pq.top().first <= start) {
                freeRooms.push(pq.top().second);
                pq.pop();
            }

            // Assign a room to the current meeting
            if (!freeRooms.empty()) {
                booked[freeRooms.top()]++;
                pq.push({end, freeRooms.top()});
                freeRooms.pop();
            } else {
                // If no free rooms are available, delay the meeting and extend the existing meeting in the room with the earliest end time
                booked[pq.top().second]++;
                auto p = pq.top();
                pq.pop();
                pq.push({p.first + end - start, p.second});
            }
        }

        // Find the room with the most meetings
        int maxRooms = 0;
        int meetingRoom = -1;

        for (auto p : booked) {
            if (p.second > maxRooms) {
                maxRooms = p.second;
                meetingRoom = p.first;
            }
        }
        return meetingRoom;
    }
};

int main() {
    // Input the number of rooms
    int n;
    cout << "Enter the number of rooms: ";
    cin >> n;

    // Input the number of meetings
    int m;
    cout << "Enter the number of meetings: ";
    cin >> m;

    // Input the start and end times of each meeting
    vector<vector<int>> meetings(m, vector<int>(2));
    cout << "Enter the start and end times of each meeting:\n";
    for (int i = 0; i < m; ++i) {
        cout << "Meeting " << i + 1 << " start time: ";
        cin >> meetings[i][0];
        cout << "Meeting " << i + 1 << " end time: ";
        cin >> meetings[i][1];
    }

    // Instantiate the Solution class
    Solution s;

    // Calculate the room with the most meetings
    int mostBookedRoom = s.mostBooked(n, meetings);

    // Print the room with the most meetings
    cout << "The room with the most meetings: " << mostBookedRoom << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    // void maxReaches(vector<int>& heights, int bricks, int ladders, int i, int& maxIndex, int n) {
    //     if (i == n - 1) {
    //         maxIndex = i; // Update maxIndex when reaching the last building
    //         return;
    //     }

    //     if (heights[i] < heights[i + 1]) {
    //         if (ladders == 0 && (bricks < (heights[i + 1] - heights[i]) || bricks == 0)) {
    //             maxIndex = max(maxIndex, i); // Update maxIndex when unable to proceed further
    //             return;
    //         }
    //         if (bricks >= (heights[i + 1] - heights[i])) {
    //             bricks -= (heights[i + 1] - heights[i]);
    //             maxReaches(heights, bricks, ladders, i + 1, maxIndex, n);
    //             bricks += (heights[i + 1] - heights[i]); // Backtrack
    //         }
    //         if (ladders != 0) {
    //             maxReaches(heights, bricks, ladders - 1, i + 1, maxIndex, n);
    //         }
    //     } else {
    //         maxReaches(heights, bricks, ladders, i + 1, maxIndex, n); // Move to the next building
    //     }
    // }
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {



        // Recursion solution

        // int i = 0;
        // int maxIndex = 0;
        // int n = heights.size();
        // maxReaches(heights, bricks, ladders, i, maxIndex, n);
        // return maxIndex;
        

        // Soution By priority_queue
        
        // Priority Queue for storing the bricks used in each step in decreasing order (Max at top)
        priority_queue<int> p;
        
        int i = 0, diff = 0; 
        for (i = 0; i < heights.size() - 1; i++) { 
            diff = heights[i + 1] - heights[i];
            if (diff <= 0) {
                continue;
            }

            bricks -= diff; 
            p.push(diff); 
       
            if (bricks < 0) {
                bricks += p.top(); 
                p.pop(); 
                ladders--;
            }

            if (ladders < 0) {
                break;
            }
        }
        
        return i;
    }
};

int main() {
    Solution solution;
    vector<int> heights;
    int n;
    cout << "Enter the number of buildings: ";
    cin >> n;

    cout << "Enter the heights of buildings: ";
    for (int i = 0; i < n; i++) {
        int height;
        cin >> height;
        heights.push_back(height);
    }

    int bricks, ladders;
    cout << "Enter the number of bricks: ";
    cin >> bricks;
    cout << "Enter the number of ladders: ";
    cin >> ladders;

    int furthest = solution.furthestBuilding(heights, bricks, ladders);
    cout << "The furthest building reachable is at index: " << furthest << endl;

    return 0;
}

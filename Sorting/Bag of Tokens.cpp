#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Brute force solution for bag of tokens score
    int bagOfTokensScore_BruteForce(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0;
        int i = 0;
        int j = tokens.size() - 1;

        while (i <= j) {
            while (power >= tokens[i]) {
                power -= tokens[i];
                score++;
                i++;
                if (i > j) {
                    break;
                }
            }

            if (i < j && score >= 1) {
                power += tokens[j];
                score--;
                j--;
            }
            else {
                i++;
            }
        }

        return score;
    }

    // Optimal solution for bag of tokens score
    int bagOfTokensScore_Optimal(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0;
        int maxScore = 0;
        int i = 0;
        int j = tokens.size() - 1;

        while (i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i];
                score++;
                maxScore = max(maxScore, score);
                i++;
            }
            else if (score > 0) {
                power += tokens[j];
                score--;
                j--;
            }
            else {
                break;
            }
        }

        return maxScore;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the number of tokens: ";
    cin >> n;

    vector<int> tokens(n);
    cout << "Enter the token values: ";
    for (int i = 0; i < n; ++i) {
        cin >> tokens[i];
    }

    int power;
    cout << "Enter the initial power: ";
    cin >> power;

    cout << "Brute Force Solution: " << sol.bagOfTokensScore_BruteForce(tokens, power) << endl;
    cout << "Optimal Solution: " << sol.bagOfTokensScore_Optimal(tokens, power) << endl;

    return 0;
}

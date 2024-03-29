#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>

using namespace std;

int maxFrequencyElements(vector<int>& nums) {
    int maxFrequency = 0;
    unordered_map<int, int> frequencyMap;

    // Iterate through the vector and count element frequencies
    for (int num : nums) {
        frequencyMap[num]++;
    }

    // Find the element with the maximum frequency
    for (unordered_map<int, int>::iterator it = frequencyMap.begin(); it != frequencyMap.end(); ++it) {
        maxFrequency = max(maxFrequency, it->second);
    }

    // Handle the case where all elements have the same frequency (edge case)
    if (maxFrequency == 1) {
        return nums.size(); // All elements have the same frequency (1)
    }

    // Count the number of elements with the maximum frequency
    int elementsWithMaxFrequency = 0;
    for (unordered_map<int, int>::iterator it = frequencyMap.begin(); it != frequencyMap.end(); ++it) {
        if (it->second == maxFrequency) {
            elementsWithMaxFrequency++;
        }
    }

    return elementsWithMaxFrequency;
}

int main() {
    int n;

    // Prompt user for input size
    cout << "Enter the number of elements: ";
    cin >> n;

    // Input validation (handle negative or zero size)
    while (n <= 0) {
        cout << "Invalid input. Please enter a positive number: ";
        cin >> n;
    }

    vector<int> nums(n);

    // Get user input for elements
    cout << "Enter the elements (integers):\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = maxFrequencyElements(nums);
    cout << "The number of elements with the maximum frequency: " << result << endl;

    return 0;
}
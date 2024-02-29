#include <iostream>
#include <queue>
#include <climits> // For INT_MIN and INT_MAX

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (root == nullptr) {
            return true; // An empty tree is considered as an even-odd tree
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int sz = q.size();
            int prevVal = (level % 2 == 0) ? INT_MIN : INT_MAX; // Set previous value based on level

            for (int i = 0; i < sz; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                // Check if the current value violates the conditions of an even-odd tree
                if ((level % 2 == 0 && (curr->val % 2 == 0 || curr->val <= prevVal)) ||
                    (level % 2 == 1 && (curr->val % 2 == 1 || curr->val >= prevVal))) {
                    return false;
                }

                prevVal = curr->val;

                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            }

            ++level;
        }

        return true;
    }

    // Brute-force solution to check if a binary tree is an even-odd tree
    bool isEvenOddTreeBruteForce(TreeNode* root) {
        if (root == nullptr) {
            return true; // An empty tree is considered as an even-odd tree
        }

        queue<TreeNode*> q;
        q.push(root);

        bool evenLevel = true; // Initial level is even
        while (!q.empty()) {
            int prevVal = (evenLevel) ? INT_MIN : INT_MAX;
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                if ((evenLevel && (curr->val % 2 == 0 || curr->val <= prevVal)) ||
                    (!evenLevel && (curr->val % 2 == 1 || curr->val >= prevVal))) {
                    return false;
                }

                prevVal = curr->val;

                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            }

            evenLevel = !evenLevel; // Toggle level
        }

        return true;
    }
};

// Utility function to create a binary tree from given values (for testing)
TreeNode* createTree() {
    int val;
    cin >> val;
    if (val == -1) {
        return nullptr; // Input -1 represents a null node
    }
    TreeNode* root = new TreeNode(val);
    root->left = createTree();
    root->right = createTree();
    return root;
}

int main() {
    Solution sol;

    cout << "Enter the values of the binary tree (or -1 for null nodes): ";
    TreeNode* root = createTree();

    // Check if the tree is an even-odd tree using the BFS approach
    if (sol.isEvenOddTree(root)) {
        cout << "The given tree is an even-odd tree." << endl;
    } else {
        cout << "The given tree is not an even-odd tree." << endl;
    }

    // Check if the tree is an even-odd tree using the brute-force approach
    if (sol.isEvenOddTreeBruteForce(root)) {
        cout << "The given tree is an even-odd tree (brute-force)." << endl;
    } else {
        cout << "The given tree is not an even-odd tree (brute-force)." << endl;
    }

    return 0;
}

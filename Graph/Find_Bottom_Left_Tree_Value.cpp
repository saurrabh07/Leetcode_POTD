#include <iostream>
#include <queue>

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
    int bottomLeftValue;
    int maxDepth;

    // DFS solution to find the bottom-left value
    void dfs(TreeNode* root, int depth) {
        if (root == NULL) {
            return;
        }
        if (depth > maxDepth) {
            maxDepth = depth;
            bottomLeftValue = root->val;
        }

        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

    // BFS solution to find the bottom-left value
    int findBottomLeftValue(TreeNode* root) {
        // Queue for BFS traversal
        queue<TreeNode*> q;
        TreeNode* curr = root;
        q.push(curr);

        bottomLeftValue = 0;
        maxDepth = -1;
        int depth = 0;

        // Perform BFS traversal
        while (!q.empty()) {
            int sz = q.size();
            depth++;
            while (sz--) {
                curr = q.front();
                q.pop();
                if (maxDepth < depth) {
                    maxDepth = depth;
                    bottomLeftValue = curr->val;
                }
                if (curr->left != NULL) q.push(curr->left);
                if (curr->right != NULL) q.push(curr->right);
            }
        }
        return bottomLeftValue;
    }
};

// Function to create a binary tree from user input
TreeNode* createTree() {
    int val;
    cout << "Enter root value (or -1 for NULL): ";
    cin >> val;
    if (val == -1)
        return NULL;
    TreeNode* root = new TreeNode(val);
    cout << "Enter left child of " << val << ":\n";
    root->left = createTree();
    cout << "Enter right child of " << val << ":\n";
    root->right = createTree();
    return root;
}

int main() {
    // Create the binary tree
    cout << "Enter values for the binary tree:\n";
    TreeNode* root = createTree();

    // Create a Solution object
    Solution sol;

    // Find bottom-left value using DFS
    sol.dfs(root, 0);
    cout << "Bottom-left value using DFS: " << sol.bottomLeftValue << endl;

    // Find bottom-left value using BFS
    int bottomLeftBFS = sol.findBottomLeftValue(root);
    cout << "Bottom-left value using BFS: " << bottomLeftBFS << endl;

    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Brute-force solution to find the height of a binary tree
int height(TreeNode* root) {
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Brute-force solution to find the diameter of a binary tree
int diameterBrute(TreeNode* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int leftDiameter = diameterBrute(root->left);
    int rightDiameter = diameterBrute(root->right);
    return max({leftHeight + rightHeight, leftDiameter, rightDiameter});
}

// Optimized solution to find the height of a binary tree and update the diameter
int diameterOptimized(TreeNode* root, int& diameter) {
    if (root == NULL)
        return 0;

    int lh = diameterOptimized(root->left, diameter);
    int rh = diameterOptimized(root->right, diameter);

    diameter = max(diameter, lh + rh);

    return 1 + max(lh, rh);
}

// Optimized solution to find the diameter of a binary tree
int diameterOfBinaryTree(TreeNode* root) {
    if (root == NULL)
        return 0;
    int maxDiameter = 0;
    diameterOptimized(root, maxDiameter);
    return maxDiameter;
}

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

    // Calculate diameter using brute-force method
    cout << "Diameter of the binary tree (Brute-force): " << diameterBrute(root) << endl;

    // Calculate diameter using optimized method
    cout << "Diameter of the binary tree (Optimized): " << diameterOfBinaryTree(root) << endl;

    return 0;
}

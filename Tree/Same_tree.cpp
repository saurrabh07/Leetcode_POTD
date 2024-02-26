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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        if (!p || !q)
            return false;
        if(p->val == q->val)
            return isSameTree(p->left , q->left) && isSameTree(p->right , q->right);
        else
            return false;
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
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        cout << "Enter left child value of " << curr->val << " (or -1 for NULL): ";
        cin >> val;
        if (val != -1) {
            curr->left = new TreeNode(val);
            q.push(curr->left);
        }
        cout << "Enter right child value of " << curr->val << " (or -1 for NULL): ";
        cin >> val;
        if (val != -1) {
            curr->right = new TreeNode(val);
            q.push(curr->right);
        }
    }
    return root;
}

int main() {
    Solution sol;
    
    // Creating the first tree
    cout << "Enter values for the first tree:\n";
    TreeNode* p = createTree();
    
    // Creating the second tree
    cout << "Enter values for the second tree:\n";
    TreeNode* q = createTree();
    
    // Checking if the trees are the same
    if (sol.isSameTree(p, q))
        cout << "The trees are the same.\n";
    else
        cout << "The trees are not the same.\n";
    
    return 0;
}

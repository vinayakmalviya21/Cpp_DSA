#include <iostream>
#include <vector>
using namespace std;

// Definition of a binary tree node
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void solve(TreeNode* root, int targetSum, int currSum, vector<int>& path, vector<vector<int>>& ans) {
    if (root == NULL) {
        return;
    }
    // Add the current node to the path
    path.push_back(root->val);
    currSum += root->val;

    // If the current node is a leaf and the current sum equals the target sum, add the path to the answer
    if (root->left == NULL && root->right == NULL && currSum == targetSum) {
        ans.push_back(path);
    }

    // Recursively explore left and right subtrees
    solve(root->left, targetSum, currSum, path, ans);
    solve(root->right, targetSum, currSum, path, ans);

    // Remove the current node from the path before returning from the recursive call
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> ans;
    vector<int> path;
    solve(root, targetSum, 0, path, ans);
    return ans;
}

// Function to deallocate memory used by the binary tree
void deleteTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;
    vector<vector<int>> result = pathSum(root, targetSum);

    // Print the paths with target sum
    cout << "Paths with sum " << targetSum << ":" << endl;
    for (const vector<int>& path : result) {
        cout << "[ ";
        for (int val : path) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }

    // Deallocate memory used by the binary tree
    deleteTree(root);

    return 0;
}

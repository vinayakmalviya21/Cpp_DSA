#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int countPaths(TreeNode* root, int targetSum) {
    if (root == nullptr)
        return 0;

    // Count the number of paths starting from the current node
    int pathsFromNode = 0;

    // Check if the current node itself forms a path with the target sum
    if (root->val == targetSum)
        pathsFromNode++;

    // Recursively count paths from the left and right subtrees
    pathsFromNode += countPaths(root->left, targetSum - root->val);
    pathsFromNode += countPaths(root->right, targetSum - root->val);

    return pathsFromNode;
}


int kSumPath(TreeNode* root, int targetSum) {
    if (root == nullptr)
        return 0;

    // Recursive function to count paths starting from the current node
    int pathsFromRoot = countPaths(root, targetSum);

    // Recursively count paths starting from left and right subtrees
    int pathsFromLeft = kSumPath(root->left, targetSum);
    int pathsFromRight = kSumPath(root->right, targetSum);

    // Total number of paths in the entire tree
    return pathsFromRoot + pathsFromLeft + pathsFromRight;
}

int main()
{

    // * K Sum Path
    // ! Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
    // ! The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    int targetSum = 8;

    // * Calculate the number of paths with the given target sum
    int paths = kSumPath(root, targetSum);
    cout << "Number of paths with sum " << targetSum << ": " << paths << endl;

    delete root->left->left->left;
    delete root->left->left->right;
    delete root->left->left;
    delete root->left->right->right;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;


    return 0;
}
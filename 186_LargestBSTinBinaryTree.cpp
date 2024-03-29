#include <iostream>
#include <climits>
using namespace std;

// ! Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ! Structure to store information about each subtree
struct NodeData
{
    int size;   // Size of the subtree
    int minVal; // Minimum value in the subtree
    int maxVal; // Maximum value in the subtree
    bool isBST; // Whether the subtree is a BST or not
    NodeData(int s, int minV, int maxV, bool bst) : size(s), minVal(minV), maxVal(maxV), isBST(bst) {}
};

NodeData *findLargestBST(TreeNode *root, int &ans)
{
    if (root == nullptr)
    {
        return new NodeData(0, INT_MAX, INT_MIN, true);
    }

    // ! Postorder traversal to process subtrees before the root
    NodeData *leftData = findLargestBST(root->left, ans);
    NodeData *rightData = findLargestBST(root->right, ans);

    // ! Check if the current subtree rooted at 'root' is a BST
    bool isBSTHere = (root->val > leftData->maxVal && root->val < rightData->minVal && leftData->isBST && rightData->isBST);

    // ! If the current subtree is a BST, update the answer
    if (isBSTHere)
    {
        int sizeHere = leftData->size + 1 + rightData->size;
        ans = max(ans, sizeHere);
    }

    // ! Construct data for the current subtree
    int minVal = min(root->val, min(leftData->minVal, rightData->minVal));
    int maxVal = max(root->val, max(leftData->maxVal, rightData->maxVal));
    NodeData *currentData = new NodeData(isBSTHere ? leftData->size + 1 + rightData->size : 0,minVal, maxVal, isBSTHere);

    return currentData;
}

int largestBSTSubtree(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int ans = 0;
    findLargestBST(root, ans);
    return ans;
}

int main()
{

    // * Largest BST in Binary Tree

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);

    cout << "Size of the largest BST subtree: " << largestBSTSubtree(root) << endl;

    return 0;
}

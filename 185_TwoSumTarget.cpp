#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void storeInorder(TreeNode* root, vector<int> &inorder) {
    if(root == nullptr) {
        return;
    }
    storeInorder(root->left, inorder);
    inorder.push_back(root->val);
    storeInorder(root->right, inorder);
}

bool findTarget(TreeNode* root, int k) {
    vector<int> inorder;
    storeInorder(root, inorder);

    int s = 0;
    int e = inorder.size() - 1;

    while(s < e) {
        int sum = inorder[s] + inorder[e];

        if(sum == k) return true;

        if(sum > k) e--;
        else  s++;
    }
    return false;
}

// Function to deallocate memory used by the tree
void deleteTree(TreeNode* root) {
    if(root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {

    // * Two Sum Target

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int k = 9; // ! Target sum

    bool found = findTarget(root, k);
    if(found)
        cout << "There exist two elements in the BST that sum up to " << k << endl;
    else
        cout << "There doesn't exist two elements in the BST that sum up to " << k << endl;

    // Deallocate memory used by the tree
    deleteTree(root);

    return 0;
}

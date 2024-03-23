#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int D = 0;

int height(node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int currD = leftHeight + rightHeight;
    D = max(D, currD);

    int ans = max(leftHeight, rightHeight) + 1;
    return ans;
}

int diameterOfBinaryTree(node* root) {
    height(root);
    return D;
}

int main() {

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    root->left->right->left = new node(7);
    root->left->right->right = new node(8);

    // * Calculate and print the diameter of the binary tree
    cout << "Diameter of the binary tree: " << diameterOfBinaryTree(root) << endl;

    delete root->left->right->left;
    delete root->left->right->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}

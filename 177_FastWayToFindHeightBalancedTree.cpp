#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isBalanced = true;

int height(node* root) {
    if (root == nullptr) {
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    if (isBalanced && abs(lh - rh) > 1) {
        isBalanced = false;
    }

    return max(lh, rh) + 1;
}

bool isTreeBalanced(node* root) {
    height(root);
    return isBalanced;
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

    // * Check whether the binary tree is balanced or not
    if (isTreeBalanced(root)) {
        cout << "The binary tree is balanced." << endl;
    } else {
        cout << "The binary tree is not balanced." << endl;
    }

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

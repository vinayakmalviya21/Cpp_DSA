#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

bool solve(Node* root, long long int lb, long long int ub) {
    if(root == NULL) {
        return true;
    }

    if(root->val > lb && root->val < ub) {
        bool leftAns = solve(root->left, lb, root->val);
        bool rightAns = solve(root->right, root->val, ub);
        return leftAns && rightAns;
    }
    else {
        return false;
    }
}

bool isValidBST(Node* root) {
    long long int lowerBound = -4294967296; // INT_MIN
    long long int upperBound = 4294967296;  // INT_MAX
    bool ans = solve(root, lowerBound, upperBound);
    return ans;
}

// Function to deallocate memory used by the tree
void deleteTree(Node* root) {
    if(root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {

    // * Validate BST

    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);

    cout << "Is the tree a valid BST? " << (isValidBST(root) ? "Yes" : "No") << endl;

    // Deallocate memory used by the tree
    deleteTree(root);

    return 0;
}

#include <iostream>
using namespace std;

class node {
public:
    int val;
    node* left;
    node* right;

    node(int v) {
        val = v;
        left = NULL;
        right = NULL;
    }
};

node* lowestCommonAncestor(node* root, node* p, node* q) {
    if(root == NULL) {
        return NULL;
    }

    if(root->val == p->val)
        return p;
    if(root->val == q->val)
        return q;

    node* leftAns = lowestCommonAncestor(root->left, p, q);
    node* rightAns = lowestCommonAncestor(root->right, p, q);

    if(leftAns == NULL && rightAns == NULL) {
        return NULL;
    }
    else if(leftAns != NULL && rightAns == NULL) {
        return leftAns;
    }
    else if(leftAns == NULL && rightAns != NULL) {
        return rightAns;
    }
    else {
        return root;
    }
}

int main() {
    // Creating the tree
    node* root = new node(3);
    root->left = new node(5);
    root->right = new node(1);
    root->left->left = new node(6);
    root->left->right = new node(2);
    root->right->left = new node(0);
    root->right->right = new node(8);
    root->left->right->left = new node(7);
    root->left->right->right = new node(4);

    // Nodes for which we need to find the lowest common ancestor
    node* p = root->left;
    node* q = root->right;

    // * Finding lowest common ancestor
    node* lca = lowestCommonAncestor(root, p, q);

    // Displaying the result
    if(lca != NULL) {
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    }
    else {
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " doesn't exist." << endl;
    }

    return 0;
}

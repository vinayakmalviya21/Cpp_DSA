#include<iostream>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;
    node(int x) : val(x), left(NULL), right(NULL) {}
};

bool isMirror(node* p, node* q) {
    if (!p && !q)
        return true;

    if (p && q) {
        return (p->val == q->val)
            && isMirror(p->left, q->right)
            && isMirror(p->right, q->left);
    }
    return false;
}

bool isSymmetric(node* root) {
        return isMirror(root->left,root->right);
}

int main() {

    node* tree1 = new node(1);
    tree1->left = new node(2);
    tree1->right = new node(3);

    // * Check if the two trees are symmetric
    // ! check whether it is a mirror of itself (i.e., symmetric around its center)

    if (isSymmetric(tree1)) {
        cout << "The trees are symmetric." << endl;
    } else {
        cout << "The trees are not symmetric." << endl;
    }

    delete tree1->left;
    delete tree1->right;
    delete tree1;

    return 0;
}

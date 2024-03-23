#include<iostream>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;
    node(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(node* p, node* q) {
    if (!p && !q)
        return true;

    if (p && q) {
        return (p->val == q->val)
            && isSameTree(p->left, q->left)
            && isSameTree(p->right, q->right);
    }
    return false;
}

int main() {

    node* tree1 = new node(1);
    tree1->left = new node(2);
    tree1->right = new node(3);

    node* tree2 = new node(1);
    tree2->left = new node(2);
    tree2->right = new node(3);

    // * Check if the two trees are identical
    if (isSameTree(tree1, tree2)) {
        cout << "The trees are identical." << endl;
    } else {
        cout << "The trees are not identical." << endl;
    }

    delete tree1->left;
    delete tree1->right;
    delete tree1;
    delete tree2->left;
    delete tree2->right;
    delete tree2;

    return 0;
}

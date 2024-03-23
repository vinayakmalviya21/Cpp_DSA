#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;
    node(int x) : val(x), left(NULL), right(NULL) {}
};

void zigzagTraversal(node* root) {
    if (root == nullptr)
        return;

    // Create a stack to store nodes of current level
    stack<node*> currentLevel;
    // Create a stack to store nodes of next level
    stack<node*> nextLevel;

    // Push the root node to the current level stack
    currentLevel.push(root);

    // Variable to track the order of traversal (left to right or right to left)
    bool leftToRight = true;

    while (!currentLevel.empty()) {
        // Get the top node from the current level stack
        node* current = currentLevel.top();
        currentLevel.pop();

        if (current) {
            // Print the value of the current node
            cout << current->val << " ";

            // For zigzag traversal, we push nodes to the next level stack in opposite order
            if (leftToRight) {
                if (current->left)
                    nextLevel.push(current->left);
                if (current->right)
                    nextLevel.push(current->right);
            } else {
                if (current->right)
                    nextLevel.push(current->right);
                if (current->left)
                    nextLevel.push(current->left);
            }
        }

        // If the current level stack becomes empty, swap the current level stack with the next level stack
        if (currentLevel.empty()) {
            swap(currentLevel, nextLevel);
            // Toggle the direction for the next level traversal
            leftToRight = !leftToRight;
        }
    }
}

int main() {

    node* tree1 = new node(8);
    tree1->left = new node(3);
    tree1->right = new node(10);
    tree1->left->left = new node(1);
    tree1->left->right = new node(6);
    tree1->right->right = new node(14);
    tree1->left->right->left = new node(4);
    tree1->left->right->right = new node(7);
    tree1->right->right->left = new node(13);

    cout << "Zigzag Traversal of the tree:" << endl;
    zigzagTraversal(tree1);
    cout << endl;

    delete tree1->left->right->left;
    delete tree1->left->right->right;
    delete tree1->left->right;
    delete tree1->left->left;
    delete tree1->left;
    delete tree1->right->right->left;
    delete tree1->right->right;
    delete tree1->right;
    delete tree1;

    return 0;
}

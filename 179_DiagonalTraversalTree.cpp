#include <iostream>
#include <queue>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;
    node(int x) : val(x), left(NULL), right(NULL) {}
};

void diagonalTraversal(node* root) {
    if (root == nullptr)
        return;

    // Create a queue to store nodes of current diagonal
    queue<node*> q;

    // Enqueue the root node
    q.push(root);

    while (!q.empty()) {
        // Get the current node
        node* current = q.front();
        q.pop();

        // Traverse the current diagonal
        while (current) {
            // Print the value of the current node
            cout << current->val << " ";

            // If there is a left child, add it to the queue
            if (current->left)
                q.push(current->left);

            // Move to the right child of the current node
            current = current->right;
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

    cout << "Diagonal Traversal of the tree:" << endl;
    diagonalTraversal(tree1);
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

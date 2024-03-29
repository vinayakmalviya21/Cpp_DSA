#include <iostream>
using namespace std;

// Definition for a linked list node.
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* sortedListToBST(Node* &head, int n) {
    if (n <= 0 || head == nullptr) {
        return nullptr;
    }

    TreeNode* leftSubtree = sortedListToBST(head, n - 1 - n/2);

    TreeNode* root = new TreeNode(head->data);
    root->left = leftSubtree;

    head = head->next;

    root->right = sortedListToBST(head, n/2);

    return root;
}

// Inorder traversal to print the BST
void printBST(TreeNode* root) {
    if (root == nullptr)
        return;
    printBST(root->left);
    cout << root->val << " ";
    printBST(root->right);
}

int main() {

    // * Sorted list to BST
    
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    TreeNode* root = sortedListToBST(head, 5); // Assuming 5 elements in the list

    // Traverse and print the BST
    cout << "Elements of the BST: ";
    printBST(root);
    cout << endl;

    return 0;
}

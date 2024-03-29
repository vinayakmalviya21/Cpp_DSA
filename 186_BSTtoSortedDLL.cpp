#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Definition for a doubly-linked list node.
struct ListNode {
    int val;
    ListNode* prev;
    ListNode* next;
    ListNode(int x) : val(x), prev(NULL), next(NULL) {}
};

void BSTToDLL(TreeNode* root, TreeNode* &head) {
    if (!root)
        return;

    // Right subtree into DLL
    BSTToDLL(root->right, head); 

    // Attach root node
    root->right = head;

    if (head != NULL) {
        head->left = root;
    }

    // Update head
    head = root;

    // Left subtree into DLL
    BSTToDLL(root->left, head); 
}

int main() {
    
    // * Convert BST into Sorted DLL

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    TreeNode* head = NULL;
    BSTToDLL(root, head);

    TreeNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->right;
    }

    return 0;
}

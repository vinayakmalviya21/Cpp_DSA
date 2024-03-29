#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (p->val < root->val && q->val < root->val)
    {
        return lowestCommonAncestor(root->left, p, q);
    }

    if (p->val > root->val && q->val > root->val)
    {
        return lowestCommonAncestor(root->right, p, q);
    }

    return root;
}

int main()
{

    // * Lowest Common Ancestor

    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode *p = root->left->left;         // Node with value 0
    TreeNode *q = root->left->right->right; // Node with value 5

    TreeNode *lca = lowestCommonAncestor(root, p, q);
    if (lca != NULL)
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    else
        cout << "No common ancestor found." << endl;

    // Deallocate memory used by the tree
    delete root->right->right;
    delete root->right->left;
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}

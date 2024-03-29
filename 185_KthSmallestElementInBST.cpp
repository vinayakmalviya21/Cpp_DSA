#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int kthSmallest(TreeNode *root, int k)
{
   if(root == nullptr || k <= 0)
            return -1; // Return -1 for invalid input or if k is not valid

        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(curr != nullptr || !st.empty()) {
            while(curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            k--;
            if(k == 0)
                return curr->val;

            curr = curr->right;
        }

        return -1; // If k exceeds the number of elements in the tree
}

int main()
{

    // * Kth smallest element

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    int k = 1; // kth smallest element to find

    int kthSmallestElement = kthSmallest(root, k);
    cout << "The " << k << "th smallest element is: " << kthSmallestElement << endl;

    // Deallocate memory used by the tree
    delete root->left->right;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}

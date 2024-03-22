#include <iostream>
#include <queue>
using namespace std;

// ! Definition of a node in the binary tree
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// ! Function to build tree
node *buildTree(node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left: " << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right: " << endl;
    root->right = buildTree(root->right);

    return root;
}

int height(node* root){
        if(root == NULL){
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int ans = 1 + max(leftHeight,rightHeight);
        return ans;
    }

    bool isBalanced(node* root) {
        if(root == NULL){
            return true;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diff = abs(leftHeight - rightHeight);

        bool ans1 = (diff <= 1);

        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);

        if(ans1 && leftAns && rightAns){
            return true;
        }
        else{
            return false;
        }
    }

int main()
{
    // * Balanced Binary Tree
    // ! each node pr left subtree and right subtree ,height ka absolute difference <= 1 hona chahiye

    node *root = NULL;

    // ! Creating a tree
    root = buildTree(root);

    //      3
    //   9     20
    //       15   7

    if(isBalanced(root)){
        cout<<"Balanced Binary Tree"<<endl;
    }
    else{
        cout<<"Not Balanced Binary Tree"<<endl;
    }

    return 0;
}

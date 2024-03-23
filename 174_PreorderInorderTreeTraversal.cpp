#include <iostream>
#include <queue>
using namespace std;

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

// Function to find the position of an element in an array
int findPosition(int arr[], int n, int element)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

// Build tree from inorder and preorder traversal
node *buildTreeFromPreorderInorder(int inorder[], int preorder[], int size, int &preIndex, int inorderStart, int inorderEnd)
{
    if (preIndex >= size || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = preorder[preIndex++];
    node *root = new node(element);
    int pos = findPosition(inorder, size, element);

    root->left = buildTreeFromPreorderInorder(inorder, preorder, size, preIndex, inorderStart, pos - 1);

    root->right = buildTreeFromPreorderInorder(inorder, preorder, size, preIndex, pos + 1, inorderEnd);

    return root;
}


void levelOrderTraversal(node *root)
{
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            node *current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
        cout << endl;
    }
}

int main()
{
    int inorder[] = {4, 2, 5, 1, 6, 3};
    int preorder[] = {1, 2, 4, 5, 3, 6};
    int size = sizeof(inorder) / sizeof(inorder[0]);
    int preIndex = 0;

    node *root = buildTreeFromPreorderInorder(inorder, preorder, size, preIndex, 0, size - 1);

    cout << "Tree in the required format:" << endl;
    levelOrderTraversal(root);

    return 0;
}

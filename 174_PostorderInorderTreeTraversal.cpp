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

// Build tree from inorder and postorder traversal
node *buildTreeFromInorderPostorder(int inorder[], int postorder[], int size, int &postIndex, int inorderStart, int inorderEnd)
{
    if (postIndex < 0 || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = postorder[postIndex--];
    node *root = new node(element);
    int pos = findPosition(inorder, size, element);

    root->right = buildTreeFromInorderPostorder(inorder, postorder, size, postIndex, pos + 1, inorderEnd);
    root->left = buildTreeFromInorderPostorder(inorder, postorder, size, postIndex, inorderStart, pos - 1);

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
    int postorder[] = {4, 5, 2, 6, 3, 1};
    int size = sizeof(inorder) / sizeof(inorder[0]);
    int postIndex = size - 1;

    node *root = buildTreeFromInorderPostorder(inorder, postorder, size, postIndex, 0, size - 1);

    cout << "Tree in the required format:" << endl;
    levelOrderTraversal(root);

    return 0;
}

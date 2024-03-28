#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        // This is the first node we have to create
        root = new Node(data);
        return root;
    }

    if (root->data > data)
    {
        // Insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        // Insert in right
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

Node *findNodeInBST(Node *root, int target)
{
    // Base case
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == target)
    {
        return root;
    }

    if (target > root->data)
    {
        return findNodeInBST(root->right, target);
    }
    else
    {
        return findNodeInBST(root->left, target);
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL); // Pushing NULL to indicate the end of the current level

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL); // Pushing NULL to indicate the end of the next level
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int maxVal(Node *root)
{
    Node *temp = root;
    if (temp == NULL)
    {
        return -1;
    }

    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

Node *deleteNodeInBST(Node *root, int target)
{
    // Base case
    if (root == NULL)
    {
        return root;
    }

    // Find the node to be deleted
    if (target < root->data)
    {
        root->left = deleteNodeInBST(root->left, target);
    }
    else if (target > root->data)
    {
        root->right = deleteNodeInBST(root->right, target);
    }
    else
    {
        // Node with given value found
        // Case 1: Node is a leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // Case 2: Node has only one child
        else if (root->left == NULL)
        {
            Node *child = root->right;
            delete root;
            return child;
        }
        else if (root->right == NULL)
        {
            Node *child = root->left;
            delete root;
            return child;
        }

        // Case 3: Node has two children
        else
        {
            // Find the maximum value in the left subtree
            root->data = maxVal(root->left);
            // Delete the maximum value node from the left subtree
            root->left = deleteNodeInBST(root->left, root->data);
        }
    }
    return root;
}

int main()
{
    Node *root = NULL;
    cout << "Enter data for Node " << endl;
    takeInput(root);
    // Input: 100 50 150 40 60 175 110 -1
    cout << "Printing the tree: " << endl;
    levelOrderTraversal(root);

    deleteNodeInBST(root, 100);

    cout << "Printing the tree after deletion: " << endl;
    levelOrderTraversal(root);

    return 0;
}

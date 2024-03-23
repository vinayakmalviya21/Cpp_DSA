#include <iostream>
#include <queue>
#include <map>
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

// Function to build tree
node *buildTree(node *root)
{
    cout << "Enter the data (Enter -1 for NULL): ";
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new node(data);

    cout << "Enter data for the left child of " << data << ": ";
    root->left = buildTree(root->left);

    cout << "Enter data for the right child of " << data << ": ";
    root->right = buildTree(root->right);

    return root;
}

void printLeftView(node *root)
{
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        // Get the number of nodes at the current level
        int size = q.size();

        // Iterate over all nodes at the current level
        for (int i = 0; i < size; i++)
        {
            node *current = q.front();
            q.pop();

            // Print the first node encountered at each level
            if (i == 0)
                cout << current->data << " ";

            // Enqueue left child if exists
            if (current->left)
                q.push(current->left);
            
            // Enqueue right child if exists
            if (current->right)
                q.push(current->right);
        }
    }
}

int main()
{
    node *root = NULL;
    root = buildTree(root);

    cout << "Left view of the tree: " << endl;
    printLeftView(root);

    return 0;
}

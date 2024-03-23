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

void printTopView(node *root)
{
    if (root == NULL)
        return;

    // Create map for storing Horizontal distance -> Topnode -> data
    map<int, int> topNode;

    queue<pair<node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();

        node *frontNode = temp.first;
        int hd = temp.second;

        if (topNode.find(hd) == topNode.end())
        {
            topNode[hd] = frontNode->data;
        }

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    cout << "Top view of the tree: " << endl;
    for (auto i : topNode)
    {
        cout << i.second << " ";
    }
}

int main()
{
    node *root = NULL;
    root = buildTree(root);

    printTopView(root);

    return 0;
}

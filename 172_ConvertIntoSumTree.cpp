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

int convertIntoSumTree(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftSum = convertIntoSumTree(root->left);
    int rightSum = convertIntoSumTree(root->right);

    int currentData = root->data;
    root->data = leftSum + rightSum + currentData;

    return root->data;
}

void printLevelOrder(node *root)
{
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            node *curr = q.front();
            q.pop();

            if (curr != NULL)
            {
                cout << curr->data << " ";

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            else
            {
                cout << "NULL ";
            }
        }

        cout << endl;
    }
}

int main()
{
    node *root = NULL;

    // ! Creating a tree
    root = buildTree(root);

    //        10
    //    20       30
    // 10   50   20   40

    // 10  20  10  -1 -1 50 -1 -1 30 20 -1 -1 40 -1 -1

    //        180
    //    80       90
    // 10   50   20   40

    cout << "Original tree (level-order traversal):" << endl;
    printLevelOrder(root);

    convertIntoSumTree(root);

    cout << "Sum tree (level-order traversal):" << endl;
    printLevelOrder(root);

    return 0;
}

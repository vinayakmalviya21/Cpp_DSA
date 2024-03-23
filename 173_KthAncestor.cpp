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

bool kthAncestor(node* root,int k,int p){
    if(root == NULL){
        return false;
    }

    if(root->data == p){
        return true;
    }

    // if (k==0)
    // {
    //     return false;
    // }
    

    bool leftAns = kthAncestor(root->left,k,p);
    bool rightAns = kthAncestor(root->right,k,p);

    if(leftAns || rightAns){
        k--;
    }
    if(k==0){
        cout<<"Answer is: "<< root->data<<endl;
        return false;
    }

    return leftAns || rightAns;
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
    int k=1,p=4;

    //       1
    //    2      3
    //  4   5

    // 1 2 4 -1 -1 5 -1 -1 3 -1 -1

    cout << "Original tree (level-order traversal):" << endl;
    printLevelOrder(root);

    bool found = kthAncestor(root,k,p);

    

    return 0;
}

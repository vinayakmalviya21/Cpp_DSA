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

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL); // Pushing NULL to indicate the end of the current level

    while (!q.empty())
    {
        node *temp = q.front();
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

void inorder(node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    // * Tree is non-linear data structure

    node *root = NULL;

    // ! Creating a tree
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<"Printing level order traversal output: "<<endl;

    // ! level order
    levelOrderTraversal(root);


    //         1
    //     3       5
    //   7   11  17  -1

    // * Inorder traversing (LNR)
    // 7 3 11 1 17 5
    cout<<"Inorder traversal is: ";
    inorder(root);

    // * Preorder traversing (NLR)
    // 1 3  7 11 5 17
    cout<<endl<<"Preorder traversal is: ";
    preorder(root);

    // * Postorder traversing (LRN)
    // 7 11 3 17 5 1
    cout<<endl<<"Postorder traversal is: ";
   postorder(root);

    return 0;
}

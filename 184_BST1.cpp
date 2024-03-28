#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root,int data){
    if(root == NULL){
        // This is first node we have to create
        root = new Node(data);
        return root;
    }

    if(root->data > data){
        // Insert in left
        root->left = insertIntoBST(root->left,data);
    }
    else{
        // Insert in right
        root->right = insertIntoBST(root->right,data);
    }
    return root;
}

void takeInput(Node* & root){
    int data;
    cin>>data;
    while(data!=-1){
        root = insertIntoBST(root,data);
        cin>>data;
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

int main()
{
    // * BST - 1
    // ! Binary Search Tree
    // ~ Conditions for BST, for every Node:-
    // ~ root->data > (left subtree data)
    // ~ root->data < (rightt subtree data)

    // ! Inorder of BST is always sorted

    Node* root = NULL;
    cout<<"Enter data for Node "<<endl;
    takeInput(root);
    cout<<"Printing the tree: "<<endl;
    levelOrderTraversal(root);

    return 0;
}
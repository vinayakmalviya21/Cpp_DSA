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

// ! Assuming unique values in tree
bool findNodeInBST(Node* root,int target){
    // base case
    if(root == NULL){
        return false;
    }

    if(root->data == target){
        return true;
    }

    if(target > root->data){
        return findNodeInBST(root->right,target);
    }
    else{
        return findNodeInBST(root->left,target);
    }
}

int main()
{
    // * Searching in BST 

    Node* root = NULL;
    cout<<"Enter data for Node "<<endl;
    takeInput(root);
    cout<<"Printing the tree: "<<endl;
    levelOrderTraversal(root);

    bool ans = findNodeInBST(root,30);
    cout<<"Present or not: "<<ans<<endl;

    return 0;
}
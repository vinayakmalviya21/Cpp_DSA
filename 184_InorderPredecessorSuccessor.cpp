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

void findPredecessorAndSuccessor(Node* root, Node*& pred, Node*& succ, int key) {
    if (root == NULL)
        return;

    // If key is found in root
    if (root->data == key) {
        // Find predecessor if left subtree exists
        if (root->left) {
            Node* temp = root->left;
            while (temp->right)
                temp = temp->right;
            pred = temp;
        }

        // Find successor if right subtree exists
        if (root->right) {
            Node* temp = root->right;
            while (temp->left)
                temp = temp->left;
            succ = temp;
        }
        return;
    }

    // If key is smaller than root's key, then it lies in left subtree
    if (root->data > key) {
        succ = root; // Update successor
        findPredecessorAndSuccessor(root->left, pred, succ, key);
    }
    // If key is greater than root's key, then it lies in right subtree
    else {
        pred = root; // Update predecessor
        findPredecessorAndSuccessor(root->right, pred, succ, key);
    }
}


int main()
{
    // * Inorder Predecessor/Successor in BST 
    // ! Inorder Predecessor is left subtree ka max value
    // ! Inorder Successor is right subtree ka min value

    Node* root = NULL;
    cout<<"Enter data for Node "<<endl;
    takeInput(root);
    cout<<"Printing the tree: "<<endl;
    levelOrderTraversal(root);

    int key = 11;

    Node* predecessor = NULL;
    Node* successor = NULL;
    findPredecessorAndSuccessor(root, predecessor, successor, key);

    if (predecessor)
        cout << "Predecessor of " << key << " is " << predecessor->data << endl;
    else
        cout << "No predecessor found for " << key << endl;

    if (successor)
        cout << "Successor of " << key << " is " << successor->data << endl;
    else
        cout << "No successor found for " << key << endl;

    return 0;
}
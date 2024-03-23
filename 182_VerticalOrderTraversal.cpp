#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;

    map<pair<int,int>, vector<int>> mp;
    queue<pair<TreeNode*, pair<int,int>>> q;
    q.push({root, {0, 0}}); //{row, col}

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            pair<TreeNode*, pair<int,int>> curr = q.front();
            q.pop();
            int row = curr.second.first;
            int col = curr.second.second;
            mp[{row, col}].push_back(curr.first->val);
            if (curr.first->left != nullptr)
                q.push({curr.first->left, {row + 1, col - 1}});
            if (curr.first->right != nullptr)
                q.push({curr.first->right, {row + 1, col + 1}});
        }
    }

    for (auto& x: mp) {
        sort(x.second.begin(), x.second.end());
    }

    map<int, vector<int>> mp1;
    for (auto x: mp) {
        for (int val: x.second) {
            mp1[x.first.second].push_back(val);
        }
    }

    for (auto& col: mp1) {
        ans.push_back(col.second);
    }

    return ans;
}

int main() {

    // ! The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

    TreeNode* tree1 = new TreeNode(8);
    tree1->left = new TreeNode(3);
    tree1->right = new TreeNode(10);
    tree1->left->left = new TreeNode(1);
    tree1->left->right = new TreeNode(6);
    tree1->right->right = new TreeNode(14);
    tree1->left->right->left = new TreeNode(4);
    tree1->left->right->right = new TreeNode(7);
    tree1->right->right->left = new TreeNode(13);

    cout << "Vertical Order Traversal of the tree:" << endl;
    vector<vector<int>> result = verticalTraversal(tree1);
    for (const auto& col : result) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    delete tree1->left->right->left;
    delete tree1->left->right->right;
    delete tree1->left->right;
    delete tree1->left->left;
    delete tree1->left;
    delete tree1->right->right->left;
    delete tree1->right->right;
    delete tree1->right;
    delete tree1;

    return 0;
}

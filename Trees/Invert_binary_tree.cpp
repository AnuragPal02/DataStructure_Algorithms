
//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        // flip the left and right node of the particular root
        // for every node just flip the childs
       if(root==NULL) return root;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

         root->left = right;
         root->right = left;
         return root;
    }
};

// BFS approach 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // BFS approach 
        if(root==NULL) return root;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* temp = que.front();
            que.pop();

            TreeNode* u = temp->left;
            temp->left = temp->right;
            temp->right = u;

            if(temp->left) que.push(temp->left);
            if(temp->right) que.push(temp->right);
        }
        return root;
    }
};
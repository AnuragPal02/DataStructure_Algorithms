//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// } Driver Code Ends
class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool solve(Node* root,int min,int max){
        
        if(root==NULL) return true;
        
        if(root->data < min || root->data > max ){
            return false;
        }
        
        return solve(root->left,min,root->data)
                     && solve(root->right,root->data+1,max);
    }
    bool isBST(Node* root) {
       return solve(root,INT_MIN,INT_MAX);
        
    }
};

// using stack or dfs
bool isBST(Node* root) {
        // finding whether a tree is bst or not using stack 
        
        stack<pair<Node*,pair<int,int>>> st;
        st.push({root,{INT_MIN,INT_MAX}});
        while(!st.empty()){
            auto top =  st.top();
            Node* node = top.first;
            auto range = top.second;
            st.pop();
            int min = range.first;
            int max = range.second;
            
            if(node->data < min || node->data > max)return false;
            
            if(node->left) st.push({node->left,{min,node->data}});
            if(node->right) st.push({node->right,{node->data+1,max}});
        }
   return true;
    }
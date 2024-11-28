#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
  vector<int> result;
   void solve(Node* root,int level, unordered_map<int,int>&mp){
       
       if(root==nullptr){
           return;
       }
       //push into result if the level is encountered for the first time 
       if(mp.find(level)==mp.end()){
           result.push_back(root->data);
           mp[level]++;
       }
       solve(root->left,level+1,mp);
       solve(root->right,level+1,mp);
   }
    vector<int> leftView(Node *root) {
        unordered_map <int,int> mp;
        solve(root,1,mp);
        return result;
    }
};
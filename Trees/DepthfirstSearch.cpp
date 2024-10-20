
#include<bits/stdc++.h>

#define int long long
using namespace std;
 
 class Node{
    public:
    char val;
    Node* left;
    Node* right;

    Node(char val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
 };

 int main(){
    Node obj('a');
    Node obj('b');
    Node obj('c');
    Node obj('d');
    Node obj('e');
    Node obj('d');

    
 }

 // The iterative one 
void solve(Node* root)
{
    if(root==NULL) return;

    vector<char> arr;
    stack<Node*>st;
    
    st.push(root);
    while(!st.empty()){
        Node *top = st.top();
        st.pop();
        arr.push_back(top->val);
        if(top->right) st.push(top->right);
        if(top->left) st.push(top->left);
 
    }
}

// Recursive one

void solve_recursivley(Node* root){
   // First edge case is check whether root exists or not
   if(!root)return;
   cout<<root->val<<" ";
   if(root->left) solve(root->left);
   if(root->right) solve(root->right);
}
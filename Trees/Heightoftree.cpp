class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;

        int left_count = 1 +  maxDepth(root->left);
        int right_count = 1 + maxDepth(root->right);
        return max(left_count,right_count);
    }
};


int leveorder_traversal(TreeNode *root){
    queue<TreeNode*> que;

    que.push(root);
    while(!que.empty()){
        TreeNode *node = que.front();
        que.pop();
        
    }
}
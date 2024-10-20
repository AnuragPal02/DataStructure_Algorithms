
int arr[100000];

int* inOrder(struct Node* root) {
    // code here
    int k = 0;
    struct Node* curr = root;
    while(curr != NULL){
        if(curr->left != NULL){
           struct Node* leftchild = curr->left;
            while(leftchild->right != NULL){
                leftchild = leftchild->right;
            }
            
            leftchild->right = curr;
            struct Node* temp = curr;
            curr = curr->left;
            temp->left = NULL;
        }else{
            arr[k++] = curr->data; 
            curr = curr->right;
        }
    }
    return arr; // do not change the default values(i.e -1) in the unused array
                // indices.
}

//{ Driver Code Starts.

https://practice.geeksforgeeks.org/problems/search-a-node-in-bst/1

bool search(Node* root, int x) {
    // Your code here
    
    if(root==NULL)return false;
    
    if(root->data==x)return true;
    
    bool left=0,right=0;
    
    if(x < root->data)left = search(root->left,x);
    else right = search(root->right,x);
    
    return left||right;
}

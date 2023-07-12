https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1

void find(Node*root, int&val){
    
    if(root==NULL)return;
    
    
    find(root->left,val);
    
    val = min(val,root->data);
    
    
    
}

int minValue(Node* root) {
    // Code here
    
    int val = INT_MAX;
    find(root,val);
    
    if(val==INT_MAX)return -1;
    
    return val;
}

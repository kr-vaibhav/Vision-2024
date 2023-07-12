https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1

Node *deleteNode(Node *root, int X) {
    // your code goes here
    
    if(root==NULL)return root;
    
    if(root->data < X) root->right = deleteNode(root->right,X);
    else if(root->data > X) root->left = deleteNode(root->left,X);
    else{
        
        if(!root->left && !root->right)return NULL;
        else if(!root->left)return root->right;
        else if(!root->right)return root->left;
        else{
            
            Node* temp = root->left;
            
            while(temp->right)temp=temp->right;
            
            temp->right = root->right;
            
            temp=root->left;
            
            delete root;
            
            return temp;
            
        }
        
    }
    
    return root;
}

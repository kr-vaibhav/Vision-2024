https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1

Node* insert(Node* root, int Key) {
    // Your code here
    Node*curr=root;
    Node*prev=NULL;
    
    while(curr){
        
        if(curr->data==Key)return root;
        else if(curr->data > Key){
            
            prev = curr;
            curr=curr->left;
        }
        else{
            prev = curr;
            curr=curr->right;
        }
    }
    
    struct Node* temp =new Node(Key);
    
    if(prev->data > Key) prev->left = temp;
    else prev->right = temp;
    
    return root;
}

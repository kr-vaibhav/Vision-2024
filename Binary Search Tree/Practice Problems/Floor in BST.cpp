https://practice.geeksforgeeks.org/problems/floor-in-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-bst

int floor(Node* root, int x) {
    // Code here
    int ans = -1;
    
    Node*curr = root;
    
    while(curr){
        
        if(curr->data<=x){
            
            ans = curr->data;
            curr=curr->right;
        }
        else curr=curr->left;
    }
    
    return ans;
}

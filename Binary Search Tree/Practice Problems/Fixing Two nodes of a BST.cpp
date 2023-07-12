https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=fixed-two-nodes-of-a-bst


class Solution {
    private:
    
        struct Node*first = NULL;
        struct Node*middle = NULL;
        struct Node*last = NULL;
        struct Node*prev = NULL;
    
    void solve( struct Node*root){
        
        if(root==NULL)return;
        
        
        solve(root->left);
        
        if(prev!=NULL && prev->data > root->data){
            
            if(first==NULL){
                
                first = prev;
                middle = root;
            }
            else{
                
                last = root;
            }
        }
        
        prev = root;
        
        solve(root->right);
    }
  public:
    void correctBST( struct Node* root )
    {
        // add code here.
        
        first=NULL,middle=NULL,last=NULL,prev=NULL;
        
        solve(root);
        
        if(first&&last){
            
            swap(first->data,last->data);
        }
        else if(first&&middle){
            
            swap(first->data,middle->data);
        }
    }
};

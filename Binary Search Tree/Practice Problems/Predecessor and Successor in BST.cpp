https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        if(root==NULL)return;
        
        Node*curr=root;
        
        while(curr!=NULL){
            
            if(curr->key == key )curr=curr->right;
            
            else if(curr->key  > key ){
                
                suc = curr;
                curr=curr->left;
            }
            else curr=curr->right;
        }
        
        curr=root;
        
        while(curr!=NULL){
            
            if(curr->key  == key )curr=curr->left;
            else if(curr->key  < key ){
                pre = curr;
                curr=curr->right;
            }
            else curr=curr->left;
        }
    }
};

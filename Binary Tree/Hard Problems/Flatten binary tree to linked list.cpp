https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flatten-binary-tree-to-linked-list

class Solution
{
    public:
    void flatten(Node *root)
    {
        //code here
        Node*curr=root;
        
        while(curr){
            
            if(curr->left){
                
                Node*temp = curr->left;
                
                while(temp->right!=NULL )temp=temp->right;
                
                temp->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            else{
                curr=curr->right;
            }
        }
        
        
    }
};

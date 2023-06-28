https://practice.geeksforgeeks.org/problems/symmetric-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=symmetric-tree

class Solution{
    private:
    bool solve(struct Node*root1, struct Node*root2){
        
        if(root1==NULL && root2==NULL)return true;
        if(root1==NULL || root2==NULL)return false;
        
        if(root1->data==root2->data){

            return solve(root1->left,root2->right) && solve(root1->right,root2->left);
        }
        
        else return false;
    }
    
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    
	    return solve(root,root);
    }
};

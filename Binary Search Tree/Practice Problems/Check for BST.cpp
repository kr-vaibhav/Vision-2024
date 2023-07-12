https://practice.geeksforgeeks.org/problems/check-for-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=check-for-bst

class Solution
{   private:
    
    bool solve(Node*root, int mn, int mx){
        
        if(root==NULL)return true;
        
        bool left = solve(root->left,mn,root->data);
        bool right = solve(root->right,root->data,mx);
        
        bool flag = 0;
        
        if( root->data > mn && root->data < mx)flag=1;
        
        return left && flag && right;
    }
    
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
        return solve(root, INT_MIN, INT_MAX);
    }
};

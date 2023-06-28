https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=diameter-of-binary-tree

class Solution {
    
    private:
    
    int solve(Node*root, int&res){
        
        if(root==NULL)return 0;
        
        int left     = solve(root->left,res);
        int right    = solve(root->right,res);
        
        int temp = 1 + left + right;
        
        res = max( res, temp);
        
        return max(left,right)+1;
    }
    
    
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        
        int res=INT_MIN;
        
        solve(root, res);
        
        return res;
        
    }
};

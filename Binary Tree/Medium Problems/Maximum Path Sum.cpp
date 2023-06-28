https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-path-sum-from-any-node

class Solution {
    
    private:
    
    int solve(Node*root, int&res){
        
        if(root==NULL)return 0;
        
        int left     = solve(root->left,res);
        
        int right    = solve(root->right,res);
        
        int temp;
        
        if(left<0 && right<0) temp = root->data;
        else temp = root->data + max(left,right);
        
        int ans = max( temp, left+right+root->data);
        
        res = max(res,ans);
        
        return temp;
        
    }
    
    
  public:
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root)
    {
        // Your code goes here
        int res =   INT_MIN;
        
        solve(root, res);
        
        return res;
    }
};

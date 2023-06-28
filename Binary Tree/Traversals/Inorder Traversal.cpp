https://practice.geeksforgeeks.org/problems/inorder-traversal/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=inorder-traversal

class Solution {
    private:
    
    void in(Node*root, vector<int>&ans){
    
    if(root==NULL)return;
    
    
    in(root->left,ans);
    
    ans.push_back(root->data);
    
    in(root->right,ans);
}
    
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        
        vector<int>ans;
        in(root,ans);
        
        return ans;
    }
};

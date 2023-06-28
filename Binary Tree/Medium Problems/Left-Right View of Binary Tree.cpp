https://leetcode.com/problems/binary-tree-right-side-view/

class Solution {
    private:

    void solve(TreeNode*root, map<int,int>&mp){
    
    int horz = 0;
    
    queue<pair<TreeNode*,int>>q;
    q.push({root,horz});
    
    while(!q.empty()){
        
        TreeNode*curr = q.front().first;
        int h = q.front().second;
        q.pop();
        
        if(mp.find(h)==mp.end())mp[h]=curr->val;
        
        if(curr->right)q.push({curr->right,h+1});
        if(curr->left)q.push({curr->left,h+1});
        
    }
    
}
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int>ans;
   
   if(root==NULL)return ans;
  
    map<int,int>mp;   // { horizontal, value};
    
    solve(root,mp);
    
    for(auto it:mp){
        
        ans.push_back(it.second);
    }
  
    return ans;
    }
};

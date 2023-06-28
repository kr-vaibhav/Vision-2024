https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bottom-view-of-binary-tree

class Solution {
    private:
    
    void solve(Node*root, map< int, pair<int,int> > &mp, int v, int h){
        
        queue< pair< Node*, pair<int,int> > >q;  // { root, { v, h} };
        
        q.push({root,{v,h}});
        
        while(!q.empty()){
            
            Node* curr = q.front().first;
            int vertical = q.front().second.first;
            int horizontal = q.front().second.second;
            q.pop();
            
            mp[vertical] = {horizontal,curr->data};
            
            if(curr->left)q.push({curr->left,{vertical-1,horizontal+1}});
            if(curr->right)q.push({curr->right,{vertical+1,horizontal+1}});
        }
    }
    
    
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        if(root==NULL) return {};
        
        int v = 0;
        int h = 0;
        
        map< int , pair<int,int> > mp;  // { v,{h, value} };
        
        solve(root,mp,v,h);
        
        vector<int>ans;
        
        for(auto it:mp){
            
            int vert = it.first;
            int horz = it.second.first;
            int val = it.second.second;
            
            ans.push_back(val);
        }
        
        return ans;
        
    }
};

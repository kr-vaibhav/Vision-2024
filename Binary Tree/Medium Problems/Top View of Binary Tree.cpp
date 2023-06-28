https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=top-view-of-binary-tree

class Solution
{   
    private:
    
    void solve(Node*root, int vertical, map<int,int>&mp){
        
        
        queue< pair<Node*,int> >q;  // { root, level};
        q.push({root,vertical});
        
        while(!q.empty()){
            
            Node*curr = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(mp.find(level)==mp.end()){
                
                mp[level] = curr->data;
            }
            
            if(curr->left)q.push({curr->left,level-1});
            if(curr->right)q.push({curr->right,level+1});
        }
        
        
    }
    
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        if(root==NULL)return {};
        
        map<int,int>mp;  // { vertical, value};
        
        int vertical = 0;
        
        solve(root,vertical,mp);
        
        vector<int>ans;
        
        for(auto it:mp){
            
            ans.push_back(it.second);
        }
        
        return ans;
    }

};

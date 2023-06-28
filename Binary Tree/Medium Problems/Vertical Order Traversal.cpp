https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-a-binary-tree-in-vertical-order

typedef pair<int,pair<int,pair<int,int>>>ppi;

class Solution
{   private:

    int count=0;

    void solve(Node*root, int vertical, int horizontal,  priority_queue<ppi,vector<ppi>,greater<ppi>>&minh){
        
        count++;
        if(root==NULL)return;
        
        minh.push({vertical,{horizontal,{count,root->data}}});
        
        solve(root->left, vertical - 1, horizontal +1, minh);
        solve(root->right, vertical+1, horizontal+1,minh);
        
        
    }
    
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        priority_queue<ppi,vector<ppi>,greater<ppi>>minh;
        
        // { vertical_level, {horizontal_level, { count, value }  } };
        
        int vertical = 0, horizontal = 0;
        
        solve(root,vertical, horizontal, minh);
        
        vector<int>ans;
        
        while(!minh.empty()){
            
            ans.push_back(minh.top().second.second.second);
            minh.pop();
        }
        
        return ans;
    }
};

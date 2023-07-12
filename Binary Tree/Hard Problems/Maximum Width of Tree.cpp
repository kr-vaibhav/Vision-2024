https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-width-of-tree

class Solution {
  public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {

        // Your code here
        queue<Node*>q;
        q.push(root);
        
        int ans = 0;
        
        while(!q.empty()){
            
            int size = q.size();
            ans = max(ans,size);
            
            for(int i=0;i<size;i++){
                
                Node*curr = q.front();
                q.pop();
                
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
        }
        
        return ans;
    }
};

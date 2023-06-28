https://practice.geeksforgeeks.org/problems/binary-tree-representation/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=binary-tree-representation

class Solution{
public:

    void create_tree(node* root0, vector<int> &vec){
        //Your code goes here
        int i = 1;
        
        int n = vec.size();
        
        queue<node*>q;
        q.push(root0);
        
        while(!q.empty() && i<n ){
            
            node* curr = q.front();
            q.pop();
            
            node* left = newNode(vec[i++]);
            curr->left = left;
            q.push(left);
            
            node* right = newNode(vec[i++]);
            curr->right = right;
            q.push(right);
            
        }
        
        
    }

};

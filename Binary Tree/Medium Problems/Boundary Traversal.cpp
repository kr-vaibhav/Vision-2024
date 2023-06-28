https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=boundary-traversal-of-binary-tree

class Solution {
    
private:
    void left(Node*root, vector<int>&ans){
        
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return;
        }
         
        
        ans.push_back(root->data);
        
        if(root->left)left(root->left,ans);
        else left(root->right,ans);
    }
    
    void leaf(Node*root, vector<int>&ans){
      
      if(root==NULL)return;
      if(root->left==NULL && root->right==NULL){
          ans.push_back(root->data);
          return;
      }
      
      
      leaf(root->left,ans);
      leaf(root->right,ans);
    }
    
    void right(Node*root, vector<int>&ans){
        
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return;
        }
        
        
        ans.push_back(root->data);
        
        if(root->right){
            right(root->right,ans);
        }
        else if(root->left){
            right(root->left,ans);
        }
    }
    
public:
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        
        if(root==NULL)return ans;
        
        ans.push_back(root->data);
        
        left(root->left,ans);
        
        leaf(root->left,ans);
        leaf(root->right,ans);
        
        vector<int>revans;
        
        right(root->right,revans);
        
        int size=revans.size();
        reverse(revans.begin(),revans.end());
        for(int i=0;i<size;i++){
            ans.push_back(revans[i]);
        }
        return ans;
    }
};

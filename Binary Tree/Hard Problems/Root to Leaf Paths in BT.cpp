https://practice.geeksforgeeks.org/problems/root-to-leaf-paths/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=root-to-leaf-paths

 void solve(Node*root, vector<int>path, vector<vector<int>>&ans){
     
     if(root==NULL)return;
     
     if(root->left==NULL && root->right==NULL){
         
        path.push_back(root->data);
        ans.push_back(path);
        path.pop_back();
        
        return;
     }
     
     path.push_back(root->data);
     solve(root->left,path,ans);
     solve(root->right,path,ans);
     path.pop_back();
     
     
 }
 
vector<vector<int>> Paths(Node* root)
{
    // Code here
    vector<int>path;
    vector<vector<int>>ans;
    
    solve(root,path,ans);
    
    return ans;
}

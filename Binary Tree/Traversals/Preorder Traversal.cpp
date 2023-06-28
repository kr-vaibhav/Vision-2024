https://practice.geeksforgeeks.org/problems/preorder-traversal/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=preorder-traversal


void pre(Node*root, vector<int>&ans){
    
    if(root==NULL)return;
    
    ans.push_back(root->data);
    pre(root->left,ans);
    pre(root->right,ans);
}


vector <int> preorder(Node* root)
{
  // Your code here
  vector<int>ans;
  pre(root,ans);
  
  return ans;
  
}

https://practice.geeksforgeeks.org/problems/postorder-traversal/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=postorder-traversal

    void post(Node*root, vector<int>&ans){
    
    if(root==NULL)return;
    
    
    post(root->left,ans);
    
    post(root->right,ans);
        
    ans.push_back(root->data);
}

vector <int> postOrder(Node* root)
{
  // Your code here
    vector<int>ans;
    post(root,ans);
    
    return ans;
}

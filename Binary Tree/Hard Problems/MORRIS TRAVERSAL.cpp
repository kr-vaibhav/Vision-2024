https://practice.geeksforgeeks.org/problems/preorder-traversal/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=preorder-traversal

vector <int> preorder(Node* root)
{
  // Your code here
  
  vector<int>ans;
  if(root==NULL)return ans;
  
  Node*curr=root;
  
    while(curr){
        
        if(curr->left){
            
            Node*temp = curr->left;
            
            while(temp->right!=NULL && temp->right!=curr)temp=temp->right;
            
            if(temp->right==NULL){
                temp->right=curr;
                ans.push_back(curr->data);
                curr=curr->left;
            }
            else{
                curr=curr->right;
                temp->right=NULL;
            }
        }
        else{
            
            ans.push_back(curr->data);
            curr=curr->right;
        }
    }
    
    return ans;
}

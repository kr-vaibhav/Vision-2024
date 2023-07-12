https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1

class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int target)
    {
    //add code here.
        vector<int>ans;
        
        struct Node*curr = root;
        
        while(curr){
            
            if(curr->left){
                
                struct Node*temp = curr->left;
                
                while(temp->right!=NULL && temp->right!=curr)temp=temp->right;
                
                if(temp->right==NULL){
                    
                    temp->right=curr;
                    curr=curr->left;
                }
                else{
                    
                    ans.push_back(curr->data);
                    curr=curr->right;
                    temp->right=NULL;
                }
            }
            else{
                
                ans.push_back(curr->data);
                curr=curr->right;
            }
        }
        
        int i=0,j=ans.size()-1;
        
        while(i<j){
            
            if(ans[i]+ans[j]==target)return 1;
            else if(ans[i]+ans[j]>target)j--;
            else i++;
        }
        
        return 0;
    }
};

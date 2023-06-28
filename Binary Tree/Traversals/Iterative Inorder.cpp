https://practice.geeksforgeeks.org/problems/inorder-traversal-iterative/1

class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        //code here
        Node*curr = root;
        
        vector<int>ans;
        
        while(curr){
            
            if(curr->left!=NULL){
                
                Node*temp = curr->left;
                
                while(temp->right && temp->right!=curr){
                    
                    temp = temp->right;
                    
                }
                
                if(temp->right == NULL){
                    temp->right = curr;
                    curr = curr->left;
                }
                else{
                    
                    ans.push_back(curr->data);
                    temp->right = NULL;
                    curr= curr->right;
                }
            }
            else{
                
                ans.push_back(curr->data);
                curr= curr->right;
            }
        }
        
        return ans;
        
    }
};

https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1

class Solution
{   private:

    void store(Node*root, vector<int>&ans){
        
        Node*curr=root;
        
        while(curr){
            
            if(curr->left){
                
                Node*temp=curr->left;
                while(temp->right && temp->right!=curr)temp=temp->right;
                
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
    }
    
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int>final,first,second;
       
       if( !root1 && !root2)return final;
       
       
       
       store(root1,first);
       store(root2,second);
       
       int i=0,j=0;
       
       while(i<first.size() && j<second.size()){
           
           if(first[i]==second[j]){
               
               final.push_back(first[i++]);
           }
           else if(first[i] > second[j]){
               
               final.push_back(second[j++]);
           }
           else{
               
               final.push_back(first[i++]);
           }
       }
       
       while(i<first.size())final.push_back(first[i++]);
       while(j<second.size())final.push_back(second[j++]);
       
       return final;
    }
};

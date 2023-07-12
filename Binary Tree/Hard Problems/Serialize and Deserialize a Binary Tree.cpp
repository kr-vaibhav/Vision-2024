https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=serialize-and-deserialize-a-binary-tree

class Solution
{   private:

    void store(Node*root, vector<int>&ans){
        
        if(root==NULL){
            
            ans.push_back(-1);
            return;
        }
        
        ans.push_back(root->data);
        store(root->left,ans);
        store(root->right,ans);
    }
    
    Node* create(vector<int>&ans, int&i){
        
        
        if(i>=ans.size())return NULL;
        
        int val = ans[i++];
        
        if(val==-1)return NULL;
        
        struct Node* root = new Node(val);
        
        root->left = create(ans,i);
        root->right = create(ans,i);
        
        return root;
    }
    
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int>ans;
        
        if(root==NULL)return ans;
        
        store(root,ans);
        
        return ans;
        
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       if(A.size()==0)return NULL;
       
       int i=0;
       
       return create(A,i);
    }

};

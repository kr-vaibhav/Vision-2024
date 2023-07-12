https://practice.geeksforgeeks.org/problems/construct-tree-1/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=construct-tree

class Solution{
    
    int i=0;
    
    private:
    
    Node* solve(vector<int>& preorder, vector<int>& inorder) {
        
        if(inorder.size()==0)return NULL;

        int node = preorder[i++];

        int size = 0;

        for(int i=0;i<inorder.size();i++){

            if(inorder[i]!=node)size++;
            else break;
        }
        vector<int>left,right;
        for(int i=0;i<size;i++)left.push_back(inorder[i]);
        for(int i=size+1;i<inorder.size();i++)right.push_back(inorder[i]);

        struct Node* curr = new Node(node);

       curr->left = solve(preorder,left);
       curr->right = solve(preorder,right);

       return curr;
    }
    
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        vector<int>inorder(n),preorder(n);
        
        for(int i=0;i<n;i++){
            inorder[i] = in[i];
            preorder[i] = pre[i];
        }
        
        return solve(preorder,inorder);
    }
};

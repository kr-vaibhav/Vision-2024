https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=check-for-balanced-tree#:~:text=Given%20a%20binary%20tree,%20find,for%20all%20nodes%20of%20tree.&text=Example%202:,and%20right%20subtree%20is%201.

class Solution{
    private:
    
    int check(Node*root, bool &istrue){
        
        if(root==NULL) return 0;
        if(root->left == NULL && root->right==NULL)return 1;
        
        int left = check(root->left,istrue);
        int right = check(root->right,istrue);
        
        if(abs(left-right)>1)istrue=false;
        
        return 1 + max(left,right);
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        
        bool istrue = true;
        check(root,istrue);
        
        return istrue;
        
    }
};

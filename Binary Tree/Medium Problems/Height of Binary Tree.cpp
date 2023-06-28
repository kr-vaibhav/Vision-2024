https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=height-of-binary-tree

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        if(node==NULL)return 0;
        if(node->left==NULL && node->right==NULL)return 1;
        
        int left = height(node->left);
        
        int right = height(node->right);
        
        return 1 + max(left,right);
        
    }
};

https://practice.geeksforgeeks.org/problems/children-sum-parent/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=hildren-sum-parent

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
        
        if(root==NULL)return 1;
        if(root->left==NULL && root->right==NULL)return 1;
        
        int sum =0;
        
        if(root->left)sum+=root->left->data;
        if(root->right)sum+=root->right->data;
        
        return (root->data==sum && isSumProperty(root->left) && isSumProperty(root->right));
    }
};

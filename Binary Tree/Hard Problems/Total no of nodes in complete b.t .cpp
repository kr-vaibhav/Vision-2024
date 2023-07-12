https://practice.geeksforgeeks.org/problems/count-number-of-nodes-in-a-binary-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=count-number-of-nodes-in-a-binary-tree

class Solution {
  public:
    int countNodes(Node* root) {
        // Write your code here
        if(root==NULL)return 0;
        if(root->left==NULL && root->right==NULL)return 1;
        
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        
        return 1 + left + right;
    }
};

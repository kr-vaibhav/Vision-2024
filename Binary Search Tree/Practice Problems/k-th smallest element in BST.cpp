https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1#:~:text=Find%20the%20Kth%20Smallest%20element%20in%20the%20BST.&text=Your%20Task%3A,such%20element%20exists%20return%20%2D1.


class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int&K) {
        // add code here.
        if(root==NULL)return-1;
        
        int left = KthSmallestElement(root->left,K);
        
        if(left!=-1)return left;
        
        int value=-1;
        
        K--;
        
        if(K==0)value=root->data;
        
        int right = KthSmallestElement(root->right,K);
        
        if(right!=-1)return right;
        
        
        return value;
        
        
    }
};

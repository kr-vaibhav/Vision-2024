https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1


class Solution{
    private:
    
    Node* solve( int pre[], int&i, int size, int bound ){
        
        if(i>=size || pre[i]>bound)return NULL;
        
        Node* root = newNode(pre[i++]);
        
        root->left = solve(pre,i,size,root->data);
        
        root->right = solve(pre,i,size,bound);
        
        return root;
    }
    
public:
    //Function that constructs BST from its preorder traversal.
    Node* post_order(int pre[], int size)
    {
        //code here
        int i=0;
        return solve(pre,i,size,INT_MAX);
    }
};

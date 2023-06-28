https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=determine-if-two-trees-are-identical

class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *p, Node *q)
    {
        //Your Code here
        
        if(p==NULL && q==NULL)return true;
        if(p==NULL || q==NULL)return false;

        bool left = isIdentical(p->left,q->left);
        bool right = isIdentical(p->right,q->right);

        if(p->data!=q->data)return false;

        return left&&right;
    }
};

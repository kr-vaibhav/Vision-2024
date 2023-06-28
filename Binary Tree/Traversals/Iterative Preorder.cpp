https://practice.geeksforgeeks.org/problems/preorder-traversal-iterative/1

class Solution{
    public:
    vector<int> preOrder(Node* root)
    {
        //code here
        if(root==NULL) return {};
        
        stack<Node*>st;
        st.push(root);
        vector<int>ans;
        
        while(!st.empty()){
            
            Node*curr = st.top();
            st.pop();
            ans.push_back(curr->data);
            
            if(curr->right)st.push(curr->right);
            if(curr->left)st.push(curr->left);
        }
        
        return ans;
    }
};

https://practice.geeksforgeeks.org/problems/postorder-traversal-iterative/1

class Solution{
    public:
    vector<int> postOrder(Node* root) {
        // code here
        if(root==NULL)return {};
        
        vector<int>ans;
        
        stack<Node*>st;
        st.push(root);
        
        while(!st.empty()){
            
            Node* curr = st.top();
            st.pop();
            ans.push_back(curr->data);
            
            if(curr->left)st.push(curr->left);
            if(curr->right)st.push(curr->right);
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

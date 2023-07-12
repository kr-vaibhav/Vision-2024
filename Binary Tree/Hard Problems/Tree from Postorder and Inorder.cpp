https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=tree-from-postorder-and-inorder

    Node* solve(vector<int>& postorder, vector<int>& inorder, int&i) {
        
        if(inorder.size()==0)return NULL;

        int node = postorder[i++];

        int size = 0;

        for(int i=0;i<inorder.size();i++){

            if(inorder[i]!=node)size++;
            else break;
        }
        vector<int>left,right;
        for(int i=0;i<size;i++)left.push_back(inorder[i]);
        for(int i=size+1;i<inorder.size();i++)right.push_back(inorder[i]);

        struct Node* curr = new Node(node);

        curr->right = solve(postorder,right,i);
        curr->left = solve(postorder,left,i);
       

        return curr;
    }

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    vector<int>inorder(n),postorder(n);
    int i=0;
        
        for(int i=0;i<n;i++){
            inorder[i] = in[i];
            postorder[i] = post[i];
        }
        
        reverse(postorder.begin(),postorder.end());
        
        return solve(postorder,inorder,i);
}

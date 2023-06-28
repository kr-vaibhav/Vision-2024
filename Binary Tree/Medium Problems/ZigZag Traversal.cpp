https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=zigzag-tree-traversal

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int>ans;
    	
    	queue<Node*>q;
    	q.push(root);
    	
    	int level = 1;
    	
    	while(!q.empty()){
    	
    	    int size = q.size();
    	    vector<int>temp;
    	    
    	    for(int i=0;i<size;i++){
    	    
    	        Node*curr = q.front();
    	        temp.push_back(curr->data);
    	        q.pop();
    	        
    	        if(curr->left)q.push(curr->left);
    	        if(curr->right)q.push(curr->right);
    	    
    	    }
    	    
    	    int n = temp.size();
    	    
    	    if(level%2){
    	        for(int i=0;i<n;i++)ans.push_back(temp[i]);
    	    }
    	    else{
    	        reverse(temp.begin(),temp.end());
    	        for(int i=0;i<n;i++)ans.push_back(temp[i]);
    	    }
    	    
    	    level++;
    	}
    	
    	return ans;
    	
    }
};

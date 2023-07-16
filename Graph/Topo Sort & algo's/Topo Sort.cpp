https://practice.geeksforgeeks.org/problems/topological-sort/1

class Solution
{   private:
    
    stack<int>st;
    
    void dfs(int node, vector<bool>&visited, vector<int>adj[] ){
        
        visited[node] = 1;
        
        for(auto it:adj[node]){
            
            if(!visited[it])dfs(it,visited,adj);
        }
        
        st.push(node);
    }
    
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    
	    
	    vector<bool>visited(V+1,0);
	    
	    for(int i=0;i<V;i++){
	        
	        if(!visited[i])dfs(i,visited,adj);
	    }
	    
	    vector<int>ans;
	    
	    while(!st.empty()){
	        
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	}
};

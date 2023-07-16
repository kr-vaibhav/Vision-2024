https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        vector<int>indegree(V,0);
	    
	    for(int i=0;i<V;i++){
	        
	        for( auto it:adj[i]){
	            
	            indegree[it]++;
	        }
	    }
	    
	    queue<int>q;
	    vector<int>ans;
	    
	    for(int i=0;i<V;i++){
	        
	        if(indegree[i]==0)q.push(i);
	    }
	    
	    while(!q.empty()){
	        
	        int node = q.front();
	        q.pop();
	        
	        ans.push_back(node);
	        
	        for( auto it:adj[node]){
	            
	            indegree[it]--;
	            
	            if(indegree[it]==0)q.push(it);
	        }
	    }
	    
	    for(int i=0;i<V;i++)if(indegree[i]>0)return true;
	    return false;
        
    }
};

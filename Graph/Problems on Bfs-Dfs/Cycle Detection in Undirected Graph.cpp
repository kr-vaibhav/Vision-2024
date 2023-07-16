https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

class Solution {
    private:
    
    bool dfs(int node, int parent, vector<bool>&visited, vector<int>adj[]){
        
        visited[node] = 1;
        
        for(auto it:adj[node]){
            
            if(!visited[it]){
                
                visited[it] = 1;
                
                if(dfs(it,node,visited,adj))return true;
            }
            else if(it!=parent)return true;
        }
        
        return false;
    }
    
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<bool>visited(V,0);
        
        for(int i=0;i<V;i++){
            
            if(!visited[i]){
                
                if(dfs(i,-1,visited,adj))return true;
            }
        }
        
        return false;
    }
};

https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=dfs_of_graph

class Solution {
    private:
    
    void solve(int node, vector<int>adj[], vector<bool>&visited, vector<int>&ans ){
        
        ans.push_back(node);
        
        for(auto it:adj[node]){
            
            if(!visited[it]){
                
                visited[it]=1;
                solve(it,adj,visited,ans);
            }
        }
    }
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int>ans;
        
        vector<bool>visited(V,0);
        
        visited[0] = 1;
        
        solve(0,adj,visited,ans);
        
        return ans;
    }
};

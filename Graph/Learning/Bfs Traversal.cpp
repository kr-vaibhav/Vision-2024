https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bfs_of_graph

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int>q;
        q.push(0);
        vector<bool>visited(V,0);
        visited[0]=1;
        
        vector<int>ans;
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it: adj[node]){
                
                if(!visited[it]){
                    
                    visited[it]=1;
                    q.push(it);
                }
            }
        }
        
        return ans;
    }
};

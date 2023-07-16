https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-provinces


class Solution {
    private:
    
    void solve(int node, vector<bool>&visited, vector<int>graph[] ){
        
        visited[node]=1;
        
        for(auto it: graph[node]){
            
            if(!visited[it])solve(it,visited,graph);
        }
    }
    
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> graph[V+1];
        
        for(int i=0;i<V;i++){
            
            for(int j=0;j<V;j++){
                
                if(i!=j && adj[i][j]==1){
                    
                    graph[i+1].push_back(j+1);
                    
                }
            }
        }
        
        vector<bool>visited(V+1,0);
        
        int count=0;
        
        for(int i=1;i<=V;i++){
            
            if(!visited[i]){
                
                count++;
                
                solve(i,visited,graph);
                
            }
        }
        
        return count;
    }
};

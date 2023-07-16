https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph

class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        
        
        vector<pair<int,int>>adj[N];
        
        vector<int> distance(N,1e9);
        
        for(auto it:edges){
            
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adj[u].push_back({v,wt});
        }
        
        distance[0]=0;
        
        queue<pair<int,int>>q;
        q.push({0,0});          // { node,  distance};
        
        while(!q.empty()){
            
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            for(auto it:adj[node]){
                
                int adj = it.first;
                int adjwt = it.second;
                
                if(distance[adj] > dist + adjwt ){
                    
                    distance[adj] = dist + adjwt;
                    
                    q.push({adj,dist+adjwt});
                }
            }
        }
        
        for(int i=0;i<N;i++)if(distance[i]==1e9)distance[i] = -1;
        
        return distance;
    }
};

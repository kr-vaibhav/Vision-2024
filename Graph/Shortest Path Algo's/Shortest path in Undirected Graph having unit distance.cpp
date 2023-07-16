https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        
        vector<int>adj[N];
        
        vector<int>distance(N,1e9);
        
        for(auto it:edges){
            
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        distance[src] = 0;
        
        queue<pair<int,int>>q;
        q.push({src,0});
        
        while(!q.empty()){
            
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            for(auto it:adj[node]){
                
                if(distance[it] > dist + 1){
                    
                    distance[it] = dist + 1;
                    q.push({it,dist+1});
                }
            }
        }
        
        for(int i=0;i<N;i++)if(distance[i]==1e9)distance[i] = -1;
        
        
        return distance;
    }
};

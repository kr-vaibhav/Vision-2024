https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1

typedef pair<long long,long long>pll;
typedef long long ll;

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        
        vector<pll>adj[n];
        
        int mod = 1e9+7;
        
        for(auto it:roads){
            
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        
        
        vector<ll>distance(n,LLONG_MAX);
        vector<ll>path(n,0);
        
        path[0] = 1;
        distance[0] = 0;
        
        priority_queue<pll, vector<pll>, greater<pll>> minh;
        
        minh.push({0,0});       // { distance, node };
        
        while(!minh.empty()){
            
            ll node = minh.top().second;
            ll dist = minh.top().first;
            minh.pop();
            
            for(auto it: adj[node]){
                
                ll adjnode = it.first;
                ll adjwt   = it.second;
                
                if(distance[adjnode] > dist + adjwt ){
                    
                    distance[adjnode] = dist + adjwt;
                    
                    path[adjnode] = path[node]%mod;
                    
                    minh.push({distance[adjnode],adjnode});
                }
                else if( distance[adjnode] == dist+adjwt ){
                    
                    path[adjnode]  = ( path[adjnode] + path[node] )%mod;
                }
            }
        }
        
        
        return path[n-1]%mod;
    }
    
};

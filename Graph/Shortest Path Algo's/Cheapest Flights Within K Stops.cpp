https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=cheapest-flights-within-k-stops

typedef pair<int,pair<int,int>>ppi;

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        
        vector<pair<int,int>>adj[n];
        
        for(auto it:flights){
            
            int u = it[0];
            int v = it[1];
            int price = it[2];
            
            adj[u].push_back({v,price});
        }
        
        queue<ppi>minh;
        
        vector<int>distance(n,1e9);
        
        distance[src] = 0;
        
        minh.push({0,{src,0}});     // { stops, { src, flight_price } };
        
        while(!minh.empty()){
            
            int stops = minh.front().first;
            int city = minh.front().second.first;
            int price = minh.front().second.second;
            minh.pop();
            
            
            for(auto it:adj[city]){
                
                int adjcity = it.first;
                int adjprice = it.second;
                
                if(stops<=K && adjcity==dst && distance[adjcity] > price + adjprice){
                    
                    distance[adjcity] = price + adjprice;
                    
                    minh.push({stops+1,{adjcity,distance[adjcity]}});
                }
                else if(stops<K && distance[adjcity] > price + adjprice ){
                    
                    distance[adjcity] = price + adjprice;
                    
                    minh.push({ stops+1,{adjcity,distance[adjcity]}});
                }
            }
        }
        
        if(distance[dst]==1e9)return -1;
        
        return distance[dst];
        
    }
};

https://practice.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/0?category%5B%5D=Shortest%20Path&category%5B%5D=Shortest%20Path&page=1&query=category%5B%5DShortest%20Pathpage1category%5B%5DShortest%20Path

class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int th) {
        
        vector<vector<int>>distance(n,vector<int>(n,1e8));
        
        for(auto it:edges){
            
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            distance[u][v] = wt;
            distance[v][u] = wt;
        }
        
        
        for(int k=0;k<n;k++){
            
            for(int i=0;i<n;i++){
                
                for(int j=0;j<n;j++){
                    
                    
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j] );
                }
            }
        }
        
        int ans = -1;
        
        int mn = INT_MAX;
        
        for(int i=0;i<n;i++){
            
            int count = 0;
            
            for(int j=0;j<n;j++){
                
                if(i!=j && distance[i][j]<=th)count++;
            }
            
            mn = min(count,mn);
            if(count==mn)ans = i;
            
        }
        
        return ans;
        
    }
};

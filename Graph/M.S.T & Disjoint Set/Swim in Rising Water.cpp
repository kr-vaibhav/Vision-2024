https://leetcode.com/problems/swim-in-rising-water/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        priority_queue<pair<int,pair<int,int>>>minh;
        
        minh.push({grid[0][0],{0,0}});   // { value, { i, j } };
        
        int mn = INT_MAX;
        
        vector<vector<int>>distance(n,vector<int>(n,1e9));
        distance[0][0] = grid[0][0];
        
        int drow[4] = {+1,-1,0,0};
        int dcol[4] = {0,0,+1,-1};
        
        while(!minh.empty()){
            
            int dist = minh.top().first;
            int row = minh.top().second.first;
            int col = minh.top().second.second;
            minh.pop();
            
            if(row==n-1 && col==n-1);
            
            for(int k=0;k<4;k++){
                
                int nrow = drow[k] + row;
                int ncol = dcol[k] + col;
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n ){
                    
                    if(distance[nrow][ncol] > max( dist, grid[nrow][ncol])  ){
                        
                        distance[nrow][ncol] = max(dist, grid[nrow][ncol]);
                        
                        minh.push({distance[nrow][ncol],{nrow,ncol}});
                    }
                    
                }
            }
        }
        
        return distance[n-1][n-1];

        
    }
};

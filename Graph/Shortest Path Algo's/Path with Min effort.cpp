https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=path-with-minimum-effort

typedef pair<int,pair<int,int>>ppi;

class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>>distance(n,vector<int>(m,1e9));
        
        priority_queue<ppi,vector<ppi>,greater<ppi>>minh;
        
        int mn = INT_MAX;
        
        minh.push({0,{0,0}});       // { distance, { row, column } };
        
        distance[0][0] = 0;
        
        int drow[4] = {+1,-1,0,0};
        int dcol[4] = {0,0,+1,-1};
        
        
        while(!minh.empty()){
            
            int dist = minh.top().first;
            int row = minh.top().second.first;
            int col = minh.top().second.second;
            minh.pop();
            
            if(row==n-1 && col==m-1)mn = min(mn,dist);
            
            for(int k=0;k<4;k++){
                
                int nrow = drow[k] + row;
                int ncol = dcol[k] + col;
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m ){
                    
                    if(distance[nrow][ncol] > max( dist, abs(heights[row][col] - heights[nrow][ncol]))  ){
                        
                        distance[nrow][ncol] = max(dist,abs(heights[row][col]  - heights[nrow][ncol]) );
                        
                        minh.push({distance[nrow][ncol],{nrow,ncol}});
                    }
                    
                }
            }
        }
        
        return mn;
        
    }
};

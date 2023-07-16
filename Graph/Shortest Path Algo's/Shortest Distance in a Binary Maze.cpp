https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        // code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        
        int drow[4] = {+1,-1,0,0};
        int dcol[4] = {0,0,+1,-1};
        
        int sr = source.first;
        int sc = source.second;
        
        int dr = destination.first;
        int dc = destination.second;
        
        queue<pair<int,pair<int,int>>>q;
        
        q.push({0,{sr,sc}});
        
        visited[sr][sc] = 1;
        
        int ds = -1;
        
        while(!q.empty()){
            
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            
            if(row==dr && col==dc)return dist;
            
            q.pop();
            
            for(int k=0;k<4;k++){
                
                int nrow = row + drow[k];
                int ncol = col + dcol[k];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                    
                    visited[nrow][ncol] = 1;
                    q.push({dist+1,{nrow,ncol}});
                }
            }
        }
        
        return -1;
    }
};

https://practice.geeksforgeeks.org/problems/number-of-enclaves/1

class Solution {
    private:
    
    void dfs(int row, int col, vector<vector<bool>>&visited,vector<vector<int>>&grid){
        
        int n = visited.size();
        int m = visited[0].size();
        
        visited[row][col] = 1;
        
        int drow[4] = {+1,-1,0,0};
        int dcol[4] = {0,0,+1,-1};
        
        for(int k=0;k<4;k++){
            
            int nrow = drow[k] + row;
            int ncol = dcol[k] + col;
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                
                dfs(nrow,ncol,visited,grid);
            }
        }
    }
    
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        
        int count = 0;
        
        for(int i=0;i<n;i++){
            
            if(!visited[i][0] && grid[i][0]==1){
                
                dfs(i,0,visited,grid);
            }
            
            if( !visited[i][m-1] &&  grid[i][m-1]==1){
                
                dfs(i,m-1,visited,grid);
            }
        }
        
        
        for(int j=0;j<m;j++){
            
            if( !visited[0][j] && grid[0][j]==1)dfs(0,j,visited,grid);
            
            if( !visited[n-1][j] && grid[n-1][j]==1)dfs(n-1,j,visited,grid);
        }
        
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==1&&!visited[i][j])count++;
            }
        }
        
        
        
        
        
        return count;
    }
};

https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1

class Solution {
    private:
    
    set<vector<pair<int,int>>>st;
    
    void bfs( int ii, int jj, vector<vector<bool>>&visited, vector<vector<int>>& grid){
        
        visited[ii][jj] = 1;
        
        queue<pair<int,int>>q;
        q.push({ii,jj});
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<pair<int,int>>ans;
        
        while(!q.empty()){
            
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            pair<int,int>p;
            p.first = ii-i;
            p.second = jj-j;
            
            ans.push_back(p);
            
            //down
            
            int nrow=i+1;
            int ncol=j;
            
            if( nrow>=0 && nrow<n && ncol >=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                q.push({nrow,ncol});
                visited[nrow][ncol]=1;
                
            }
            
            //left
            
            nrow=i;
            ncol=j-1;
            
            if( nrow>=0 && nrow<n && ncol >=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                q.push({nrow,ncol});
                visited[nrow][ncol]=1;
                
            }
            
            //right
            
            nrow=i;
            ncol=j+1;
            
            if( nrow>=0 && nrow<n && ncol >=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                q.push({nrow,ncol});
                visited[nrow][ncol]=1;
                
            }
            
            //up
            
            nrow=i-1;
            ncol=j;
            
            if( nrow>=0 && nrow<n && ncol >=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                q.push({nrow,ncol});
                visited[nrow][ncol]=1;
                
            }
            
        }
        
        if(st.find(ans)==st.end())st.insert(ans);
        
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==1 && !visited[i][j]){
                    
                    bfs(i,j,visited,grid);
                    
                }
            }
        }
        
        return st.size();
    }
};

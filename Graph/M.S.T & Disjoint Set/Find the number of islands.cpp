https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-the-number-of-islands

class DisjointSet{
    
  vector<int>size,parent;
  public:
  
    DisjointSet(int n){
        
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    
    int findParent(int node){
        
        if(parent[node]==node)return node;
        
        return parent[node] =   findParent(parent[node]);
    }
    
    void UnionBySize(int u, int v){
        
        int Uu  =   findParent(u);
        int Uv  =   findParent(v);
        
        if(Uu   ==  Uv)return;
        
        if(size[Uv] > size[Uu]){
            
            parent[Uu]  =   Uv;
            size[Uv]    +=  size[Uu];
        }
        else{
            
            parent[Uv]  =   Uu;
            size[Uu]    +=  size[Uv];
        }
    }
  
};

class Solution {
    private:
    
    void solve( int row, int col, vector<vector<char>>& grid, vector<vector<bool>>&visited){
        
        visited[row][col] = 1;
        
        int n = grid.size();
        int m = grid[0].size();
        
        int drow[8] = {-1,-1,0,+1,+1,+1,0,-1};
        int dcol[8] = {0,+1,+1,+1,0,-1,-1,-1};
        
        for(int k = 0;k<8;k++){
            
            int nrow = row + drow[k];
            int ncol = col + dcol[k];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]=='1'){
                
                solve(nrow,ncol,grid,visited);
            }
        }
    }
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        
        int count=0;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(grid[i][j]=='1' && !visited[i][j]){
                    
                    count++;
                    
                    solve(i,j,grid,visited);
                }
            }
        }
        
        return count; 
        
    }
};

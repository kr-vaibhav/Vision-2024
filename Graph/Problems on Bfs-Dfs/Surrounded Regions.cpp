https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=replace-os-with-xs

class Solution{
    private:
    
    void dfs(int row, int col, vector<vector<bool>>&visited, vector<vector<char>>output){
        
        int n = visited.size();
        int m = visited[0].size();
        
        visited[row][col] = 1;
        
        int drow[4] = {+1,-1,0,0};
        int dcol[4] = {0,0,+1,-1};
        
        for(int k=0;k<4;k++){
            
            int nrow = drow[k] + row;
            int ncol = dcol[k] + col;
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && output[nrow][ncol]=='O'){
                
                dfs(nrow,ncol,visited,output);
            }
        }
    }
    
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        
        vector<vector<char>>output(mat);
        
        
        for(int i=0;i<n;i++){
            
            if(!visited[i][0] && output[i][0]=='O'){            // only thing to check here is iff not visited ! 
                                                                // that's an optimazation you need to have, otherwise tle
                
                dfs(i,0,visited,output);
            }
            
            if( !visited[i][m-1] &&  output[i][m-1]=='O'){
                
                dfs(i,m-1,visited,output);
            }
        }
        
        
        for(int j=0;j<m;j++){
            
            if( !visited[0][j] && output[0][j]=='O')dfs(0,j,visited,output);
            
            if( !visited[n-1][j] && output[n-1][j]=='O')dfs(n-1,j,visited,output);
        }
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                
                if(output[i][j]=='O' && !visited[i][j])output[i][j] = 'X';
            }
        }
        
        
        return output;
   
    }
};

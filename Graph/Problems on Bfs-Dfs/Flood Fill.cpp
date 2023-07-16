https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm

class Solution {
    private:
    
    void dfs(int sr, int sc, vector<vector<int>>&output, vector<vector<bool>>&visited, int color, int Newcolor){
        
        output[sr][sc] = Newcolor;
        visited[sr][sc] = 1;
        
        int n = output.size();
        int m = output[0].size();
        
        int drow[4] = {-1,+1,0,0};
        int dcol[4] = {0,0,-1,+1};
        
        for(int k =0;k<4;k++){
            
            int nrow = drow[k] + sr;
            int ncol = dcol[k] + sc;
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && output[nrow][ncol]==color ){
                
                dfs(nrow,ncol,output,visited,color,Newcolor);
            }
            
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        
        vector<vector<int>>output(image);
        
        int n = output.size();
        int m = output[0].size();
        
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        
        int color = image[sr][sc];
        
        dfs(sr,sc,output,visited,color,newColor);
        
        return output;
    }
};

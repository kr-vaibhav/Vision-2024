https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotten-oranges


class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>output(grid);
        
        queue<pair<int,pair<int,int>>>q;
        
        int timer=0,freshcount=0;
        
        
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(output[i][j]==2){
                    q.push({timer,{i,j}});
                    
                }
                else if(output[i][j]==1)freshcount++;
            }
        }
        
        
        
        int drow[4] = {-1,+1,0,0};
        int dcol[4] = {0,0,-1,+1};
        
        
        while(!q.empty()){
            
            int t = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;
            q.pop();
            
            timer = max(timer,t);
            
            for(int k = 0;k<4;k++){
                
                int nrow = drow[k] + i;
                int ncol = dcol[k] + j;
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && output[nrow][ncol]==1){
                    
                    //visited[nrow][ncol] = 1;
                    
                    output[nrow][ncol] = 2;
                    
                    freshcount--;
                    
                    q.push({t+1, {nrow,ncol}});
                }
            }
            
            
        }
        
        if(freshcount>0)return -1;
        
        return timer;
    }
};

https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    vector<vector<int>>output(grid);
	    
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    queue<pair<int,pair<int,int>>>q;
	    
	    vector<vector<bool>>visited(n,vector<bool>(m,0));
	    
	    for(int i=0;i<n;i++){
	        
	        for(int j=0;j<m;j++){
	            
	            if(grid[i][j]==1){
	                
	                q.push({0,{i,j}});
	                
	                visited[i][j] = 1;
	                
	                output[i][j] = 0;
	            }
	        }
	    }
	    
	    int drow[4] = {+1,-1,0,0};
	    int dcol[4] = {0,0,+1,-1};
	    
	    
	    
	    while(!q.empty()){
	        
	        int dist = q.front().first;
	        int i = q.front().second.first;
	        int j = q.front().second.second;
	        q.pop();
	        
	        for(int k=0;k<4;k++){
	            
	            int nrow = drow[k] + i;
	            int ncol = dcol[k] + j;
	            
	            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==0){
	                
	                output[nrow][ncol] = dist+1;
	                visited[nrow][ncol] = 1;
	                
	                q.push({dist+1,{nrow,ncol}});
	            }
	        }
	        
	    }
	    
	    return output;
	}
};

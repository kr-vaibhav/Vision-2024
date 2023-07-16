https://practice.geeksforgeeks.org/problems/maximum-connected-group/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-connected-group


class DisjointSet{
   
   public:
   
  vector<int>size,parent;
  
  
    DisjointSet(int n){
        
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    
    int findParent(int node){
        
        if(parent[node]==node)return node;
        
        return parent[node] =   findParent(parent[node]);
    }
    
    void Union(int u, int v){
        
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
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n   =   grid.size();
        int m   =   grid[0].size();
        vector<vector<int>>visited(n,vector<int>(n,0));
        
        DisjointSet dj(n*n);
        
        int drow[4] =   {+1,0,0,-1};
        int dcol[4] =   {0,-1,+1,0};
        
        int count=0;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<n;j++){
                
                
                
                if(grid[i][j]==1){
                    
                    for(int k=0;k<4;k++){
                    
                    int nrow    =   drow[k]+i;
                    int ncol    =   dcol[k]+j;
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n &&visited[nrow][ncol]==0 &&grid[nrow][ncol]==1){
                        
                        visited[nrow][ncol] ==  1;
                        
                        int node    =   i*n +   j;
                        
                        int adjNode =   nrow*n+ ncol;
                        
                        if(dj.findParent(node)!=dj.findParent(adjNode)){
                            
                            dj.Union(node,adjNode);
                            count++;
                        }
                        
                    }
                }  
                }
                
            }
        }
        
         int mx = 0;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==0){
                    
                    set<int>st;
                    
                    for(int k=0;k<4;k++){
                        
                        int nrow = i + drow[k];
                        int ncol = j + dcol[k];
                        
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 ){
                            
                            int node = m*nrow + ncol;
                            st.insert(dj.findParent(node));
                        }
                    }
                    
                    int count=0;
                    
                    for(auto it:st){
                        
                        count+= dj.size[it];
                    }
                    
                    mx = max(mx,count+1);
                }
            }
        }
        
        
        for(int i=0;i<n*n;i++)mx = max(mx,dj.size[i]);
        
        return mx;
    }
};

https://practice.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-stone-removal

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
        
        if(Uu==Uv)return;
        
        if(size[Uu]<size[Uv]){
            
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
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        
        
        
        int maxrow=0,maxcol=0;
        
        for(auto it:stones){
            
            maxrow =   max(maxrow,it[0]);
            maxcol =   max(maxcol,it[1]);
        }
        
        DisjointSet dj(maxrow+maxcol+1);
        
        set<int>s;
        
        for(auto it:stones){
            
            int r   =   it[0];
            int c   =   maxrow+it[1]+1;
            dj.UnionBySize(r,c);
            s.insert(r);
            s.insert(c);
        }
        
        int count=0;
        
        for(auto it:s){
            if(dj.findParent(it)==it)count++;
        }
        
        return n-count;
       
        
        
    }
};

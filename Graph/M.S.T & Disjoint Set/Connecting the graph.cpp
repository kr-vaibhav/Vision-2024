https://practice.geeksforgeeks.org/problems/connecting-the-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=connecting-the-graph

class DisjointSet{
    
    
    public:
    
    vector<int> size, parent;
    
    DisjointSet(int n){
        
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)parent[i]=i;
        
    }
    
    int findParent(int node){
        
        if(parent[node]==node)return node;
        
        return parent[node] = findParent(parent[node]);
        
    }
    
    void UnionBySize(int u, int v){
        
        int Uu  =   findParent(u);
        int Uv  =   findParent(v);
        
        if(Uu==Uv)return;
        
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
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        
        DisjointSet dj(n);
        int reserve=0;
        
        for(auto it:edge){
            
            int u   =   it[0];
            int v   =   it[1];
            
            if(dj.findParent(u)==dj.findParent(v)){
                
                reserve++;
                
            }
            else dj.UnionBySize(u,v);
            
        }
        
        
        
        int components=0;
        
        for(int i=0;i<n;i++){
            
            if(dj.findParent(i)==i)components++;
        }
        
        int ans =   components-1;
        
        if(reserve>=ans)return ans;
        
        return -1;
        
        
        
        
    }
};

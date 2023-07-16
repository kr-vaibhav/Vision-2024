https://practice.geeksforgeeks.org/problems/disjoint-set-union-find/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=disjoint-set-union-find

class DisjointSet{
    
    private:
    
    vector<int>size,parent;
    
    public:
    
    DisjointSet(int n){
        
        size.resize(n+1,1);
        parent.resize(n+1);
        
        for(int i=0;i<n+1;i++)parent[i] = i;
    }
    
    int find_uparent(int i){
        
        if(parent[i]==i)return i;
        
        return parent[i] = find_uparent(parent[i]);
    }
    
    void disjoint_size(int u, int v){
        
        int Uu = find_uparent(u);
        int Uv = find_uparent(v);
        
        if(Uu == Uv)return;
        
        if( size[Uv]> size[Uu]){
            
            size[Uv] += size[Uu];
            parent[Uu] = Uv;
        }
        else{
            
            size[Uu] += size[Uv];
            parent[Uv] = Uu;
        }
    }
    
};



/*Complete the functions below*/
int find(int parent[],int root)
{
       //add code here
        if(root==parent[root])return root;
        
        return parent[root] = find(parent,parent[root]);
       
}
void unionSet(int parent[],int u,int v)
{
	//add code here.
	
    u = find(parent,u);
    v = find(parent,v);
    
    if(u==v)return;
    else parent[u] = v;
    
}

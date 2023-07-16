https://practice.geeksforgeeks.org/problems/bipartite-graph/1

class Solution {
    
    private:
    
    bool check(int color[], int current,int parent,  vector<int>adj[]){
        
        for(auto it:adj[current]){
            
            if( color[it]==-1){
                
                color[it] = ! color[current];
                
                if( check(color,it,current,adj)==false)return false;
            }
            else if(color[current] == color[it] )return false;
        }
        
        
        return true;
        
    }
    
    
    
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    int color[V];
	    for(int i=0;i<V;i++)color[i]=-1;
	    
	    
	    
	    for(int i=0;i<V;i++){
	        
	        if(color[i]==-1){
	                
	                color[i]=0;
	            if( check(color,i,i,adj)==false)return false;
	        }
	    }
	    
	    return true;
	    
	    
	}

};

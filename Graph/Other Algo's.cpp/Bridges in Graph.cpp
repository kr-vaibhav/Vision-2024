https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bridge-edge-in-graph

class Solution
{   private:
    
    int t=0;
    
    void dfs(int node, int parent, vector<int>adj[],  int c, int d,vector<bool>&visited, vector<int>&timer, vector<int>&lowest, bool&flag){
        
        visited[node] = 1;
        timer[node] = t;
        lowest[node] = t;
        
        t++;
        
        for(auto it:adj[node]){
            
            if(it==parent)continue;
            
            else if(!visited[it]){
                
                dfs(it,node,adj,c,d,visited,timer,lowest,flag);
                
                lowest[node] = min(lowest[node], lowest[it]);
                
                if( lowest[it]>timer[node]&&((it==c&&node==d)||(it==d&&node==c)))flag=true;
            }
            else {
                
                lowest[node] = min(lowest[node], lowest[it]);
            }
        }
    }
    
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<bool>visited(V,0);
        bool flag = false;
        
        vector<int>timer(V,0);
        vector<int>lowest(V,0);
        
        for(int i=0;i<V;i++){
            
            if(!visited[i])dfs(i,-1,adj,c,d,visited,timer,lowest,flag);
        }
        
        return flag;
    }
};

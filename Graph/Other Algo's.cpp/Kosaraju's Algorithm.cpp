https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=strongly-connected-components-kosarajus-algo

class Solution
{   
    private:
    
    void dfs(int node, vector<vector<int>>&adj, bool visited[], stack<int>&s){
        
        visited[node]=1;
        
        for(auto it:adj[node]){
            
            if(!visited[it])dfs(it,adj,visited,s);
        }
        
        s.push(node);
    }
    
    void dfs1(int node, vector<int>adj[], bool visited[]){
        
        
        visited[node]=1;
        
        for(auto it:adj[node]){
            
            if(!visited[it])dfs1(it,adj,visited);
        }
    }
    
    
    
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        bool visited[V]={0};
        
        stack<int>s;
        
        for(int i=0;i<V;i++)if(!visited[i]) dfs(i,adj,visited,s);
        
        vector<int>reverse[V];
        
        for(int i=0;i<V;i++){
            
            visited[i]=0;
            
            for(auto it:adj[i]){
                
                reverse[it].push_back(i);
            }
        }
        
        int count=0;
        
        while(!s.empty()){
            
            int node    =   s.top();
            s.pop();
            if(!visited[node]){
                
                count++;
                dfs1(node,reverse,visited);
            }
        }

        return count;
    }
};

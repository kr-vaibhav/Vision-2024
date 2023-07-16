https://practice.geeksforgeeks.org/problems/eventual-safe-states/1

class Solution {
    
    private:
    bool safe(int node, vector<int>adj[], bool visited[], bool path[], bool safeNodes[]){
        
        visited[node]=1;
        path[node]=1;
        
        for(auto it: adj[node]){
            
            if(!visited[it]){
                
                if( safe(it,adj,visited,path,safeNodes)==true){
                    
                    return true;
                }
            }
            else if(path[it])return true;
        }
        
        
        
        safeNodes[node]=1;
        path[node]=0;
        
        return false;
    }
    
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        bool visited[V]={0};
        bool path[V]={0};
        bool safeNodes[V]={0};
        
        for(int i=0;i<V;i++){
            
            if(!visited[i]){
                
                safe(i,adj,visited,path,safeNodes);
            }
        }
        
        vector<int>ans;
        
        for(int i=0;i<V;i++){
            
            if(!path[i])ans.push_back(i);
        }
        
        return ans;
    }
};

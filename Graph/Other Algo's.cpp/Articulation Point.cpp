https://practice.geeksforgeeks.org/problems/articulation-point-1/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=articulation-point

class Solution {
    private:
    
    int t = 0;
    
    void dfs(int node, int parent, vector<int>adj[], vector<bool>&visited, vector<int>&timer, vector<int>&lowest, vector<int>&ans){
        
        visited[node] = 1;
        timer[node] = t;
        lowest[node] = t;
        t++;
        
        int children = 0;       // for initial node whose parent is -1;
        
        for(auto child:adj[node]){
            
            if(child==parent)continue;
            else if(!visited[child]){
                
                children++;
                
                dfs(child,node,adj,visited,timer,lowest,ans);
                
                lowest[node] = min(lowest[node], lowest[child]);
                
                if(parent!=-1 && lowest[child] >= timer[node])ans.push_back(node);
            }
            else {
                
                lowest[node] = min(lowest[node], timer[child]);
            }
        }
        
        if(children>1 && parent==-1)ans.push_back(node);
    }
    
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int>ans;
        vector<bool>visited(V,0);
        vector<int>timer(V),lowest(V);
        
        dfs(0,-1,adj,visited,timer,lowest,ans);
        
        if(ans.size()==0)return {-1};
        
        set<int>st;
        for(auto it:ans)st.insert(it);
        
        vector<int>a;
        
        for(auto it:st)a.push_back(it);
        
        
        return a;
    }
};

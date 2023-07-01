https://practice.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-adjacency-list

class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<vector<int>>ans;
        
        for(int i=0;i<V;i++){
            
            vector<int>p;
            
            p.push_back(i);
            
            for( auto it: adj[i] ){
                
                p.push_back(it);
            }
            
            ans.push_back(p);
        }
        
        return ans;
    }
};

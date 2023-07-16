https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1


typedef pair<int,int>pi;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        bool visited[V]={0};
        
        int ans = 0;
        
        priority_queue<pi,vector<pi>,greater<pi>>minh;
        
        minh.push({0,V-1});  // { distance, node };
        
        
        while(!minh.empty()){
            
            int node = minh.top().second;
            int dist = minh.top().first;
            minh.pop();
            
            if(visited[node]==true)continue;
            
            visited[node] = true;
            ans+=dist;
            
            for(auto it:adj[node]){
                
                int adj = it[0];
                int adjwt = it[1];
                
                if(!visited[adj])minh.push({adjwt,adj});
            }
        }
        
        return ans;
        
    }
};

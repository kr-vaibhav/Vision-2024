https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

typedef pair<int,int>pi;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        priority_queue<pi, vector<pi>, greater<pi>>minh;
        
        vector<int>distance(V,1e9);
        
        distance[S] = 0;
        
        minh.push({0,S});       // { distance, node};
        
        while(!minh.empty()){
            
            int node = minh.top().second;
            int dist = minh.top().first;
            minh.pop();
            
            for(auto it:adj[node]){
                
                int adj     = it[0];
                int adjwt   = it[1];
                
                if(distance[adj] > dist + adjwt){
                    
                    distance[adj] = dist + adjwt;
                    
                    minh.push({distance[adj],adj});
                }
            }
        }
        
        
        for(int i=0;i<V;i++)if(distance[i]==1e9)distance[i]=-1;
        
        return distance;
        
    }
};

https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
    private:
    
    bool dfs(int node, vector<bool>&visited, vector<bool>&pathvisited, vector<int>adj[] ){

	visited[node] = 1;
	pathvisited[node] = 1;

	for(auto it:adj[node]){

		if(!visited[it]){

			if( dfs(it,visited,pathvisited,adj) ==true)return true;
		}
		else if( pathvisited[it])return true;
	}

	pathvisited[node] = 0;

	return false;
}
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<bool>visited(v+1,0),pathvisited(v+1,0);

	for(int i=0;i<v;i++){

		if(!visited[i]){

			if( dfs(i,visited,pathvisited,adj)==true)return true;
		}
	}

	return false;
    }
};

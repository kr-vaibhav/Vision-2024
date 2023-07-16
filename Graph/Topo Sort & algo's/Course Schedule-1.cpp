https://practice.geeksforgeeks.org/problems/course-schedule/1

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<int>adj[n];
        vector<int>indegree(n,0);
        
        for(auto iti: prerequisites){

        adj[iti[1]].push_back(iti[0]);
    }

    for(int i=0;i<n;i++){

        for(auto iti:adj[i])indegree[iti]++;
    }

    queue<int>q;
    vector<int>ans;

    for(int i=0;i<n;i++)if(indegree[i]==0)q.push(i);
    
    int cnt=0;
        
        while(!q.empty()){
            
            int node=q.front();
            ans.push_back(node);
            cnt++;
            q.pop();
            
            for(auto it: adj[node]){
                
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        
        if(cnt==n)return ans;
        return {};
    }
};

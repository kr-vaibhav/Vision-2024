https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = numCourses;

        vector<int>indegree(n);
        vector<int>adj[n+1];

        for(auto it:prerequisites){

            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int>q;

        for(int i=0;i<n;i++){

            if(indegree[i]==0)q.push(i);
        }

        int count=0;

        vector<int>ans;

        while(!q.empty()){

            int node = q.front();
            q.pop();

            count++;
            ans.push_back(node);

            for(auto it:adj[node]){

                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }

        if(count==numCourses)return ans;
        return {};

    }
};

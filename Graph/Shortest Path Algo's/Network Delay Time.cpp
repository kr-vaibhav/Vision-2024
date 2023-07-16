https://leetcode.com/problems/network-delay-time/

typedef pair<int,int>pi;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>>adj[n+1];

        for(auto it:times){

            int u = it[0];
            int v = it[1];
            int tm = it[2];

            adj[u].push_back({v,tm});
        }

        vector<int>timed(n+1,1e9);

        timed[k] = 0;

        priority_queue<pi, vector<pi>, greater<pi>>minh;

        minh.push({0,k});      // { mintime, node}

        while(!minh.empty()){

            int ttaken = minh.top().first;
            int node = minh.top().second;
            minh.pop();

            for(auto it: adj[node]){

                int adjnode = it.first;
                int adjtime = it.second;

                if( timed[adjnode] > ttaken + adjtime ){

                    timed[adjnode] = ttaken + adjtime;

                    minh.push({timed[adjnode],adjnode});
                }
            }
        }

        int mx = INT_MIN;

        for(int i=1;i<n+1;i++){

            if(timed[i]==1e9)return -1;

            mx = max(mx,timed[i]);
        }

        return mx;
    }
};

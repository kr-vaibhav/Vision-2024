https://practice.geeksforgeeks.org/problems/alien-dictionary/1


class Solution{
    private:
    
    void create_graph(char s1, char s2, vector<int>adj[]){
        
        int first = s1-'a';
        int sec   = s2-'a';
        
        adj[first].push_back(sec);
    }
    
    void toposort(vector<int>adj[], int k , vector<int>&ans ){
        
        vector<int>indegree(k);
        
        for(int i=0;i<k;i++){
            
            for(auto it: adj[i])indegree[it]++;
        }
        
        queue<int>q;
        
        for(int i=0;i<k;i++)if(indegree[i]==0)q.push(i);
        
        while(!q.empty()){
            
            int node = q.front();
            ans.push_back(node);
            q.pop();
            
            for(auto it:adj[node]){
                
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        
        
    }
    
    public:
    string findOrder(string dict[], int n, int K) {
        //code here
        
        vector<int>adj[K];
        
        for(int i=0;i<n-1;i++){
            
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int len = min(s1.length(),s2.length());
            
            for(int i=0;i<len;i++){
                
                if(s1[i]!=s2[i]){
                    
                    create_graph(s1[i],s2[i],adj);
                    break;
                }
            }
        }
        
        vector<int>ans;
        
        toposort(adj,K,ans);
        
        string s = "";
        
        for(auto it:ans){
            
            s += 'a' + it;
        }
        
        return s;
    }
};

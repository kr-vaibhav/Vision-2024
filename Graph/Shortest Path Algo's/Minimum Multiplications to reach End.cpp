https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-multiplications-to-reach-end

typedef pair<int,int>pi;

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        
        int mod = 100000;
        
        vector<int>steps(mod,1e9);
        
        steps[start] = 0;
        
        priority_queue<pi, vector<pi>, greater<pi>>minh;
        
        minh.push({0,start});   // { steps, start};
        
        while(!minh.empty()){
            
            int node = minh.top().second;
            int st = minh.top().first;
            minh.pop();
            
            if(node==end)return steps[end];
            
            for(auto it:arr){
                
                int adjnode = (node*it)%mod;
                
                if( steps[adjnode] > st + 1 ){
                    
                    steps[adjnode] = 1 + st;
                    
                    minh.push({steps[adjnode],adjnode});
                }
            }
        }
        
        return -1;
    }
    
    
};

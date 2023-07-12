https://practice.geeksforgeeks.org/problems/burning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=burning-tree

class Solution {
    private:
    
    Node*find_node(Node*root, int target, Node*&tnode ){
        
        if(root==NULL)return NULL;
        
        if(root->data==target){
            tnode = root;
        }
        
        find_node(root->left,target,tnode);
        find_node(root->right,target,tnode);
        
    }
    
    unordered_map<Node*, Node*>parent;

    void createmap(Node*root){

        queue<Node*>q;
        q.push(root);
        //mp[root] = root;

        while(!q.empty()){

            int size = q.size();

            for(int i=0;i<size;i++){

                Node*curr = q.front();
                q.pop();

                if(curr->left){
                    q.push(curr->left);
                    parent[curr->left] = curr;
                }
                if(curr->right){

                    q.push(curr->right);
                    parent[curr->right] = curr;
                    
                }
            }
        }

    }
    
    
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        
        Node* tnode = NULL;
        
        find_node(root,target,tnode);
        createmap(root);
        
        unordered_map<Node*,bool>visited;
        visited[tnode] = 1;
        
        int ttime = 0;
        
        queue< pair<Node*,int> >q;
        q.push({tnode,ttime});
        
        while(!q.empty()){

            int size = q.size();

            for(int i=0;i<size;i++){

                Node*curr = q.front().first;
                int t = q.front().second;
                ttime = max(ttime,t);
                q.pop();

                if(curr->left && !visited[curr->left]){

                    q.push({curr->left,t+1});
                    visited[curr->left] = 1;
                }
                if(curr->right && !visited[curr->right]){

                    q.push({curr->right,t+1});
                    visited[curr->right] = 1;
                }

                if(parent[curr] && !visited[parent[curr]] ){

                    q.push({parent[curr],t+1});
                    visited[parent[curr]] = 1;
                }

            }

        }
        
        return ttime;

    }
};

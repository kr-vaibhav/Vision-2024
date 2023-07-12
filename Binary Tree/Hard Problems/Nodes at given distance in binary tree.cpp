https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=nodes-at-given-distance-in-binary-tree

class Solution
{
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

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        
        Node* tnode = NULL;
        
        find_node(root,target,tnode);
        
        
        vector<int>ans;
        
        unordered_map<Node*,bool>visited;

        createmap(root);

        queue< pair<Node*,int> >q;
        q.push({tnode,0});

        visited[tnode]=1;

        while(!q.empty()){

            int size = q.size();

            for(int i=0;i<size;i++){

                Node*curr = q.front().first;
                int level = q.front().second;
                q.pop();

                if(level==k)ans.push_back(curr->data);
                else if(level>k)break;

                if(curr->left && !visited[curr->left]){

                    q.push({curr->left,level+1});
                    visited[curr->left] = 1;
                }
                if(curr->right && !visited[curr->right]){

                    q.push({curr->right,level+1});
                    visited[curr->right] = 1;
                }

                if(parent[curr] && !visited[parent[curr]] ){

                    q.push({parent[curr],level+1});
                    visited[parent[curr]] = 1;
                }

            }

        }
        

        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

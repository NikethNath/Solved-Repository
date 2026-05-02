class Solution {
  public:
    bool ans=false;
    void dfs(int node, int parent,vector<vector<int>> &adj, vector<bool> &vis){
        for(int nbr : adj[node]){
            if(nbr!=parent && vis[nbr]){
                ans=true;
                
            }
            else if (nbr!=parent){
                vis[nbr]=true;
                dfs(nbr,node,adj,vis);
            }
        }
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(V,false);
        for(int i=0 ; i< V ; i++){
            if(!vis[i]){
                vis[i]=true;
                dfs(i,-1,adj,vis);

                }
            }
        return ans;
        }

        
    };

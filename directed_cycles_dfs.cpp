class Solution {
  public:
    bool dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &pathvis){
        for(int nbr : adj[node]){
            if(vis[nbr] && pathvis[nbr]){
                return true;
            }
            if(!vis[nbr]){
                vis[nbr]=true;
                pathvis[nbr]=true;
                if(dfs(nbr,adj,vis,pathvis)){
                    return true;
                    
                }
                pathvis[nbr]=false;
            }
        }
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        vector<bool> vis(V,false);
        vector<bool> pathvis(V,false);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
        }
        
        for(int i=0  ; i< V ; i++){
            if(vis[i]==false){
                vis[i]=true;
                pathvis[i]=true;
                if(dfs(i,adj,vis,pathvis)) return true;
                pathvis[i]=false;
            }
        }
        return false;
        
    }
};

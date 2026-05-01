class Solution {
  public:
    bool dfs(int node,vector<int>& color, vector<vector<int>> &adj){
        for(int nbr : adj[node]){
            if(color[nbr]!=-1 && color[node]==color[nbr]) return false;
            if(color[nbr]==-1){
                color[nbr]=1-color[node];
                 if(dfs(nbr,color,adj)==false){
                     return false;
                 }
            }
        }
        return true;    
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto edge : edges){
            int src=edge[0];
            int dst=edge[1];
            adj[src].push_back(dst);
            adj[dst].push_back(src);
        }
        vector<int> color(V,-1);
        color[0]=0;
        return dfs(0,color,adj);
  
    }
};

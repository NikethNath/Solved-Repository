class Solution {
  public:
    stack<int> stk;

    void dfs(int node, vector<bool> &vis,vector<vector<int>> &adj){
        for(int nbr : adj[node]){
            if(!vis[nbr]){
                vis[nbr]=true;
                dfs(nbr,vis,adj);
            }
        }
                stk.push(node);
    }
    void dfs1(int node, vector<bool> &vis,vector<vector<int>> &adj){
        for(int nbr : adj[node]){
            if(!vis[nbr]){
                vis[nbr]=true;
                dfs1(nbr,vis,adj);
            }
        }
    }
    int kosaraju(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        vector<vector<int>> revadj(V);
        vector<bool> vis(V,false);
        
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            revadj[edge[1]].push_back(edge[0]);
        }
        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                vis[i]=true;
                dfs(i,vis,adj);
            }
        }
        int ans=0;
        fill(vis.begin(),vis.end(),false);
        
        while(!stk.empty()){
            int top=stk.top();
            stk.pop();
            if(!vis[top]){
                vis[top]=true;
                ans++;
                dfs1(top,vis,revadj);
            }
            
        }
        return ans;
      
    }
};

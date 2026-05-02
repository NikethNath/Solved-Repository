class Solution {
  public:
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<bool> vis(V,false);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        queue<pair<int,int>> q;
        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                vis[i]=true;
                q.push({i,-1});
                
                while(!q.empty()){
                    int node=q.front().first;
                    int parent=q.front().second;
                    q.pop();
                    
                    for(int nbr : adj[node]){
                        if(nbr!=parent && vis[nbr]){
                            return true;
                        }
                        if(!vis[nbr]){
                            vis[nbr]=true;
                            q.push({nbr,node});
                        }
                    }
                }
            }
        }
        return false;
        
        
    }
};

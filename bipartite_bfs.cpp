class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto edge : edges){
            int src=edge[0];
            int dst=edge[1];
            adj[src].push_back(dst);
            adj[dst].push_back(src);
            
        }
        vector<int> color(V,-1);
        queue<int> q;
        q.push(0);
        color[0]=0;
        while(!q.empty()){
            int top=q.front();
            int topcolor=color[top];
            q.pop();
            for(int nbr : adj[top]){
                if(color[nbr]!=-1 && color[nbr]==color[top]){
                    return false;
                }
                if(color[nbr]==-1){
                color[nbr]=1-color[top];
                q.push(nbr);
                }
            } 
        }
        return true;

    }
};

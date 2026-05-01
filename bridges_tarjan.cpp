class Solution {
public:
    int time=0;
    vector<vector<int>> ans;
    void dfs(int node,int parent, vector<vector<int>> &adj, vector<int> &low, vector<int> & ts){
        for(int nbr : adj[node]){
            if(ts[nbr]==-1){
                ts[nbr]=time;
                low[nbr]=time;
                time++;
                dfs(nbr,node,adj,low,ts);
                low[node]=min(low[node],low[nbr]);

            }
            else{
                if(nbr==parent)continue;
                low[node]=min(low[node],ts[nbr]);
                }
                if(low[nbr]>ts[node]){
                    ans.push_back({node,nbr});
                }
            }
        }


    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        vector<int> low(n);
        vector<int> ts(n,-1);
        for(auto edge : connections){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);

        }
        for(int i=0 ; i<n ; i++){
            if(ts[i]==-1){
                ts[i]=time;
                low[i]=time;
                time++;
                dfs(i,-1,adj,low,ts);
            }
        }
        return ans;
        
    }
};

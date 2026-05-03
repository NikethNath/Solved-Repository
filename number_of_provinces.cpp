class Solution {
public:
    void dfs(int node,vector<bool>&vis, vector<vector<int>> &isConnected){
        for(int nbr=0 ; nbr<isConnected.size() ; nbr++){
            if(isConnected[node][nbr]==1 && !vis[nbr]){
                vis[nbr]=true;
                dfs(nbr,vis,isConnected);
            }

        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> vis(n,false);
        int ans=0;
        for(int i=0 ; i< n ; i++){
            if(!vis[i]){
                ans++;
                vis[i]=true;
                dfs(i,vis,isConnected);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        queue<pair<int,int>> q;   //node, mask
        int n=graph.size();
        vector<vector<bool>> vis(n+1, vector<bool>((1<<n)+1,false));
        for(int i=0 ; i< graph.size() ; i++){
            q.push({i,1<<i});
            vis[i][1<<i]=true;

        }
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0 ; i<size ; i++){
            auto p=q.front();
            if(p.second==((1<<n)-1)){
                return ans;
            }
            q.pop();
            for(int nbr : graph[p.first]){
                if(!vis[nbr][p.second | (1<<nbr)]){
                    vis[nbr][p.second | (1<<nbr)]=true;
                    q.push({nbr,p.second | (1<<nbr)});
                }
            }
        }
        ans++;
            }
            return ans;
            }
};

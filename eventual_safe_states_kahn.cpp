class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int V=graph.size();
        vector<int> indegree(V,0);
        queue<int> q;
        vector<vector<int>> adj(V);
        for(int i=0 ; i< V ; i++){
            for(int j : graph[i]){
                adj[j].push_back(i);
                indegree[i]++;

            }
        }
        for(int i=0 ; i<V ; i++){
            if(indegree[i]==0){
                ans.push_back(i);
                q.push(i);

            }
        }
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(int nbr : adj[front]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    ans.push_back(nbr);
                    q.push(nbr);
                }
            }
        }
        sort(ans.begin(),ans.end());

        return ans;

        
    }
};

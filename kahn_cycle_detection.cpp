class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> indegree(V,0);
        vector<vector<int>> adj(V);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        
        queue<int> q;
        int length=0;
        for(int i=0 ; i< V ; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            length++;
            for(int nbr : adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
            
            
        }
        if(length==V) return false;
        return true;
    }
};

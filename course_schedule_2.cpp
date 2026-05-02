class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        queue<int> q;
        vector<int> ans;
        vector<int> indegree(numCourses,0);
        for(auto edge : prerequisites){
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;

        }
        
        for(int i=0 ; i<numCourses ; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(int nbr : adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        if (ans.size()<numCourses) return {};
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto edges : prerequisites){
            adj[edges[0]].push_back(edges[1]);
            indegree[edges[1]]++;
        }
        queue<int> q;

        for(int i=0 ; i<numCourses ; i++){
            if(indegree[i]==0){
                q.push(i);

            }
        }
        int length=0;

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
        if(length==numCourses) return true;
        return false;
        
    }
};

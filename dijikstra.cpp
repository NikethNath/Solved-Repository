class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;  // wt, node
        vector<vector<pair<int,int>>> adj(n);   // to, weight
        for(auto edge : times){
            adj[edge[0]-1].push_back({edge[1]-1,edge[2]});
        }
        vector<int> distance(n,1e9);
        distance[k-1]=0;
        pq.push({0,k-1});
        while(!pq.empty()){
            int node=pq.top().second;
            int dist=pq.top().first;
            pq.pop();
            for(auto nbr : adj[node]){
                int nextdist=dist+ nbr.second;
                if(distance[nbr.first]>nextdist){
                    distance[nbr.first]=nextdist;
                    pq.push({nextdist,nbr.first});
                }
            }
        }
        int ans=0;
        for(int dist : distance){
            ans=max(ans,dist);
        }
        if(ans==1e9) return -1;
        return ans;
    
    }
};

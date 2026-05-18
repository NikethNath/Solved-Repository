class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>> mpp;
        for(int i=0 ; i<n ; i++){
            mpp[arr[i]].push_back(i);
        }
        queue<int> q;
        vector<int> vis(n,false);
        int dist=0;
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int s=q.size();
            for(int i=0 ; i<s ; i++){
            int curr=q.front();
            if(curr==arr.size()-1){
                return dist;
            }
            q.pop();
            if(curr-1>=0 && !vis[curr-1]){
                q.push(curr-1);
                vis[curr-1]=true;
            }
            if(curr+1<=arr.size()-1 && !vis[curr+1]){
                q.push(curr+1);
                vis[curr+1]=true;
            }
            for(int nbr : mpp[arr[curr]]){
                if(nbr!=curr && !vis[nbr]){
                    vis[nbr]=true;
                    q.push(nbr);
                }

            }
            mpp[arr[curr]]={};

            }
            dist++;


        }
        return dist;
        
    }
};

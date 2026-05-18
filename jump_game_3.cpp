class Solution {
public:
    bool rf(int index,vector<int> &arr,vector<bool> &vis,vector<int> &dp){
        if(arr[index]==0) return true;
        if(dp[index]!=-1) return dp[index];
        int left=false;
        int right=false;
        if(index-arr[index]>=0 &&!vis[index-arr[index]]){
            vis[index-arr[index]]=true;
            left=rf(index-arr[index],arr,vis,dp);
        }
        if(index+arr[index]<=arr.size()-1 && !vis[index+arr[index]]){
            vis[index+arr[index]]=true;
            right=rf(index+arr[index],arr,vis,dp);
        }
        return dp[index]=left | right;
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool> vis(n,false);
        vector<int> dp(n,-1);
        vis[start]=true;
        return rf(start,arr,vis,dp);
        
        
    }
};

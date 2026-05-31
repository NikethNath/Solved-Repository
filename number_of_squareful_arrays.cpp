class Solution {
public:
    bool is_sqrt(int val){
        int root=sqrt(val);
        if(root*root==val) return true;
        if((root+1)*(root+1)==val)return true;
        return false;

    }
    int factorial(int n){
        if(n==1) return 1;
        return n* factorial(n-1);
    }
    int rf(int mask,int prev, vector<vector<int>> &adj,vector<vector<int>>&dp){
        if(mask==((1<<adj.size())-1)){
            return 1;
        }
        if(dp[mask][prev]!=-1){
            return dp[mask][prev];
        }
        int ans=0;

        for(int nbr : adj[prev]){
            if((mask & (1<<nbr))==0){
                ans+= rf(mask | (1<<nbr),nbr,adj,dp);
            }
        }
        return dp[mask][prev]=ans;


    }
    int numSquarefulPerms(vector<int>& nums) {
        vector<vector<int>> adj(nums.size());
        unordered_map<int,int> mpp;
        for(int i=0 ; i<nums.size() ; i++){
            mpp[nums[i]]++;
        }
        for(int i=0 ; i<nums.size() ; i++){
            for(int j=i+1 ; j<nums.size() ; j++){
                int temp=nums[i] +nums[j];
                if(is_sqrt(temp)){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }

            }
        }
        int ans=0;
        vector<vector<int>> dp(1<<nums.size(),vector<int> (nums.size()+1,-1));
        for(int i=0 ; i<nums.size() ; i++){
            ans+= rf((1<<i),i,adj,dp);

        }
        for(auto p : mpp){
            ans=ans/factorial(p.second);
        }
        return ans;
        
        
    }
};

class Solution {
public:
    int rf(int index, int target, vector<int> &coins,vector<vector<int>> &dp){
        if(target==0) return 0;
        if(index==coins.size()-1){
            if(target%coins[index]==0){
                return target/coins[index];

            }
            return 1e9;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        int take=1e9;
        int skip=1e9;
        if(coins[index]<=target){
            take= 1+rf(index,target-coins[index],coins,dp);

        }
        skip=rf(index+1,target,coins,dp);
        return dp[index][target]=min(take,skip);

    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans= rf(0,amount,coins,dp);
        if(ans==1e9) return -1;
        return ans;
    }
};

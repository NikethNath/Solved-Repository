class Solution {
public:
    int rf(int index,int target,vector<int>&nums,vector<vector<int>> &dp){
        if(index==nums.size()){
            if(target==0) return 1;
            return 0;
        }
        if(dp[index][target+100000]!=-1) return dp[index][target+100000];
        int plus=rf(index+1,target+nums[index],nums,dp);
        plus+=rf(index+1,target-nums[index],nums,dp);
        return dp[index][target+100000]=plus;


    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(),vector<int>(200000,-1));
        return rf(0,target,nums,dp);
        
    }
};

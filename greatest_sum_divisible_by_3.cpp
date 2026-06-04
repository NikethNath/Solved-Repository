class Solution {
public:
    int rf(int index,int rem,vector<int> &nums,vector<vector<int>> &dp){
        if(index>nums.size()-1){
            if(rem==0) return 0;
            return -1e9;
        }
        if(dp[index][rem]!=-1) return dp[index][rem];
        int ans=-1e9;
        ans=max(ans, rf(index+1,rem,nums,dp));
        ans=max(ans, (nums[index] + rf(index+1,(nums[index]+rem)%3,nums,dp)));
        return dp[index][rem]=ans;
    }


    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(3,-1));
        return rf(0,0,nums,dp);
        
    }
};

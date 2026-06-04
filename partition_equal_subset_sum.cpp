class Solution {
public:
    bool rf(int index, int target, vector<int> &nums,vector<vector<int>> &dp){
        if(index>nums.size()-1){
            if(target==0) return true;
            return false;
        }
        if(dp[index][target]!=-1) return dp[index][target];

        bool ans=false;
        
        ans |= rf(index+1,target,nums,dp);
        if(nums[index]<=target){
            ans |= rf(index+1,target-nums[index],nums,dp);
        }

        return dp[index][target]=ans;


    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        vector<vector<int>> dp(nums.size()+1, vector<int>((sum/2)+2,-1));
        return rf(0,sum/2,nums,dp);
        
    }
};

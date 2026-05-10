class Solution {
public:
    int rf(int index,vector<int> &nums,int target,vector<int>&dp){
        if(index==nums.size()-1) return 0;
        if(dp[index]!=-1) return dp[index];
        int maxval=-1e9;

        for(int i=index+1 ; i<nums.size() ; i++){
            if(abs(nums[i]-nums[index])<=target){
                maxval=max(maxval,1+rf(i,nums,target,dp));
            }
        }
        return dp[index]=maxval;

    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(),-1);
        
        int ans=rf(0,nums,target,dp);
        if(ans<0) return -1;
        return ans;
        
    }
};

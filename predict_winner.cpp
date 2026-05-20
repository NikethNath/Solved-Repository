class Solution {
public:
    int rf(int l, int r,vector<int> &nums, vector<int> &pref,vector<vector<int>> &dp){
        if(l==r) return nums[l];
        if(dp[l][r]!=-1) return dp[l][r];
        int suffix=pref[r]-pref[l]+nums[l];
        int left=suffix-rf(l+1,r,nums,pref,dp);
        int right=suffix-rf(l,r-1,nums,pref,dp);
        return dp[l][r]=max(left,right);
    }
    bool predictTheWinner(vector<int>& nums) {
        vector<int> pref(nums.size(),0);
        pref[0]=nums[0];
        for(int i=1 ; i<nums.size() ; i++){
            pref[i]=pref[i-1] + nums[i];
        }
        vector<vector<int>> dp(nums.size()+1,vector<int> (nums.size()+1,-1));
        int p1= rf(0,nums.size()-1,nums,pref,dp);
        int p2=pref[nums.size()-1]-p1;
        if(p1>=p2) return true;
        return false;
        
    }
};

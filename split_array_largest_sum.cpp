class Solution {
public:
    int rf(int index,int k ,vector<int> &nums, vector<int> &pref,vector<vector<int>> &dp){
        if(index>nums.size()-1) return 1e9;
        if(k==1) return pref[nums.size()-1]-pref[index]+nums[index];
        if(dp[index][k]!=-1) return dp[index][k];
        int ans=1e9;

        for(int i=index ; i<nums.size() ; i++){
            ans=min(ans,max(pref[i]-pref[index]+nums[index],rf(i+1,k-1,nums,pref,dp)));

        }
        return dp[index][k]=ans;




    }
    int splitArray(vector<int>& nums, int k) {
        vector<int> prefix(nums.size(),0);
        prefix[0]=nums[0];
        int colsize=min((int)nums.size()+1,51);
        vector<vector<int>> dp(nums.size()+1,vector<int>(colsize,-1));
        for(int i=1 ; i<nums.size() ; i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        return rf(0,k,nums,prefix,dp);
        
    }
};

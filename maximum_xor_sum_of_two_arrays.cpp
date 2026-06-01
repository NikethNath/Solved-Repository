class Solution {
public:
    int rf(int index,int mask,vector<int> &nums1, vector<int> &nums2,vector<vector<int>>&dp){
        if(mask==((1<<nums2.size())-1) ){
            return 0;
        }
        if(index>nums1.size()-1) return 0;
        if(dp[index][mask]!=INT_MAX) return dp[index][mask];
        int ans=1e9;
        for(int i=0 ; i<nums2.size() ; i++){
            if((mask & (1<<i))==0){
                ans=min(ans,(nums1[index] ^ nums2[i] )+ rf(index+1,mask  | (1<<i),nums1,nums2,dp));
            }
        }
        return dp[index][mask]=ans;
    }
    
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int> (1<<nums1.size(),INT_MAX));
        return rf(0,0,nums1,nums2,dp);
        
    }
};

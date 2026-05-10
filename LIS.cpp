class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()+1);
        dp[0]=-1e9;
        dp[1]=nums[0];
        int right=2;
        for(int i=1 ;i<nums.size() ; i++){
            if(dp[right-1]<nums[i]){  // if we have a big number increment it
                dp[right]=nums[i];
                right++;
            }
            else{    
                int ptr=right;
                while(dp[ptr-1]>=nums[i]){
                    ptr--;
                }
                dp[ptr]=min(nums[i],dp[ptr]);
            }
        }
        return right-1;
        
    }
};

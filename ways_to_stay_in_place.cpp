class Solution {
public:
    int modulo=1e9+7;
    int rf(int index, int steps,int arrLen,vector<vector<int>> &dp){
        if(index<0 | index>arrLen-1) return 0;
        if(steps==0){
            if(index==0) return 1;
            return 0;
        }
        if(dp[index][steps]!=-1) return dp[index][steps];
        long long int ans=0;
        ans=(ans+rf(index,steps-1,arrLen,dp))% modulo;
        ans=(ans+rf(index+1,steps-1,arrLen,dp))%modulo;
        ans=(ans+rf(index-1,steps-1,arrLen,dp))% modulo;
        return dp[index][steps]=ans;

    }
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps+2,vector<int>(steps+2,-1));
        return rf(0,steps,arrLen,dp);
        
    }
};

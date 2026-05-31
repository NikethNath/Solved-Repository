class Solution {
public:
    bool rf(int n,vector<int> &dp){
        if(n<=0) return false;
        if(dp[n]!=-1)return dp[n];

        for(int i=1 ; i<n ; i++){
            if(n%i==0){
                if(!rf(n-i,dp)){
                    return dp[n]=true;
                }

            }
        }
        return dp[n]=false;
    }
    bool divisorGame(int n) {
        vector<int> dp(n+1,-1);
        return rf(n,dp);
        
    }
};

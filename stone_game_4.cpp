class Solution {
public:
    bool rf(int n,vector<int> &dp){
        if(n==0) return false;
        if(dp[n]!=-1) return dp[n];
        bool ans=false;
        for(int i=1 ;i<=pow(n,.5); i++){
            if(!rf(n-(i*i),dp)){
                ans=true;

            }

        }
        return dp[n]=ans;

    }
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,-1);
        return rf(n,dp);
        
        
    }
};

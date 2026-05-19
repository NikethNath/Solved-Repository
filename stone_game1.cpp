class Solution {
public:
    int rf(int l, int r, vector<int> &piles,vector<vector<int>> &dp){
        if(l==r) return piles[l];
        if(dp[l][r]!=-1) return dp[l][r];
        int ans=-1e9;
        ans=max(ans,piles[l]-rf(l+1,r,piles,dp));
        ans=max(ans,piles[r]-rf(l,r-1,piles,dp));
        return dp[l][r]=ans;
    }
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>>dp(piles.size()+1,vector<int>(piles.size()+1,-1));
        if(rf(0,piles.size()-1,piles,dp)>0) return true;
        return false;
        
    }
};

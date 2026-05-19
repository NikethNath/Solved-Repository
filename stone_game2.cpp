class Solution {
public:
    int rf(int index,int M,vector<int>&piles,vector<int> &prefixsums,vector<vector<int>> &dp){
        if(index+ (2*M)-1 >= piles.size()-1){
            return prefixsums[piles.size()-1]-prefixsums[index]+piles[index];
        }
        if(dp[index][M]!=-1) return dp[index][M];
        int val=-1e9;
        for(int i=0 ; i<(2*M) ; i++){
            if(index+i+1<=piles.size()-1){
            int suffix=prefixsums[piles.size()-1]-prefixsums[index]+piles[index];
            val=max(val,(suffix-rf(index+i+1,max(i+1,M),piles,prefixsums,dp)));
            }
            else break;

        }
        return dp[index][M]=val;


    }
    int stoneGameII(vector<int>& piles) {
        vector<int> prefixsums(piles.size(),0);
        prefixsums[0]=piles[0];
        for(int i=1; i<piles.size() ; i++){
            prefixsums[i]=prefixsums[i-1]+piles[i];
        }
        vector<vector<int>> dp(piles.size()+1,vector<int>(piles.size()+1,-1) );
        return rf(0,1,piles,prefixsums,dp);

        
    }
};

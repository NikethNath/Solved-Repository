class Solution {
public:
    int rf(int index, int transactionsleft,int canbuy,vector<int> &prices,vector<vector<vector<int>>> &dp){
        if(transactionsleft==0) return 0;
        if(index==prices.size()-1){
            if(canbuy) return 0;
            return prices[index];
        }
        if(dp[index][transactionsleft][canbuy]!=-1) return dp[index][transactionsleft][canbuy];
        int skip=rf(index+1,transactionsleft,canbuy,prices,dp);
        int doop=0;
        if(canbuy){
            doop=-prices[index]+ rf(index+1,transactionsleft,0,prices,dp);
        }
        else{
            doop=prices[index]+rf(index,transactionsleft-1,1,prices,dp);
        }
        return dp[index][transactionsleft][canbuy]=max(doop,skip);


    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>> (k+1,vector<int>(2,-1)));
        return rf(0,k,1,prices,dp);
        
    }
};

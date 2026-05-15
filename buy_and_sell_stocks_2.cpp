class Solution {
public:
    int rf(int index,int canbuy,vector<int> &prices,vector<vector<int>> &dp){
        if(index==prices.size()-1 ){
            if(canbuy){
                return 0;
            }
            else{
                return prices[index];
            }
        }
        if(dp[index][canbuy]!=-1) return dp[index][canbuy];
        int doop=0;
        int skip=rf(index+1,canbuy,prices,dp);
        if(canbuy){
             doop=-prices[index]+rf(index+1,0,prices,dp);

        }
        else{
            doop=prices[index]+rf(index,1,prices,dp); //sell

        }
        return dp[index][canbuy]=max(doop,skip);

    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+2,vector<int>(3,-1));
        return rf(0,1,prices,dp);

        
    }
};

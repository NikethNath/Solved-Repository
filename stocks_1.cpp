class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        vector<int> highestinfuture(prices.size());https://github.com/NikethNath/Solved-Repository/tree/main
        int maks=prices[prices.size()-1];
        for(int i=prices.size()-1 ; i>=0  ; i--){
            highestinfuture[i]=maks;
            maks=max(maks,prices[i]);
        }
        for(int num : highestinfuture){
            cout<<num<<" ";
        }
        for(int i=0 ; i<prices.size() ; i++){
            ans=max(ans,highestinfuture[i]-prices[i]);

        }
        return ans;
        
    }
};

class Solution {
public:
    int rf(int index,vector<int> &stoneValue,vector<int> &prefix,vector<int> &dp){
        int lastidx=stoneValue.size()-1;
        if(index>lastidx) return 0;
        if(dp[index]!=-1) return dp[index];

        int ans=-1e9;
        int suffix=prefix[lastidx]-prefix[index]+stoneValue[index];
        for(int i=1 ;i<=3 ; i++){
            ans=max(ans,suffix-rf(index+i,stoneValue,prefix,dp));

        }
        return dp[index]=ans;


    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> prefix(n,0);
        prefix[0]=stoneValue[0];
        for(int i=1 ; i<n ; i++){
            prefix[i]=prefix[i-1]+stoneValue[i];
        }
        vector<int> dp(stoneValue.size()+1,-1);
        int alice=rf(0,stoneValue,prefix,dp);
        int bob= prefix[stoneValue.size()-1]-alice;
        if(alice==bob) return "Tie";
        if(alice>bob) return "Alice";
        else return "Bob";
        
    }
};

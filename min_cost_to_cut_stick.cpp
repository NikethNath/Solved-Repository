class Solution {
public:
    int rf(int l,int r,vector<int> &cuts,vector<vector<int>> &dp, unordered_map<int,int> &mpp){
        if(r-l<=1) return 0;
        if(dp[mpp[l]][mpp[r]]!=-1) return dp[mpp[l]][mpp[r]];

        int ans=1e9;
        for(int i=upper_bound(cuts.begin(),cuts.end(),l)-cuts.begin() ; i<cuts.size() && cuts[i]<r ; i++){
            ans=min(ans,  r-l + rf(l,cuts[i],cuts,dp,mpp) + rf(cuts[i],r,cuts,dp,mpp));
        }
        if(ans==1e9) return dp[mpp[l]][mpp[r]]=0;
        return dp[mpp[l]][mpp[r]]=ans;

    }
    int minCost(int n, vector<int>& cuts) {
        unordered_map<int,int> mpp;
        mpp[0]=0;
        int i=0;
        for(;i<cuts.size() ; i++){
            mpp[cuts[i]]=i+1;
        }
        i++;
        mpp[n]=i;
        vector<vector<int>> dp(cuts.size()+4,vector<int>(cuts.size()+4,-1));
        sort(cuts.begin(),cuts.end());
        return rf(0,n,cuts,dp,mpp);
        
    }
};

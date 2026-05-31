class Solution {
public:
    bool rf(int l,int r, string s, string t,vector<vector<int>> &dp){
        if(l>s.length()-1) return true;
        if(r>t.length()-1) return false;
        if(dp[l][r]!=-1)return dp[l][r];
        bool ans=false;
        if(s[l]==t[r]){
            ans |= rf(l+1,r+1,s,t,dp);
        }
        ans |= rf(l,r+1,s,t,dp);

        return dp[l][r]=ans;
    }
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.length()+2,vector<int> (t.length()+2,-1));
        if(s.length()==0) return true;
        if(t.length()==0) return false;
        return rf(0,0,s,t,dp);
        
    }
};

class Solution {
public:
    int rf(int x, int y , string &text1, string &text2,vector<vector<int>> &dp){
        if(x> text1.length() || y>text2.length()) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        int take=-1e9;
        int skip=-1e9;
        if(text1[x]==text2[y]){
            take=1+rf(x+1,y+1,text1,text2,dp);
        }
        skip=max(rf(x+1,y,text1,text2,dp),rf(x,y+1,text1,text2,dp));
        return dp[x][y]=max(take,skip);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        int ans=rf(0,0,text1,text2,dp);
        if(ans==-1e9)return 0;
        return ans-1;

        
    }
};

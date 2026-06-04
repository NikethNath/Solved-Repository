class Solution {
public:
    int checkchanges(string s, int l, int r){
        int ans=0;
        while(l<r){
            if(s[l]!=s[r]) ans++;
            l++;
            r--;
        }
        return ans;
    }

    int rf(int index,int k,string s,vector<vector<int>> &dp){
        if(index>s.length()-1){
            return 1e9;
        }
        if(k==1){
            return checkchanges(s,index,s.length()-1);
        }
        if(dp[index][k]!=-1) return dp[index][k];
        int ans=1e9;

        for(int i=index ; i<s.length() ; i++){
            ans=min(ans,checkchanges(s,index,i)+rf(i+1,k-1,s,dp));

        }
        return dp[index][k]=ans;

    }


    int palindromePartition(string s, int k) {
        vector<vector<int>> dp(s.length()+1,vector<int>(k+1,-1));
        if(rf(0,k,s,dp)==1e9) return 0;
        return rf(0,k,s,dp);
        
    }
};

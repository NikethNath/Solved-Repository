class Solution {
public:
    int rf(int x,int y,int m,int n,vector<vector<int>> &dp){   //ways from xy to end
        if(x>m-1 || y>n-1) return 0;
        if(x==m-1 && y==n-1) return 1;
        if(dp[x][y]!=-1) return dp[x][y];
        return dp[x][y]=rf(x+1,y,m,n,dp) + rf(x,y+1,m,n,dp);


    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return rf(0,0,m,n,dp);
        
    }
};

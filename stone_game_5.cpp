class Solution {
public:
    int rf(int l, int r,vector<int> &prefix,vector<int>& stoneValue,vector<vector<int>> &dp){
        if(l==r) return 0;
        if((dp[l][r])!=-1) return dp[l][r];
        int ans=0;
        for(int k=l ; k<r ; k++){
            int leftsum=prefix[k]-prefix[l]+stoneValue[l];
            int rightsum=prefix[r]-prefix[k+1]+stoneValue[k+1];
            if(rightsum<leftsum){
                ans=max(ans,rightsum+ rf(k+1,r,prefix,stoneValue,dp));

            }
            if(leftsum<rightsum){
                ans=max(ans,leftsum +rf(l,k,prefix,stoneValue,dp));

            }
            if(leftsum==rightsum){
                ans=max(ans,leftsum+ max(rf(l,k,prefix,stoneValue,dp),rf(k+1,r,prefix,stoneValue,dp)));
            }

        }
        return dp[l][r]=ans;


    }
    int stoneGameV(vector<int>& stoneValue) {
        vector<int> prefix(stoneValue.size());
        prefix[0]=stoneValue[0];
        for(int i=1 ; i<stoneValue.size() ; i++){
            prefix[i]=prefix[i-1]+stoneValue[i];
        }
        vector<vector<int>> dp(stoneValue.size()+1,vector<int>(stoneValue.size()+1,-1));
        return rf(0,stoneValue.size()-1,prefix,stoneValue,dp);
        
    }
};

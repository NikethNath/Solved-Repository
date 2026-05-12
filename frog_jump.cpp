class Solution {
public:
    bool rf(int index,int k,unordered_map<int,int> &mpp, vector<int> &stones,vector<vector<int>> &dp){
        if(index==stones.size()-1) return true;
        if(dp[index][k]!=-1){
            return dp[index][k];
        } 
        bool ans=false;
        vector<int> jumps;
        for(int i=k-1 ; i<=k+1 ; i++){
            if(i>0)jumps.push_back(i);
        }
        for(int jump : jumps){
            if(mpp.count(stones[index]+jump) && mpp[stones[index]+jump] > index){
                ans|= rf(mpp[stones[index]+jump],jump,mpp,stones,dp);
            }
        }
        if(ans){
            return dp[index][k]=1;
        }
        return dp[index][k]=0;

    }
    bool canCross(vector<int>& stones) {
        unordered_map<int,int>mpp;  //stoneval, index
        for(int i=0 ; i<stones.size() ; i++){
            mpp[stones[i]]=i;

        }
        vector<vector<int>> dp(stones.size(),vector<int>(stones.size()+1,-1));
        return rf(0,0,mpp,stones,dp);

        
    }
};

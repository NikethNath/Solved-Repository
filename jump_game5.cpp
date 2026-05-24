class Solution {
public:
    int rf(int index,int d,vector<int> &arr,vector<int>&dp){
        int sum=0;
        if(dp[index]!=-1)return dp[index];
        for(int i=1; i<=d ; i++){
            if(index+i<=arr.size()-1 && arr[index+i]<arr[index]){
                sum=max(sum,1+rf(index+i,d,arr,dp));
            }
            else break;

        }
        for(int i=1; i<=d ; i++){
            if(index-i>=0 && arr[index-i]<arr[index]){
                sum=max(sum,1+rf(index-i,d,arr,dp));
            }
            else break;

        }
        return dp[index]=sum;
    }
    int maxJumps(vector<int>& arr, int d) {
        vector<int> dp(arr.size(),-1);
        int ans=0;
        for(int i=0 ; i<arr.size() ; i++){
            ans=max(ans,rf(i,d,arr,dp));
        }
        return ans+1;
        
    }
};

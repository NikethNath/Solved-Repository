#include <bits/stdc++.h>
using namespace std;    

int rf(int index, int mask, vector<vector<int>> &table,vector<vector<int>> &dp){ 
    if(index>table.size()-1){
        return 0;
    }
    if(dp[index][mask]!=-1) return dp[index][mask];
    int ans=-1e9;
    ans=max(ans,rf(index+1,mask,table,dp));
    for(int i=0 ; i<table[0].size() ; i++){
        if((mask & (1<<i))==0){
            ans=max(ans,table[index][i]+rf(index+1,mask | (1<<i),table,dp));
        }

    }
    return dp[index][mask]=ans;

    
}

int main() {
    int t;
    cin>>t;
    for(int k=0 ; k<t ; k++){
        int m,n;
        cin>>n>>m;
        vector<vector<int>> table(m,vector<int>(n,0));
        vector<vector<int>> dp(m+1, vector<int> ((1<<(n+1)),-1));
        for(int i=0 ; i<m  ; i++){
            for(int j=0 ; j<n ; j++){
                int temp;
                cin>>temp;
                table[i][j]=temp;
    
            }
        }
        cout<<rf(0,0,table,dp);
        cout<<"\n";
        
    }
}

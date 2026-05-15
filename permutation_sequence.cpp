class Solution {
public:
    void rf(int index,string &ans,int n, int k,map<int,bool> &used,vector<int>&fact){
        if(index==n) return;

        int leftoverdigits=n-index-1;
        int rankmultiplier=fact[leftoverdigits];
        vector<int> available;
        for(auto p : used){
            if(p.second==false){
                available.push_back(p.first);
            }
        }
        int i=0;
        while(i<available.size() && i*rankmultiplier<k){
            i++;
            
        }
        i--;
        ans.push_back(char(available[i]+'0'));
        used[available[i]]=true;
        rf(index+1,ans,n,k-(i*rankmultiplier),used,fact);

    }
    string getPermutation(int n, int k) {
        string ans="";
        map<int,bool> used;
        for(int i=1 ; i<=n ; i++){
            used[i]=false;
        }
        vector<int> fact(n,1);
        for(int i=1 ; i<n ; i++){
            fact[i]=fact[i-1]*i;
        }
        rf(0,ans,n,k,used,fact);
        return ans;
        
    }
};

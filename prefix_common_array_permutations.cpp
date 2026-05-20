class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans(A.size(),0);
        unordered_map<int,int> mpp;
        for(int i=1 ;i<=A.size() ; i++){
            mpp[i]=2;

        }
        int l=A.size()-1;
        int count=A.size();
        ans[l]=count;
        l--;
        while(l>=0){
            if(mpp[A[l+1]]==2){
                mpp[A[l+1]]=1;
                count--;
            }
            if(mpp[B[l+1]]==2){
                mpp[B[l+1]]=1;
                count--;
            }
            ans[l]=count;
            l--;
        
        }
        return ans;
        
    }
};

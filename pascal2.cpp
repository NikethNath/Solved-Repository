class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1,0);
        ans[0]=1;
        for(int k=0 ; k<rowIndex ; k++){
        for(int i=rowIndex ; i>=1 ; i--){
            ans[i]=ans[i-1]+ans[i];

        }

        }
        return ans;
        
    }
};

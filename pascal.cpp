class Solution {
public:
    vector<int> nextlayer(vector<int> a){
        vector<int> ans(a.size()+1,1);
        for(int i=0 ; i<a.size()-1 ; i++){
            ans[i+1]=a[i]+a[i+1];

        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=1 ;i<numRows ; i++){
            ans.push_back(nextlayer(ans[ans.size()-1]));
        }
        return ans;
        
    }
};

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        map<int,int> mpp;
        for(int a : nums ){
            mpp[a]++;
        }
        for(auto p : mpp){
                int freq=p.second;
            int val=p.first;
            freq=min(k,freq);
                for(int i=0 ;i<freq ; i++){
                ans.push_back(val);
            }
        }
    return ans;
        
    }
};

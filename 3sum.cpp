class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> stt;
        vector<vector<int>> ans;
        for(int i=0 ; i<n ; i++){
            int l=i+1;
            int r=n-1;
            while(l<r){
                int temp=nums[i]+nums[l]+nums[r];
                if(temp==0){
                    stt.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
                if(temp>0){
                    r--;
                    continue;
                }
                if(temp<0){
                    l++;
                    continue;
                }
            }
        }
        for(auto a :  stt){
            ans.push_back(a);
        }
        return ans;
    }
};

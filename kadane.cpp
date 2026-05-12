class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l=0;
        int r=0;
        int sum=0;
        int ans=-1e6;
        for(r=l ; r<nums.size(); ){
            sum+=nums[r];
            r++;
            ans=max(ans,sum);
            if(sum<0){
                sum=0;
                l=r;
            }
        }
        return ans;
        
    }
};

class Solution {
public:
    int ans=1e9;
    int bs(int l,int r, vector<int>&nums){
        if(r-l==0){
            return nums[l];

        }
        if(r-l==1){
            return min(nums[l],nums[r]);
        }
        int mid=l+((r-l)/2);
        if(nums[l]<=nums[mid] && nums[mid]<=nums[r]){
            return nums[l];

        }
        if(nums[l]<=nums[mid]){
            return bs(mid,r,nums);
        }
        if(nums[l]>nums[mid]){
            return bs(l,mid,nums);

        }
        return -1;
    }
    int findMin(vector<int>& nums) {
        return bs(0,nums.size()-1,nums);
        
    }
};

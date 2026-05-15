class NumArray {
public:
    vector<int> prefixarr;
    vector<int> nums;
    NumArray(vector<int>& nums) {
        prefixarr.resize(nums.size());
        prefixarr[0]=nums[0];
        for(int i=1; i<nums.size() ; i++){
            prefixarr[i]=prefixarr[i-1]+nums[i];
        }
        this->nums=nums;
        
    }
    
    int sumRange(int left, int right) {
        return prefixarr[right]-prefixarr[left] + nums[left];
        
    }
};

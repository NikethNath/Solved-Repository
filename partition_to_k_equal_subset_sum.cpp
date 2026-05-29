class Solution {
public:
    bool rf(int index,int length,int k,int target,int mask,vector<int> &nums){
        if(k==0) return true;
        if(length==target) return  rf(0,0,k-1,target,mask,nums);
        if(index>nums.size()-1) return false;

        bool ans=false;
        if((mask &(1<<index))==0 && nums[index]+length<=target){
            if(rf(index+1,length+nums[index],k,target,mask | (1<<index),nums)){
                return true;
            }
        }
        ans|= rf(index+1, length,k,target,mask,nums);
        return ans;


    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        vector<bool> used(nums.size()+1,false);
        int target=accumulate(nums.begin(),nums.end(),0);
        if(target%k!=0) return false;
        target=target/k;
        return rf(0,0,k,target,0,nums);
        
    }
};

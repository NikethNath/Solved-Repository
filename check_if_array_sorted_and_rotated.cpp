class Solution {
public:
    bool check(int smallestidx,int t,vector<int> &nums){
        while(t){
            if(nums[(smallestidx+1)%nums.size()]<nums[smallestidx]) return false;
            t--;
            smallestidx=(smallestidx+1)%nums.size();
        }
        return true;
        

    }
    bool check(vector<int>& nums) {
        int smallestidx=0;
        int smallestval=102;
        for( int i=0 ; i<nums.size() ; i++){
            if(nums[i]<smallestval){
                smallestval=nums[i];
                smallestidx=i;
            }
        }
        vector<int> smalls;
        for(int i=0 ;i<nums.size() ; i++){
            if(nums[i]==smallestval) smalls.push_back(i);
        }
        int t=nums.size()-1;
        for(int idx: smalls){
            if(check(idx,t,nums)) return true;
        }
        return false;
        
    }
};

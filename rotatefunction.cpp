class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0;
        int ans=0;
        int prevans=0;
        for(int i=0 ; i< nums.size() ; i++){
            prevans+=(nums[i]*i);
            sum+=nums[i];
        }
        ans=prevans;
        for(int i=1 ; i<nums.size() ; i++){
            int newans=prevans + sum - (nums.size() * nums[nums.size()-i]);
            ans=max(ans,newans);
            prevans=newans;
        }
        return ans;
 
    }
};

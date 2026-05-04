class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int a=0;
        for(int i=0 ; i< nums.size()+1 ; i++ ){
            a=a ^ i;
        }
        for(int b : nums){
            a=a^b;
        }
        return a;  
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int rotateandshift=0;
        int shiftandrotate=0;
        int zeroidx=0;
        for(int i=0 ;i<nums.size() ; i++){
            if(nums[i]==0){
                zeroidx=i;
            }
        }
        bool asc=true;
        bool desc=true;
        int idx=zeroidx;
        int n=nums.size();
        for(int i=0 ; i<nums.size()-1 ; i++){
                int nextidx = (idx + 1) % n;
                if(nums[nextidx] != nums[idx] + 1) asc = false;
                idx = nextidx;  // move AFTER checking
        }
        idx=zeroidx;
        for(int i=0 ; i<nums.size()-1 ; i++){
            int nextidx = (idx - 1 + n) % n;
            if(nums[nextidx] != nums[idx] + 1) desc = false;
            idx = nextidx;  // move AFTER checking
            
        }
        if(!asc && !desc) return -1;
        if(asc){
            int shift=zeroidx;
            int rotateshiftrotate=2+(nums.size()-zeroidx);
            return min(shift,rotateshiftrotate);
        }
        else{
             rotateandshift=nums.size()-zeroidx;
             shiftandrotate=zeroidx+1+1;
            return min(rotateandshift,shiftandrotate);
            
        }
        

        
        
    }
};

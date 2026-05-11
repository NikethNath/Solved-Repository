class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int num : nums){
            stack<int> stk;
            while(num!=0){
                stk.push(num%10);
                num=num/10;
            }
            while(!stk.empty()){
                ans.push_back(stk.top());
                stk.pop();
            
            }
        }
        return ans;
        
    }
};

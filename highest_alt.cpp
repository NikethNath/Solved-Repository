class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int curralt=0;
        for(int a : gain){
            curralt+=a;
            ans=max(ans,curralt);
        }
        return ans;
    }
};

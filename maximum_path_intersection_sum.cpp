class Solution {
public:
int kadaneAtLeastTwo(vector<int>& v) {
    int n = v.size();
    if (n < 2) return INT_MIN;

    int prev = v[0] + v[1];
    int ans = prev;

    for (int i = 2; i < n; i++) {
        int curr = max(prev + v[i], v[i-1] + v[i]);
        ans = max(ans, curr);
        prev = curr;
    }

    return ans;
}
    int maxScore(vector<vector<int>>& grid) {
        int ans=-1e9;
        for(auto v : grid){
            ans=max(ans,kadaneAtLeastTwo(v));
        }
        for(int j=0 ; j< grid[0].size() ; j++){
        vector<int> temp;
        for(int i=0 ; i<grid.size() ; i++){
            temp.push_back(grid[i][j]);
        }
        ans=max(ans,kadaneAtLeastTwo(temp));

        }
        return ans;
        
    }
};

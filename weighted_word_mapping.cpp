class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(string s : words){
            int weightsum=0;
            for(char c : s){
                weightsum+= weights[int(c-'a')];

            }
            weightsum%=26;
            ans.push_back(char(25-weightsum +'a'));
        }
        return ans;
        
    }
};

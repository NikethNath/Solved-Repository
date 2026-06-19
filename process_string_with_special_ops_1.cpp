class Solution {
public:
    string processStr(string s) {
        string res="";
        for(char c : s){
            if(c=='*'){
                if(res.length()>=1){
                    res.pop_back();
                }
                continue;
            }
            if(c=='#'){
                int len=res.size();
                for(int i=0 ; i<len ; i++){
                    res.push_back(res[i]);
                    
                }
                continue;

            }
            if(c=='%'){
                int len=res.size();
                for(int i=0 ; i<len/2 ; i++){
                    swap(res[i],res[len-1-i]);
                }
                continue;

            }
            else{
                res.push_back(c);
                // cout<<c<<" ";
            }
        }
        return res;
        
    }
};

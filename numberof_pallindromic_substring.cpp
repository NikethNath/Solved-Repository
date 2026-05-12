class Solution {
public:
    int numpallindromes(int i,string &s){
        int l=i;
        int r=i;
        int ans=0;
        while(l>=0 && r<s.length() && s[l]==s[r]){
            ans++;
            l--;
            r++;
        }
        l=i;
        r=i+1;
        while(l>=0 && r<s.length() && s[l]==s[r]){
            ans++;
            l--;
            r++;
        }
        return ans;

    }
    int countSubstrings(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0 ; i<n ; i++){
            ans+=numpallindromes(i,s);
        }
        return ans;
        
    }
};

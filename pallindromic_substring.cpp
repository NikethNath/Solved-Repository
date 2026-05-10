class Solution {
public:
    pair<int,int> pallindrome_evenlength(int n, string &s){
        int left=n;
        int right=n+1;
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        left++;
        right--;
        if(left>right) return {0,0};
        return {left,right};
    }
    pair<int,int> pallindromelength(int n, string &s){
        int left=n;
        int right=n;
        while(left-1>=0 && right+1<s.length() && s[left-1]==s[right+1]){
            left--;
            right++;
        }
        return {left,right};


    }
    string longestPalindrome(string s) {
        int n=s.length();
        int ans=0;
        string ansstring="";
        if(s.length()==1) return s;
        for(int i=0 ; i<n ; i++){
            pair<int,int> temp=pallindromelength(i,s);
            pair<int,int> temp2=pallindrome_evenlength(i,s);
            cout<<temp.first<<" "<<temp.second<<",";
            cout<<temp2.first<<" "<<temp2.second<<",";
            int templength=temp.second-temp.first+1;
            int templength2=temp2.second-temp2.first+1;
            // cout<<templength<<" ";
            if (templength>ans){
                ansstring=s.substr(temp.first,templength);
                ans=templength;
                
            }
            if (templength2>ans){
                ansstring=s.substr(temp2.first,templength2);
                ans=templength2;
                
            }


        }
        if(ansstring=="" && s.length()>=1){
            return ansstring+=s[0];

        }
        return ansstring;
        
    }
};

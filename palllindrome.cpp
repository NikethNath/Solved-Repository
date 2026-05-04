class Solution {
public:  // 65-A, 90 Z , 97-a , 122 z;  

    bool isPalindrome(string s) {
        string mystring="";
        for(char a : s){
            if(int(a)>=int('0') && int(a)<='9'){
                mystring.push_back(a);
                continue;
            }
            if(int(a)>122 || int(a)<65 || (int(a)>90 && int(a)<97 )){
                continue;
            }
            if(int(a)>=65 && int(a)<=90){
                mystring.push_back(a-'A'+'a');
            }

            else{
                mystring.push_back(a);
            }
        }
        for(int i=0 ; i<mystring.size()/2 ; i++){
            if(mystring[i]!=mystring[mystring.size()-i-1]) return false;
        }

        return true;;
    }
};

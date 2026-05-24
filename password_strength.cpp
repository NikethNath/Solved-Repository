class Solution {
public:
    int passwordStrength(string password) {
        vector<bool> lowercase(26,false);
        vector<bool> uppercase(26,false);
        vector<bool> digits(10,false);
        bool hash=false;
        bool dollar=false;
        bool  exclamation=false;
        bool at=false;
        int ans=0;

        for(int i=0 ; i<password.size() ; i++){
            
            if(int(password[i]-'a')>=0 && int(password[i]-'a')<=25){
                lowercase[int(password[i]-'a')]=true;
                continue;
            }
            if(int(password[i]-'A')>=0 && int(password[i]-'A')<=25){
                uppercase[int(password[i]-'A')]=true;
                continue;
            }
            if(int(password[i]-'0')>=0 && int(password[i]-'0')<=9){
                digits[int(password[i]-'0')]=true;
                continue;
            }
            if( password[i]=='!'){
                exclamation=true;
            continue;
            }
                        if( password[i]=='@'){
                at=true;
            continue;
            }
                        if( password[i]=='#'){
                hash=true;
            continue;
            }
                        if( password[i]=='$'){
                dollar=true;
            continue;
            }
        }
        for(bool a : lowercase){
            if(a) ans++;
        }
        for(bool a : uppercase){
            if(a) ans=ans+2;
        }
        for(bool a : digits){
            if(a) ans=ans+3;
        }
        if(hash) ans=ans+5;
        if(exclamation) ans=ans+5;
        if(dollar) ans=ans+5;
        if(at) ans=ans+5;

        return ans;
        
    }
};

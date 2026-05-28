class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> trav(26,0);
        vector<int> trav2(26,0);
        vector<int> lowercase(26,-1);
        vector<int> uppercase(26,-1);
        vector<bool>flag(26,false);
        int ans=0;
        for(char a : word){
            if(a>='A' && a<='Z'){
                trav[a-'A']=1;

            }
            else{
                trav2[a-'a']=1;
            }
        }
        for(int i=0 ; i<26 ; i++){
            if(trav[i]==1 && trav2[i]==1) ans++;
        }
        

        for(int i=0 ;i<word.length() ; i++){
            if(word[i]>='A' && word[i]<='Z'){
                uppercase[int(word[i]-'A')]=i;
                continue;
            }
                
            
            if(word[i]>='a' && word[i]<='z'){
                if(uppercase[word[i]-'a']!=-1 && !flag[word[i]-'a']){
                ans--;
                flag[word[i]-'a']=true;
                }
                    
                else{
                    lowercase[word[i]-'a']=i;
                }
            }
        }
        
        return ans;
        
    }
};

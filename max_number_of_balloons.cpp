class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b=0;
        int a=0;
        int l=0;
        int o=0;
        int n=0;
        for(char c : text){
            if(c=='b'){
                b++;
                continue;

            }
            if(c=='a'){
                a++;
                continue;

            }
                        if(c=='l'){
                            l++;
                            continue;
                
            }
                        if(c=='o'){
                            o++;
                            continue;
                
            }
                        if(c=='n'){
                            n++;
                            continue;

            }
        }
        l=l/2;
        o=o/2;
        return min({b,a,l,o,n});
        
    }
};

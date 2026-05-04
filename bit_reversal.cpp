class Solution {
public:
    int reverseBits(int n) {
        for(int i=0 ; i<32/2 ; i++){
            if((n&(1<<i))==0 && (n&(1<<(31-i)))!=0){
                n= n | (1<<i);
                n=  n ^ (1<<(31-i));
                continue;

                
            }
            if((n&(1<<i))!=0 && (n&(1<<(31-i)))==0){
                n= n | (1<<(31-i));
                n=  n ^ (1<<(i));
                continue;
            }
        }
        return n;
        
    }
};

class Solution {
public:
    bool diag(int currx,int curry,int queenx,int queeny){
        if(abs(currx-queenx)==abs(curry-queeny))return true;
        return false;
    }

    int rf(int level,int n,vector<int>&queenpos){
        if(level==n) return 1;
        int sum=0;
        for(int col=0 ; col<n ; col++){
            if(queenpos[col]==1e9){
                bool diagqueenpresent=false;
                for(int queen=0 ; queen<n ; queen++){
                    if(diag(level,col,queenpos[queen],queen)){
                        diagqueenpresent=true;
                        break;
                    }
                }
                if(!diagqueenpresent){
                    queenpos[col]=level;
                    sum+=rf(level+1,n,queenpos);
                    queenpos[col]=1e9;
                }
            }
            }
        return sum;
        }
    int totalNQueens(int n) {
        vector<int> queenpos(n,1e9);
        return rf(0,n,queenpos);

    }
};

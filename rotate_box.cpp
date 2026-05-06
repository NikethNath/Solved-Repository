class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int rows=boxGrid.size();
        int cols=boxGrid[0].size();
        vector<int> availableidx(rows,-1);
        for(int i=0 ; i<rows ; i++){
            for(int j=cols-1 ; j>=0 ; j--){
                if(boxGrid[i][j]=='.'){
                    availableidx[i]=j;
                    break;
                }
            }
        }

        for(int i=0  ; i< rows ; i++){
            for(int j=availableidx[i] ; j>=0 ;){
                if(boxGrid[i][j]=='.'){
                    j--;
                    continue;
                }
                if(boxGrid[i][j]=='*'){
                    while(j>=0 && boxGrid[i][j]!='.'){
                        j--;
                    }
                    availableidx[i]=j;
                    continue;
                }
                if(boxGrid[i][j]=='#'){
                    boxGrid[i][j]='.';
                    boxGrid[i][availableidx[i]]='#';
                    availableidx[i]--;
                    j--;
                }
            }
        }
        vector<vector<char>> ans(cols,vector<char>(rows));
        for(int i=0 ; i<rows/2 ; i++){
            swap(boxGrid[i],boxGrid[rows-i-1]);
        }
        for(int i=0 ; i<cols ; i++){
            for(int j=0 ; j<rows ; j++){
                ans[i][j]=boxGrid[j][i];
            }
        }
        return ans;
        
    }
};

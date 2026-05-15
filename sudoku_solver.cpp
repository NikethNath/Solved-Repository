class Solution {
public:
    vector<vector<int>> chunkthingy={{0,3,6},{1,4,7},{2,5,8}};


    int inwchunk(int x,int y){
        return chunkthingy[y/3][x/3];
    }


    bool rf(int index,vector<pair<int,int>> &indexes,vector<vector<bool>> &inrow, vector<vector<bool>> &incol, vector<vector<bool>> &inchunk,vector<vector<char>> &board){
        if(index== indexes.size()) return true;

        auto cordinate=indexes[index];
        int x=cordinate.first;
        int y=cordinate.second;
        int counter=0;
        for(int i=1 ; i<10 ; i++){
            if(!inrow[x][i] && !incol[y][i] && !inchunk[inwchunk(x,y)][i]){
                counter++;
                inrow[x][i]=true;
                incol[y][i]=true;
                inchunk[inwchunk(x,y)][i]=true;
                board[x][y]=char(i+'0');
                if(rf(index+1,indexes,inrow,incol,inchunk,board)){
                    return true;

                }
                board[x][y]='.';
                inchunk[inwchunk(x,y)][i]=false;
                incol[y][i]=false;
                inrow[x][i]=false;

            }

        }
        return false;
        
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> inrow(9,vector<bool>(10,false));
        vector<vector<bool>> incol(9,vector<bool>(10,false));
        vector<vector<bool>> inchunk(9,vector<bool>(10,false));
        vector<pair<int,int>> indexes;
        for(int i=0 ; i< 9 ; i++){
            for(int j=0 ; j<9 ; j++){
                if(board[i][j]!='.'){
                    inrow[i][int(board[i][j]-'0')]=true;
                    incol[j][int(board[i][j]-'0')]=true;
                }
                else{
                indexes.push_back({i,j});
                }
            }
        }
        int chunk=0;
        for(int i=0 ; i<3 ; i++){
            for(int j=0 ; j<3 ; j++){
                        int startx=i*3;
                        int starty=j*3;
                for(int k=0 ; k<3 ; k++){
                    for(int p=0 ; p<3 ; p++){
                        if(board[startx+k][starty+p]!='.'){
                        inchunk[chunk][int(board[startx+k][starty+p]-'0')]=true;
                        }
                        
                    }
                }
                chunk++;
            }
        }

        for(auto a : indexes){
            cout<<a.first<<","<<a.second<<" ";
        }
        bool ans=rf(0,indexes,inrow,incol,inchunk,board);
        return;
   
    }
};

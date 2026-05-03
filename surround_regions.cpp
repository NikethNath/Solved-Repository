class Solution {
public:
    void dfs(int x,int y, vector<vector<char>> &board, vector<vector<char>> &myboard){
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0 ; i<4 ; i++){
            int u=x+delrow[i];
            int v=y+delcol[i];
            if(u>=0 && v>=0 && u<board.size() && v<board[0].size() && board[u][v]=='O' && myboard[u][v]=='X'){
                myboard[u][v]='O';
                dfs(u,v,board,myboard);
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        int rows=board.size();
        int cols=board[0].size();
        vector<vector<char>> myboard(rows,vector<char>(cols,'X'));
        for(int i=0 ; i< rows ; i++){
            if(board[i][0]=='O' && myboard[i][0]=='X'){
            myboard[i][0]='O';
            dfs(i,0,board,myboard);
            }
            if(board[i][cols-1]=='O' && myboard[i][cols-1]=='X'){
            myboard[i][cols-1]='O';
            dfs(i,cols-1,board,myboard);
            }
        }
        for(int j=0 ; j<cols ; j++){
            if(board[0][j]=='O' && myboard[0][j]=='X'){
            myboard[0][j]='O';
            dfs(0,j,board,myboard);
            }
            if(board[rows-1][j]=='O'&& myboard[rows-1][j]=='X'){
            myboard[rows-1][j]='O' ;
            dfs(rows-1,j,board,myboard);
            }

        }
        board=myboard;
        return;

    }
};

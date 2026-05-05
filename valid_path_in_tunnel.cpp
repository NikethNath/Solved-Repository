class Solution {
public:
    int ans=false;
    bool  bcheck(int x, int y , int rows, int cols){
        if(x>=0 && y>=0 && x<rows && y<cols) return true;
        return false;

    }
    void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &vis,unordered_map<int,bool> &up,unordered_map<int,bool> &down,unordered_map<int,bool> &left,unordered_map<int,bool> &right){
        if(x==grid.size()-1 && y==grid[0].size()-1) ans=true;
        int gridval=grid[x][y];
        if(up[gridval]){   
            int u=x-1;
            int v=y;
            if(bcheck(u,v,grid.size(),grid[0].size()) && !vis[u][v]){
                vis[u][v]=true;
                int newgridval=grid[u][v];
                if(down[newgridval])
                dfs(u,v,grid,vis,up,down,left,right);
                
            }
        }
        if(down[gridval]){
            int u=x+1;
            int v=y;
            if(bcheck(u,v,grid.size(),grid[0].size()) && !vis[u][v]){
                vis[u][v]=true;
                int newgridval=grid[u][v];
                if(up[newgridval])
                dfs(u,v,grid,vis,up,down,left,right);
                
            }
                
            }

        
        if(left[gridval]){
            int u=x;
            int v=y-1;
            if(bcheck(u,v,grid.size(),grid[0].size()) && !vis[u][v]){
                int newgridval=grid[u][v];
                vis[u][v]=true;
                if(right[newgridval])
                dfs(u,v,grid,vis,up,down,left,right);
                
            }
            

        }
        if(right[gridval]){
            int u=x;
            int v=y+1;
            if(bcheck(u,v,grid.size(),grid[0].size()) && !vis[u][v]){
                int newgridval=grid[u][v];
                vis[u][v]=true;
                if(left[newgridval])
                dfs(u,v,grid,vis,up,down,left,right);
                
            }

        }


    }
    bool hasValidPath(vector<vector<int>>& grid) {
        unordered_map<int,bool> up;
        up[2]=true;
        up[5]=true;
        up[6]=true;
        unordered_map<int,bool> down;
        down[2]=true;
        down[3]=true;
        down[4]=true;

        unordered_map<int,bool> left;
        left[1]=true;
        left[3]=true;
        left[5]=true;
        unordered_map<int,bool> right;
        right[1]=true;
        right[4]=true;
        right[6]=true;
    vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
    dfs(0,0,grid,vis,up,down,left,right);
    return ans;
        
    }
};

class Solution {
public: 
    bool boundarycheck(int x,int y,int level,int rows, int cols){
        if(x>=level && y>=level && x<rows-level && y<cols-level) return true;
        return false;
        
    }
    bool up(int x, int y,int level,int rows,int cols){
        if(boundarycheck(x-1,y,level,rows,cols)) return true;
        return false;

    }
    bool down(int x,int y,int level,int rows,int cols){
        if(boundarycheck(x+1,y,level,rows,cols)) return true;
        return false;

    }
    bool right(int x, int y,int level,int rows,int cols){
        if(boundarycheck(x,y+1,level,rows,cols)) return true;
        return false;

    }
    bool left(int x, int y,int level,int rows,int cols){
        if(boundarycheck(x,y-1,level,rows,cols)) return true;
        return false;

    }
    
    void onelayer(int x,int y,int level,vector<vector<int>> &grid,int k){ 
        queue<int>q;
        int rows=grid.size();
        int cols=grid[0].size();
        int u=x+level;
        int v=y+level;
        int kay=k;
        q.push(grid[x+level][y+level]);
        kay--;
        while(down(u,v,level,rows,cols)){
            u++;
            if(kay>0){
                q.push(grid[u][v]);
                grid[u][v]=0;
                kay--;
            }
            else{
                q.push(grid[u][v]);
                grid[u][v]=q.front();
                q.pop();
            }
            

        }
        while(right(u,v,level,rows,cols)){
            v++;
            if(kay>0){
                q.push(grid[u][v]);
                grid[u][v]=0;
                kay--;
            }
            else{
                q.push(grid[u][v]);
                grid[u][v]=q.front();
                q.pop();
            }
            

        }
        while(up(u,v,level,rows,cols)){
            u--;
            if(kay>0){
                q.push(grid[u][v]);
                grid[u][v]=0;
                kay--;
            }
            else{
                q.push(grid[u][v]);
                grid[u][v]=q.front();
                q.pop();
            }
            

        }
        while(left(u,v,level,rows,cols)){
            v--;
            if(kay>0){
                q.push(grid[u][v]);
                grid[u][v]=0;
                kay--;
            }
            else{
                q.push(grid[u][v]);
                grid[u][v]=q.front();
                q.pop();
            }
            

        }  ///

        while(down(u,v,level,rows,cols) && !q.empty()){
            u++;
                grid[u][v]=q.front();
                q.pop();
            
            

        }
        while(right(u,v,level,rows,cols) && !q.empty()){
            v++;
                grid[u][v]=q.front();
                q.pop();
            
            

        }
        while(up(u,v,level,rows,cols) && !q.empty()){
            u--;
                grid[u][v]=q.front();
                q.pop();
            

        }
        while(left(u,v,level,rows,cols) && !q.empty()){
            v--;
                grid[u][v]=q.front();
                q.pop();

            

        }  

    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        for(int level=0 ; level<grid.size()/2 && level<grid[0].size()/2  ; level++){
        int rows=grid.size()-(2*level);
        int cols=grid[0].size() - (2*level);
        int perimeter=2*(rows+cols)-4;
        int kay=k% perimeter;

        onelayer(0,0,level,grid,kay);

        }
        return grid;
        
    }
};

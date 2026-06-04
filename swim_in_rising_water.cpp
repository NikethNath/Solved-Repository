class Solution {
public:

    class dsu{
        public:

        pair<int,int> start={0,0};
        vector<vector<pair<int,int>>> parent;
        vector<vector<int>> size;
        vector<vector<bool>> available;
        pair<int,int> end;
        

        dsu(vector<vector<int>> &grid){
            parent.resize(grid.size(),vector<pair<int,int>>(grid[0].size()));
            size.resize(grid.size(),vector<int>(grid[0].size(),1));
            available.resize(grid.size(),vector<bool>(grid[0].size(),false));

            for(int i=0 ; i<grid.size(); i++){
                for(int j=0 ; j<grid[0].size() ; j++){
                    parent[i][j]={i,j};
                }
            }
            end={grid.size()-1,grid.size()-1};

        }
        pair<int,int> findultparent(pair<int,int> &p){
            int x=p.first;
            int y=p.second;
            if(parent[x][y]==p) return {x,y};
            pair<int,int> par=parent[x][y];
            return parent[x][y]=findultparent(par);

        }

        void unionbysize(pair<int,int> &p1, pair<int,int> &p2){
            auto ult1=findultparent(p1);
            auto ult2=findultparent(p2);

            if(ult1==ult2) return;

            if(size[ult1.first][ult1.second]<=size[ult2.first][ult2.second]){
                size[ult2.first][ult2.second]+=size[ult1.first][ult1.second];
                parent[ult1.first][ult1.second]={ult2.first,ult2.second};
            }
            else{
                size[ult1.first][ult1.second]+=size[ult2.first][ult2.second];
                parent[ult2.first][ult2.second]={ult1.first,ult1.second};
            }

        }
        bool isconnected(pair<int,int> &p1, pair<int,int> &p2){
            auto ult1=findultparent(p1);
            auto ult2=findultparent(p2);

            if(ult1==ult2) return true;
            return false;

        }
    };


    int swimInWater(vector<vector<int>>& grid) {
        if(grid.size()==1) return grid[0][0];
        vector<pair<int,pair<int,int>>> sorted;
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid.size() ; j++){
                sorted.push_back({grid[i][j],{i,j}});
            }
        }
        sort(sorted.begin(),sorted.end());
        dsu ds(grid);
        for(auto a : sorted){
            int n=a.first;
            int x=a.second.first;
            int y=a.second.second;
            ds.available[x][y]=true;
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            for(int i=0 ; i<4 ; i++){
                int u=x+delrow[i];
                int v=y+delcol[i];
                if(u>=0 && v>=0 && u<grid.size() && v<grid[0].size() && ds.available[u][v]){
                    pair<int,int> nbr={u,v};
                    ds.unionbysize(a.second,nbr);
                    if(ds.isconnected(ds.start,ds.end)) return n;
                }
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];


        
    }
};

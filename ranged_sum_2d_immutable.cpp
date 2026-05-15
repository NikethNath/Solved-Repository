class NumMatrix {
public:
    vector<vector<int>> prefixmatrix;
    NumMatrix(vector<vector<int>>& matrix) {
        prefixmatrix.resize(matrix.size(),vector<int>(matrix[0].size()));
        prefixmatrix[0][0]=matrix[0][0];
        for(int i=1 ; i<matrix.size() ; i++){
            prefixmatrix[i][0]=matrix[i][0]+prefixmatrix[i-1][0];
        }
        for(int j=1 ; j<matrix[0].size() ; j++){
            prefixmatrix[0][j]=matrix[0][j]+prefixmatrix[0][j-1];
        }
        for(int i=1 ; i<matrix.size() ; i++){
            for(int j=1 ; j<matrix[0].size() ; j++){
                prefixmatrix[i][j]=prefixmatrix[i-1][j]+prefixmatrix[i][j-1]-prefixmatrix[i-1][j-1]+matrix[i][j];
            }
        }
        
    }
    int returnvals(int row,int col){
        if(row<0 || col<0) return 0;
        return prefixmatrix[row][col];

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return returnvals(row2,col2)-returnvals(row2,col1-1)-returnvals(row1-1,col2) + returnvals(row1-1,col1-1);
        
    }
};

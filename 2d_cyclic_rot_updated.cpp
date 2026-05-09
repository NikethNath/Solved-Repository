class Solution {
public:
    
    void rotateLayer(vector<vector<int>>& grid, int layer, int k) {
        
        int m = grid.size();
        int n = grid[0].size();

        int top = layer;
        int left = layer;
        int bottom = m - layer - 1;
        int right = n - layer - 1;

        vector<int> elems;

        // ---------------- EXTRACT ----------------

        // top row
        for (int j = left; j <= right; j++)
            elems.push_back(grid[top][j]);

        // right column
        for (int i = top + 1; i <= bottom - 1; i++)
            elems.push_back(grid[i][right]);

        // bottom row
        for (int j = right; j >= left; j--)
            elems.push_back(grid[bottom][j]);

        // left column
        for (int i = bottom - 1; i >= top + 1; i--)
            elems.push_back(grid[i][left]);



        // ---------------- ROTATE ----------------

        int len = elems.size();

        k %= len;

        vector<int> rotated(len);

        for (int i = 0; i < len; i++) {
            rotated[i] = elems[(i + k) % len];
        }



        // ---------------- PUT BACK ----------------

        int idx = 0;

        // top row
        for (int j = left; j <= right; j++)
            grid[top][j] = rotated[idx++];

        // right column
        for (int i = top + 1; i <= bottom - 1; i++)
            grid[i][right] = rotated[idx++];

        // bottom row
        for (int j = right; j >= left; j--)
            grid[bottom][j] = rotated[idx++];

        // left column
        for (int i = bottom - 1; i >= top + 1; i--)
            grid[i][left] = rotated[idx++];
    }

    
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int layers = min(grid.size(), grid[0].size()) / 2;

        for (int layer = 0; layer < layers; layer++) {
            rotateLayer(grid, layer, k);
        }

        return grid;
    }
};

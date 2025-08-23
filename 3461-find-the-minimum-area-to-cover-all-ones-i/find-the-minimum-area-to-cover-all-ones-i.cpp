class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxCol = -1;
        int minCol = n;

        int maxRow = -1;
        int minRow = m;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    maxCol = max(maxCol, j);
                    minCol = min(minCol, j);

                    maxRow = max(maxRow, i);
                    minRow = min(minRow, i);
                }
            }
        }

        return (maxCol - minCol + 1) * (maxRow - minRow + 1);
    }
};
class Solution {
public:
    int m, n;
    vector<vector<int>> dir = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int DFS(int x,  int y, int d, bool turn, int currTarget,  vector<vector<int>> &grid){
        int newX = x + dir[d][0];
        int newY = y + dir[d][1];

        if(newX >= m || newX < 0 || newY >= n || newY < 0 || grid[newX][newY] != currTarget){
            return 0;
        }

        int best = DFS(newX, newY, d, turn, 2 - currTarget, grid);

        if(turn){
            best = max(best, DFS(newX, newY, (d + 1) % 4, false, 2 - currTarget, grid));
        }

        return best + 1;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int result = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    for(int d = 0; d<4; d++){
                                            result = max(result, DFS(i, j, d, true, 2, grid) + 1);
                    }
                }
            }
        }

        return result;
    }
};
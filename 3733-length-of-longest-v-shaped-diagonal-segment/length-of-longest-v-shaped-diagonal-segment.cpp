class Solution {
public:
//Lets's Memoize this:
    int m, n;
    int t[501][501][4][2]; //x, y, direction, turn
    vector<vector<int>> dir = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int DFS(int x,  int y, int d, int turn, int currTarget,  vector<vector<int>> &grid){
        int newX = x + dir[d][0];
        int newY = y + dir[d][1];

        if(newX >= m || newX < 0 || newY >= n || newY < 0 || grid[newX][newY] != currTarget || turn > 1){
            return 0;
        }

        if(t[newX][newY][d][turn] != -1) return t[newX][newY][d][turn];

        int notTakeTurn = 1 + DFS(newX, newY, d, turn, 2 - currTarget, grid);
        int takeTurn = 1 + DFS(newX, newY, (d + 1) % 4, turn + 1, 2 - currTarget, grid);

        return t[newX][newY][d][turn] = max(notTakeTurn, takeTurn);
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int result = 0;

        // Intialize Table:
        memset(t, -1, sizeof(t));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    for(int d = 0; d<4; d++){
                        t[i][j][d][0] = 1;
                        t[i][j][d][1] = 1;
                        result = max(result, DFS(i, j, d, 0, 2, grid) + 1);
                    }
                }
            }
        }

        return result;
    }
};
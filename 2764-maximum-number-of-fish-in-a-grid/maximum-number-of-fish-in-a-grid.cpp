class Solution {
public:
    vector<vector<int>> directions;
    int m;
    int n;

    int dfs(int i, int j, vector<vector<int>>& grid){
        if(i < 0 || i>=m || j<0 || j>=n || grid[i][j]==0){
            return 0;
        }

        int fish = grid[i][j];

        grid[i][j] = 0; // mark the cell as visited

        for(auto &dir: directions){
            fish += dfs(dir[0] + i, dir[1] + j, grid);
        }

        return fish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        int maxFish = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] > 0){
                    maxFish = max(maxFish, dfs(i, j, grid));
                }
            }
        }

        return maxFish;
    }
};
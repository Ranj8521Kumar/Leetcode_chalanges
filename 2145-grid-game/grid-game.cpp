class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long top = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int j = 0; j<n; j++){
            top += grid[0][j];
        }

        long long buttom = 0; long long res = LLONG_MAX;
        for(int j = 0; j<n; j++){
            top -= grid[0][j];//first robot picks from the first row
            res = min(res, max(top, buttom));
            buttom += grid[1][j];//second robot picks from the buttom row
        }

        return res;
    }
};
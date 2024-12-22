class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {1,1}, {-1, 1}, {-1,0}, {-1, -1}, {0, -1},  {1, -1}};

        if(m <= 0 || n <= 0 || grid[0][0] == 1){
            return -1;
        }

        auto isSafe = [&](int i, int j){
            if(i<0 || j<0 || i>=m || j>=n){
                return false;
            }

            return true;
        };

        int lebel = 0;
        queue<pair<int, int>> que;
        que.push({0, 0});
        grid[0][0] = 1;

        while(!que.empty()){
            int len = que.size();

            while(len--){
                auto u = que.front();
                que.pop();
                int i = u.first;
                int j = u.second;
                
                if(i == m-1 && j == n-1){
                    return lebel + 1;
                }

                for(auto &dir: directions){
                    int i = u.first + dir[0];
                    int j = u.second + dir[1];

                    if(isSafe(i, j) && grid[i][j] != 1){
                        grid[i][j] = 1;
                        que.push({i, j});
                    }
                }
            }

            lebel++;
        }

        return -1;
    }
};
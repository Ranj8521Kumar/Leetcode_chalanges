class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] != 0 || grid[m-1][n-1] != 0) return -1;

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1},{-1, 1}, {-1, -1}};

        vector<vector<int>> result(m,  vector<int> (n, INT_MAX));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({1, {0, 0}});
        grid[0][0] = 1;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int weight = it.first;
            int x = it.second.first;
            int y = it.second.second;

            if(x == m-1 && y == n-1) return weight;

            for(auto &dir: directions){
                int newX = x + dir[0];
                int newY = y + dir[1];

                if(newX >= 0 && newX < m && newY >= 0 && newY < n){
                    if(grid[newX][newY] == 0){
                        if(weight + 1 < result[newX][newY]){
                            result[newX][newY] = (weight + 1);
                            grid[newX][newY] = 1;
                            pq.push({weight+1, {newX, newY}});
                        }
                    }
                }
            }
        }

        return -1;
    }
};
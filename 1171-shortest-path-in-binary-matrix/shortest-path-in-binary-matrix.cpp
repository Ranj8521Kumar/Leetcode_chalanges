class Solution {
public:
    typedef pair<int, int> p;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(m <= 0 || n <= 0 || grid[0][0] == 1){
            return -1;
        }

        vector<vector<int>> direction = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0,  -1}, {1, -1}};

        // Lambda function for isSafe
        auto isSafe = [&](int i,  int j){
            if(i < 0 || j < 0 || i >= m || j>= n){
                return false;
            }

            return true;
        };

        vector<vector<int>> result(m, vector<int> (n, INT_MAX));

        queue<p> pq;
        pq.push({0, 0});
        result[0][0] = 0;

        int dist = 1;

        while(!pq.empty()){
            auto u = pq.front();
            pq.pop();

            int i = u.first;
            int j = u.second;

            for(auto &dir: direction){
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                if(isSafe(new_i, new_j) && grid[new_i][new_j] == 0 && (result[i][j] + dist) < result[new_i][new_j]){
                    pq.push({new_i, new_j});
                    result[new_i][new_j] = result[i][j] + dist;
                }
            }
        }

        if(result[m-1][n-1] == INT_MAX){
            return -1;
        }

        return result[m-1][n-1] + 1;
    }
};
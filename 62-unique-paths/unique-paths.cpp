class Solution {
public:
    int t[101][101];

    int solve(int i, int j, int m, int n){
        if(i >= m || i < 0 || j >= n || j < 0){
            return 0;
        }

        if(t[i][j] != -1) return t[i][j];

        if(i == m-1 && j == n-1){
            return 1;
        }

        int right = solve(i, j + 1, m, n);
        int down = solve(i + 1, j, m, n);

        return t[i][j] = right + down;
    }

    int uniquePaths(int m, int n) {
        // This Approach is give TLE

        // vector<vector<int>> dirs = {{0, 1}, {1, 0}};
        // queue<pair<int, int>> que;
        // int result = 0;

        // que.push({0, 0});
        
        // while(!que.empty()){
        //     auto it = que.front(); que.pop();

        //     int x = it.first;
        //     int y = it.second;

        //     if(x == m-1 && y == n-1) result += 1;

        //     for(auto &dir: dirs){
        //         int newX = x + dir[0];
        //         int newY = y + dir[1];

        //         if(newX >= 0 && newX < m && newY >= 0 && newY < n){
        //             que.push({newX, newY});
        //         }
        //     }
        // }

        // return result;



        // Let's try another Approach;
        memset(t, -1, sizeof(t));
        
        return solve(0, 0, m, n);
    }
};
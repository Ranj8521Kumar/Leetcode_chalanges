class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> result(m, vector<int> (n, -1));
        queue<pair<int, int>> que;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(mat[i][j]  == 0){
                    result[i][j] = 0;
                    que.push({i,j});
                }
            }
        }

        vector<vector<int>> dir ={{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        while(!que.empty()){
            auto [r, c] = que.front();
            que.pop();

            for(auto &vec: dir){
                int nr = r + vec[0];
                int nc = c + vec[1];

                if(nr >= 0 && nr<m && nc>=0 && nc<n && result[nr][nc] == -1){
                    result[nr][nc] = result[r][c] + 1;
                    que.push({nr, nc});
                }
            }
        }

        return result;

    }
};
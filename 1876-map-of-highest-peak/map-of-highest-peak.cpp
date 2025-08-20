class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n  = isWater[0].size();

        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        vector<vector<int>> result(m, vector<int> (n, 0));

        queue<pair<int, int>> que;

        for(int i = 0; i<m; i++){
            for(int j  = 0; j<n; j++){
                if(isWater[i][j] == 1){
                    que.push({i, j});
                }
            }
        }

        while(!que.empty()){
            int len = que.size();

            while(len--){
                auto it = que.front();
                que.pop();

                int x = it.first;
                int y =  it.second;

                for(auto &dir: directions){
                    int newX = x + dir[0];
                    int newY = y + dir[1];

                    if(newX >= 0 && newX < m && newY >= 0 && newY < n){
                        if(result[newX][newY] == 0 && isWater[newX][newY] != 1){
                            result[newX][newY] = result[x][y] + 1;
                            que.push({newX, newY});
                        }
                    }
                    
                }
            }
        }

        return result;
    }
};
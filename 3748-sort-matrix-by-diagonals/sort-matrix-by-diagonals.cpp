class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        unordered_map<int, vector<int>> mpp;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                mpp[(i - j)].push_back(grid[i][j]);
            }
        }

        for(auto &it: mpp){
            auto &vec = it.second;
            if(it.first < 0){
                sort(vec.rbegin(), vec.rend());
            }else{
                sort(vec.begin(), vec.end());
            }
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                grid[i][j] = mpp[(i-j)].back();
                 mpp[(i-j)].pop_back();
            }
        }

        return grid;
    }
};
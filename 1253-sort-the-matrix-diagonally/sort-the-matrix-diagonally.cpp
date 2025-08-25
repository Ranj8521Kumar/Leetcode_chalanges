class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        // Let's Apply [i - j] Technique
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, vector<int>> mpp;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                mpp[(i-j)].push_back(mat[i][j]);
            }
        }

        for(auto &it: mpp){
             sort(it.second.rbegin(), it.second.rend());
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                mat[i][j] = mpp[i-j].back();
                mpp[i-j].pop_back();
            }
        }

        return mat;
    }
};
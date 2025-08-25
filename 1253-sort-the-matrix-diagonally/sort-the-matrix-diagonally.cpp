class Solution {
public:
    void fillMat(vector<vector<int>>& mat, int k, vector<int> &arr){
        int r = 0;
        for(int i = 0; i<mat.size(); i++){
            for(int j = 0; j<mat[0].size(); j++){
                if((i - j) == k){
                    mat[i][j] = arr[r];
                    r++;
                }
            }
        }
    }

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
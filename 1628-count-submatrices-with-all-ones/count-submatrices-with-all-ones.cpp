class Solution {
public:
    int m, n;
    int solve(int r1, int r2, vector<vector<int>>& mat){
        // vector<int> temp(n, 0);
        int prev = 0;
        int result = 0;
        
        for(int j = 0; j < n; j++){
            bool isZero = false;
            for(int i = r1; i <= r2; i++){
                if(mat[i][j] == 0){
                    isZero = true;
                    break;
                }
            }

            if(!isZero){
                // temp[j] = (j == 0) ? 1 : temp[j-1] + 1;
                prev = prev + 1;
                result += prev;
            }else{
                prev = 0;
            }
        }

        // int result = 0;
        // for(auto &it: temp){
        //     if(it != 0){
        //         result += it;
        //     }
        // }

        return result;
    }


    int numSubmat(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        int result = 0;

        for(int r1 = 0; r1 < m; r1++){
            for(int r2 = r1; r2 < m; r2++){
                result += solve(r1, r2, mat);
            }
        }

        return result;
    }
};
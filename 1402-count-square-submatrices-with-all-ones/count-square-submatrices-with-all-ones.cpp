class Solution {
public:
    int m, n;
    int solve(int r1, int r2, int d, vector<vector<int>>& matrix){
        vector<int> temp(n, 0);
        int currDist = 0;

        for(int j = 0; j<n; j++){
            bool isZero = false;
            for(int i = r1; i<=r2; i++){
                if(matrix[i][j] == 0){
                    isZero = true;
                    break;
                }
            }

            if(isZero){
                currDist = 0;
            }else{
                currDist++;
                if(currDist >= d){
                    temp[j] = 1;
                }
            }
        }

        int result = 0;
        for(auto &it: temp){
            if(it == 1){
                result += it;
            }
        }

        return result;
    }

    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int result = 0;

        for(int r1 = 0; r1<m; r1++){
            for(int r2 = r1; r2<m; r2++){
                result += solve(r1, r2, (r2 - r1 + 1), matrix);
            }
        }

        return result;
    }
};
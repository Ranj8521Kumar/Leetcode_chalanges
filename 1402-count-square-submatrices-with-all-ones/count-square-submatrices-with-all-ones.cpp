class Solution {
public:
    int m, n;
    int t[301][301];
    int isSafe(int x, int y){
        if(x >= 0 && x < m && y >= 0 && y < n){
            return true;
        }

        return false;
    }

    int solveRecurrsion(int x, int y, vector<vector<int>>& matrix){
        if(!isSafe(x, y) || matrix[x][y] == 0){
            return 0;
        }

        if(t[x][y] != -1) return t[x][y];

        int right = solveRecurrsion(x, y+1, matrix);
        int diagonal = solveRecurrsion(x+1, y+1, matrix);
        int buttom = solveRecurrsion(x+1, y, matrix);

        return t[x][y] = 1 + min(right, min(diagonal, buttom));
    }





    // int solve(int r1, int r2, int d, vector<vector<int>>& matrix){
    //     // r --> remove when commented code is uncomment
    //     // vector<int> temp(n, 0);
    //     int currDist = 0;
    //     int result = 0; //r

    //     for(int j = 0; j<n; j++){
    //         bool isZero = false;
    //         for(int i = r1; i<=r2; i++){
    //             if(matrix[i][j] == 0){
    //                 isZero = true;
    //                 break;
    //             }
    //         }

    //         if(isZero){
    //             currDist = 0;
    //         }else{
    //             currDist++;
    //             if(currDist >= d){
    //                 // temp[j] = 1;
    //                 result += 1;//r
    //             }
    //         }
    //     }

    //     // int result = 0;
    //     // for(auto &it: temp){
    //     //     if(it == 1){
    //     //         result += it;
    //     //     }
    //     // }

    //     return result;
    // }

    int countSquares(vector<vector<int>>& matrix) {
        // m = matrix.size();
        // n = matrix[0].size();
        // int result = 0;

        // for(int r1 = 0; r1<m; r1++){
        //     for(int r2 = r1; r2<m; r2++){
        //         result += solve(r1, r2, (r2 - r1 + 1), matrix);
        //     }
        // }

        // return result;






        // Let's Try out another approach that is Recurrsion + Memoization:
        m = matrix.size();
        n = matrix[0].size();
        int result = 0;

        memset(t, -1, sizeof(t));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                result += solveRecurrsion(i, j, matrix);
            }
        }

        return result;
    }
};
class Solution {
public:
    int m, n;
    int t[301][301];

    bool isSafe(int x, int y){
        if(x >= m || y >= n){
            return false;
        }

        return true;
    }

    int solve(int x, int y, vector<vector<char>>& matrix){
        if(!isSafe(x, y) || matrix[x][y] == '0'){
            return 0;
        }

        if(t[x][y] != -1) return t[x][y];

        int right = solve(x, y+1, matrix);
        int diagonal = solve(x+1, y+1, matrix);
        int down = solve(x+1, y, matrix);

        return t[x][y] = 1 + min({right, diagonal, down});
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        // Let's Apply Recursion Technique:
        // for checking the square, we can move right, down and diagonal from a element from upper-left
        // find length of sqaure from that element
        // find maximum length of square till now
        // return maximum length and calculate the area

        // Only recursion throw the TLE, so lets memoize it:

        // m = matrix.size();
        // n = matrix[0].size();
        // int maxLength = 0;

        // memset(t, -1, sizeof(t));

        // for(int i = 0; i<m; i++){
        //     for(int j = 0; j<n; j++){
        //         if(matrix[i][j] == '1'){
        //             maxLength = max(maxLength, solve(i, j, matrix));
        //         }
        //     }
        // }

        // return maxLength*maxLength;


        // Done, but let's try out using buttom-up approach:
        m = matrix.size();
        n = matrix[0].size();
        int maxLength = 0;

        vector<vector<int>> dp(m, vector<int> (n, 0));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = (matrix[i][j] == '1') ? 1 : 0;
                }else if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }

                maxLength = max(maxLength, dp[i][j]);
            }
        }

        return maxLength*maxLength;
    }
};
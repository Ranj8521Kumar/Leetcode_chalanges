class Solution {
public:
    int solve(int n, int dp[]){
        if(n <= 2){
            return n;
        }

        if(dp[n] != -1) return dp[n];

        int oneStep = solve(n-1, dp);
        int twoStep = solve(n-2, dp);

        return dp[n] = oneStep + twoStep;
    }

    int climbStairs(int n) {
        int dp[n+1];
        memset(dp, -1, sizeof(dp));

        return solve(n, dp);
    }
};
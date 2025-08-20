class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int p, vector<vector<int>>& pairs){
        if(i >= pairs.size()) return 0;

        if(dp[i][p+1] != -1) return dp[i][p+1];

        //take
        int take = 0;
        if(p == -1 || pairs[i][0] > pairs[p][1]){
            take = 1 + solve(i+1, i, pairs);
        }

        //skip
        int skip = solve(i+1, p, pairs);

        return dp[i][p+1] = max(take, skip);
    }


    int findLongestChain(vector<vector<int>>& pairs) {
        //This is also the funda of take and skip

        int n = pairs.size();
        dp.resize(n+1, vector<int> (n+1, -1));

        sort(pairs.begin(), pairs.end());

        return solve(0, -1, pairs);
    }
};
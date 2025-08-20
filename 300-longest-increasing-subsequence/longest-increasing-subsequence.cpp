class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int p, vector<int> &nums){
        if(i >= nums.size()) return 0;

        if(dp[i][p+1] != -1) return dp[i][p+1];

        //take
        int take = 0;
        if(p == -1 || nums[p] < nums[i]){
            take = 1 + solve(i+1, i, nums);
        }

        //skip
        int skip = solve(i+1, p, nums);

        return dp[i][p+1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        //it is the funda of take and skip
        int n = nums.size();

        dp.resize(n+1, vector<int> (n+1, -1));

        return solve(0, -1, nums);
    }
};
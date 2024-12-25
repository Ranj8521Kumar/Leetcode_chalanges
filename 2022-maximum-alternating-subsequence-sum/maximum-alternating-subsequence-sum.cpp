class Solution {
public:
    //recursion + memoization
    long long t[100001][2];
    long long solve(vector<int>& nums, int n, int i, bool isEven) {
        if (i >= n) {
            return 0;
        }

        if(t[i][isEven] != -1) return t[i][isEven];
        
        long long take = (isEven?nums[i]:-nums[i]) + solve(nums, n, i + 1, !isEven);
        long long notTake = solve(nums, n, i + 1, isEven);

        return t[i][isEven] = max(take, notTake);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        memset(t, -1, sizeof(t));

        return solve(nums, n, 0, true);
    }
};

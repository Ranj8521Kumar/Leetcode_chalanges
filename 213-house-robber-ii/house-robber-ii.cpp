class Solution {
public:
//recursion with memoization
    int t[101];

    int solve(int i, int n, vector<int>& nums){
        if(i > n) return 0;

        if(t[i] != -1) return t[i];

        int steal = nums[i] + solve(i+2, n, nums);
        int skip = solve(i+1, n, nums);

        return t[i] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];//special case, if only one house

        memset(t, -1, sizeof(t));
        int withZeroIindexedHouse = solve(0, n-2, nums);// can steal till n-2 indexed house
        memset(t,-1, sizeof(t));
        int withOutZeroIindexedHouse = solve(1, n-1, nums);// can steal till n-1 indexed house

        return max(withZeroIindexedHouse, withOutZeroIindexedHouse);
    }
};
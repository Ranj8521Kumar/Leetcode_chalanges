class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long count = 0;

        sort(nums.begin(), nums.end());

        for (int i = n - 1; i > 0; i--) {
            int i_lower = lower_bound(nums.begin(), nums.begin() + i, lower - nums[i]) - nums.begin();
            int i_upper = upper_bound(nums.begin(), nums.begin() + i, upper - nums[i]) - nums.begin();

            if (i_lower < i_upper) {
                count += (i_upper - i_lower);
            }
        }
        return count;
    }
};

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        if (nums.size() == 1)
            return 1;

        int maxBeauty = 0;
        int maxValue = 0;

        // Find the maximum value in the array
        for (int num : nums) {
            maxValue = max(maxValue, num);
        }

        // Create a frequency difference array
        vector<int> count(maxValue + 2, 0);

        for (int num : nums) {
            count[max(0, num - k)]++;
            count[min(maxValue + 1, num + k + 1)]--;
        }

        // Calculate the prefix sum to find the maximum beauty
        int currentSum = 0;
        for (int val : count) {
            currentSum += val;
            maxBeauty = max(maxBeauty, currentSum);
        }

        return maxBeauty;
    }
};
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        std::map<int, int> mpp;
        int left = 0, right = 0;
        long long count = 0; // Use long long to handle large values

        while (right < n) {
            mpp[nums[right]]++;

            // Shrink the window if max - min > 2
            while ((mpp.rbegin()->first - mpp.begin()->first) > 2) {
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0) {
                    mpp.erase(nums[left]);
                }
                left++;
            }

            // Add the number of subarrays ending at 'right'
            count += right - left + 1;
            right++;
        }

        return count;
    }
};

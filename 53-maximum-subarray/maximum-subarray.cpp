class Solution {
public:
    int n;
    int t[100001];
    int solve(int i, vector<int> &nums){
        if(i == 0) return t[i] = nums[i];

        if(t[i] != INT_MIN) return t[i];

        return t[i] = max(nums[i] + solve(i-1, nums), nums[i]); // Either start a new or add in previous existing
    }

    // int maxSubArray(vector<int>& nums) {
    //     n = nums.size();
    //     fill(t, t+n, INT_MIN);

    //     int ans = nums[0];
    //     for(int i = 0; i<n; i++){
    //         ans = max(ans, solve(i, nums));
    //     }

    //     return ans;
    // }





     int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;
        for(auto &it: nums){
            sum += it;

            maxSum = max(maxSum, sum);

            if(sum < 0) sum = 0;
        }

        return maxSum;
    }
};
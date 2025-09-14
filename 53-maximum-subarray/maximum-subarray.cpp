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
        int n = nums.size();
        
        int curr = nums[0];
        int best = nums[0];

        for(int i = 1; i<n; i++){
            curr = max(nums[i], curr + nums[i]); //restart or extend
            best = max(best, curr);
        }

        return best;
    }
};
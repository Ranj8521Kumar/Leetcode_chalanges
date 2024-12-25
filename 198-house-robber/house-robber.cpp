class Solution {
public:
// Buttom - Up Apprach
    int solve(vector<int>& nums, vector<int>& arr, int n){
        if(n==0) return 0;

        arr[0] = 0;
        arr[1] = nums[0];

        for(int i = 2; i<=n; i++){
            int steal = nums[i-1] + arr[i-2];
            int skip = arr[i-1];

            arr[i] = max(steal, skip);
        }

        return arr[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n+1);

        return solve(nums, arr, n);
    }
};
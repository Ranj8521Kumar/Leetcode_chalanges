class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = INT_MIN;
        int n = nums.size();

        if(n == 1){
            return nums[0];
        }

        int sum = nums[0];
        for(int i = 1; i<n; i++){
            if(nums[i] > nums[i-1]){
                sum += nums[i];
            }else{
                maxSum = max(maxSum, sum);
                sum = nums[i];
            }

            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};
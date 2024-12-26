class Solution {
public:
    int solve(vector<int>& nums, int target, int i, int sum){
        if(i>=nums.size()){
            if(sum == target){
                return 1;
            }else{
                return 0;
            }
        }

        //add
        int leftSum = solve(nums, target, i+1, sum + nums[i]);
        //substract
        int rightSum = solve(nums, target, i+1, sum - nums[i]);

        return leftSum + rightSum;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0, 0);
    }
};
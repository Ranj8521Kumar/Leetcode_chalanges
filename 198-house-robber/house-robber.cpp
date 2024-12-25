class Solution {
public:
//using buttom - up approach with constant space
    int solve(int n, vector<int>& nums){
        if(n == 1){
            return nums[0];
        }

        int prevPrev = 0;
        int prev = nums[0];

        int maxProfit;

        for(int i = 2; i<=n; i++){
            int steal = nums[i-1] + prevPrev;
            int skip = prev;

            maxProfit = max(steal, skip);

            prevPrev = prev;
            prev = maxProfit;;
        }

        return maxProfit;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        return solve(n, nums);
    }
};
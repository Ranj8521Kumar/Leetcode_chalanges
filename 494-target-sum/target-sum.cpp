class Solution {
public:
    //using recursion and memoization without use unordered_map
    int S; //total sum

    int solve(vector<int>& nums, int target, int i, int sum, vector<vector<int>>& t){
        if(i==nums.size()){
            if(sum == target){
                return 1;
            }else{
                return 0;
            }
        }

        if(t[i][sum + S] != INT_MIN) return t[i][sum + S];

        //add
        int leftSum = solve(nums, target, i+1, sum + nums[i], t);
        //substract
        int rightSum = solve(nums, target, i+1, sum - nums[i], t);

        return t[i][sum + S] = leftSum + rightSum;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n =  nums.size();
        S = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> t(n+1, vector<int>(2*S+1, INT_MIN));
        
        return solve(nums, target, 0, 0, t);
    }
};
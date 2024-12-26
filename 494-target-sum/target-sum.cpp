class Solution {
public:
    //using recursion and memoization
    unordered_map<string, int> mpp; //for memoization

    int solve(vector<int>& nums, int target, int i, int sum, bool isPlus){
        if(i>=nums.size()){
            if(sum == target){
                return 1;
            }else{
                return 0;
            }
        }

        string key = to_string(i)+','+to_string(sum);

        if(mpp.find(key) != mpp.end()){
            return mpp[key];
        }

        //add
        int leftSum = solve(nums, target, i+1, sum + nums[i], isPlus);
        //substract
        int rightSum = solve(nums, target, i+1, sum - nums[i], !isPlus);

        return mpp[key] = leftSum + rightSum;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0, 0, 1);
    }
};
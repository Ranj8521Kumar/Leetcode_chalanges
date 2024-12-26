class Solution {
public:
//using buttom - Approach
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        long long t[100001][2];

        //0 -> even
        //1 -> odd

        for(int i = 1; i<n+1; i++){
            t[i][0] = max((t[i-1][1] + nums[i-1]), t[i-1][0]);//for even length

            t[i][1] = max((t[i-1][0] - nums[i-1]), t[i-1][1]);//for odd length
        }

        return max(t[n][0], t[n][1]);
    }
};
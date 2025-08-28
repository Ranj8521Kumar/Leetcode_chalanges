class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int, int> mpp;
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];

            int rest = target - sum;
            if(mpp.find(rest) != mpp.end()){
                return {mpp[rest], i};
            }

            mpp[sum] =  i;
            sum = 0;
        }

        return {-1};
    }
};
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> vec(82);

        for(int i = 0; i<n; i++){
            int num = nums[i];
            int sum = 0;
            while(num != 0){
                int digit = num%10;
                sum += digit;
                num /= 10;
            }

            vec[sum].push_back(nums[i]);
        }

        int result = INT_MIN;

        for(auto &group: vec){
            int len = group.size();
            if(len > 1){
                sort(group.begin(), group.end());

                result = max(result, group[len - 1] + group[len - 2]);
            }
        }

        return (result == INT_MIN)? -1 : result;
    }
};
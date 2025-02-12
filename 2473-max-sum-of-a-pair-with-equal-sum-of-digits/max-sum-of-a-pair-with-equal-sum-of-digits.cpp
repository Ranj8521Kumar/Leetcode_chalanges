class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int result = -1;
        unordered_map<int, pair<int, int>> mpp;

        for(int i = 0; i<n; i++){
            int num = nums[i];
            int sum = 0;
            while(num != 0){
                int digit = num%10;
                sum += digit;
                num /= 10;
            }

            // auto &[max1, max2] = mpp[sum];
            auto &it = mpp[sum];
            int max1 = it.first;
            int max2 = it.second;

            if(nums[i] > max1){
                max2 = max1;
                max1 = nums[i];
            }else if(nums[i] > max2){
                max2 = nums[i];
            }

            it = {max1, max2}; //for updating the map entry

            if(max1 && max2){
                result = max(result, max1 + max2);
            }
        }

        return result;
    }
};
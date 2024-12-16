class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--){
            auto minElem = min_element(nums.begin(), nums.end());
            int idx = distance(nums.begin(), minElem);
            int  num = *minElem * multiplier;

            nums[idx] = num;
        }

        return nums;
    }
};
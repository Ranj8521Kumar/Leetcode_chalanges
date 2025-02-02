class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> sortedArray;
        int n = nums.size();

        int rotatedBy = 0;
        for(int i = 0; i<n-1; i++){
            if(rotatedBy != 0 && nums[i] > nums[i+1]){
                return false;
            }else if(nums[i] > nums[i+1]){
                rotatedBy = i+1;
            }
        }

        if(rotatedBy != 0 && nums[n-1] > nums[0]){
            return false;
        }

        return true;
    }
};
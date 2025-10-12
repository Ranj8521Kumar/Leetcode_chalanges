class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int majority = nums[0];

        for(int i = 0; i<n; i++){
            if(nums[i] == majority){
                count++;
            }else{
                count--;
                if(count == 0){
                    majority = nums[i];
                    count = 1;
                }
            }
        }

        return majority;
    }
};
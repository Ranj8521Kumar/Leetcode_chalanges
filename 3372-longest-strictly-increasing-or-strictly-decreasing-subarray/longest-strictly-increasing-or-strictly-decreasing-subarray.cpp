class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return 1;
        }

        int increasing = INT_MIN;
        int decreasing = INT_MIN;

        int inc = 1;
        int dec = 1;

        for(int i = 1; i<n; i++){
            if(nums[i] > nums[i-1]){
                inc++;

                if(dec != 1){
                    dec = 1;
                }

            }else if(nums[i] < nums[i-1]){
                dec++;

                if(inc != 1){
                    inc = 1;
                }
            }else{
                inc = 1;
                dec = 1;
            }

            increasing = max(increasing, inc);
            decreasing = max(decreasing, dec);
        }

        return max(increasing, decreasing);
    }
};
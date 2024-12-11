class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();

        int maxBeauty = 0;

        sort(begin(nums), end(nums));

        int j = 0;

        for(int i = 0; i<n; i++){
            int x = nums[i];
            int y = x+2*k;

            while(j<n && nums[j]<=y){
                j++;
            }

            maxBeauty = max(maxBeauty, j-i);
        }

        return maxBeauty;
    }
};
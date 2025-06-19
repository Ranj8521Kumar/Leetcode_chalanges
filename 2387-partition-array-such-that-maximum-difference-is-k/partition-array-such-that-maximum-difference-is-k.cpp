class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0;
        int cnt = 1;

        for(int j = 0; j<n; j++){
            if(nums[j] - nums[i] > k){
                i = j;
                cnt++;
            }
        }

        return cnt;
    }
};
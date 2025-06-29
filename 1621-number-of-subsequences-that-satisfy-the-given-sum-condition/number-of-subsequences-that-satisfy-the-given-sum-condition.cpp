class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;
        int mod = 1e9 + 7;

//because we have to find minimum and maximum for each subsequence, so don't care about order of elements in subsequences
        sort(nums.begin(), nums.end());

        vector<int> power(n, 0);
        power[0] = 1;

        for(int i = 1; i<n; i++){
            power[i] = (2 * power[i-1]) % mod;
        }

        int left = 0;
        int right = n-1;

        while(left <= right){
            if(nums[left] + nums[right] <= target){
                count = (count + power[right - left]) % mod;
                left++;
            }else{
                right--;
            }
        }

        return count;
    }
};
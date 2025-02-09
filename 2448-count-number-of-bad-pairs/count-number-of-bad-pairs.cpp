class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> mpp;
        long long goodPairs = 0;
        int n = nums.size();

        for(int i = 0; i<n; i++){
            int key = nums[i] - i;
            goodPairs += mpp[key];
            mpp[key]++;
        }

        return ((1LL*n*(n-1))/2) - goodPairs;
    }
};
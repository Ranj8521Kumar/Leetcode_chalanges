class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        // Let's Apply Sliding Window Technique:
        int n = arr.size();
        int result = 0;
        int zeroCount = 0;
        int last_zero_idx = -1;
        int i = 0;
        bool hasZero = false;
        for(int j = 0; j<n; j++){
            if(arr[j] == 0){
                hasZero = true;
                i = last_zero_idx + 1;
                last_zero_idx = j;
            }

            result = max(result, (j - i));
        }

        if(!hasZero) return n-1;

        return result;
    }
};